/*
 * Issuer.h
 *
 *  Created on: Jul 19, 2017
 *      Author: root
 */

#ifndef _MISSION_ISSUER_H_
#define _MISSION_ISSUER_H_

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>

namespace NS_Mission
{
  using namespace boost::interprocess;

  #define SHM_NAME "MISSION"

  class Issuer
  {
  public:
    Issuer()
    {
      obtainObject();
      active = true;
      proc_thread = boost::thread(boost::bind(&Issuer::process, this));
    }

    virtual ~Issuer()
    {
      if(active)
        proc_thread.join();
    }

  private:
    void obtainObject()
    {
      shared_memory_object obj_shm;

      try
      {
        obj_shm = shared_memory_object(open_only, SHM_NAME, read_write);
      }
      catch(interprocess_exception& exception)
      {
        return;
      }

      offset_t oper_size = 0;
      if(obj_shm.get_size(oper_size) && oper_size == sizeof(MissionObject))
      {

        object_region = mapped_region(obj_shm, read_write);

        void* region_addr = object_region.get_address();
        if(region_addr)
        {
          object = static_cast< MissionObject* >(region_addr);
          object->status = MISSION_STANDBY;
        }
      }
    }

    bool setGoal(double x, double y, double yaw)
    {
      if(!object)
      {
        obtainObject();
        if(!object)
        {
          return false;
        }
      }

      scoped_lock< interprocess_mutex > lock(object->lock);

      if(object->status != MISSION_STANDBY)
      {
        return false;
      }

      object->mission_id++;
      object->goal.x = x;
      object->goal.y = y;
      object->goal.yaw = yaw;
      object->operation = MISSION_SET_GOAL;

      object->issuer_cond.notify_all();

      while(object->status != MISSION_VALIDATING)
      {
        object->executor_cond.timed_wait(lock, (boost::get_system_time() + boost::posix_time::seconds(1)));
      }

      if(object->result == MISSION_REJECT)
      {
        return false;
      }

      return true;
    }

    void cancel()
    {
      if(object)
      {
        scoped_lock< interprocess_mutex > lock(object->lock);
        object->operation = MISSION_CANCEL;
        object->issuer_cond.notify_all();
      }
    }

    void process()
    {
      while(active)
      {
        if(object)
        {

          scoped_lock< interprocess_mutex > lock(object->lock);

          while(object->status != MISSION_ACTING)
          {
            object->executor_cond.timed_wait(lock, (boost::get_system_time() + boost::posix_time::seconds(1)));
          }

          if(object->result == MISSION_ABORT || object->result == MISSION_SUCCEED)
          {
            scoped_lock< boost::mutex > lock(action_mutex);
            trigger = true;
            action_cond.notify_all();
          }
        }
      }
    }

  private:
    boost::thread proc_thread;
    bool active;

    mapped_region object_region;
    MissionObject* object;

    mapped_region goal_region;

    boost::mutex action_mutex;
    boost::condition action_cond;

    bool trigger;

  public:
    bool action(double x, double y, double yaw, const int timeout = 30, MissionResult& last_result = MISSION_SUCCEED)
    {
      if(!setGoal(x, y, yaw))
      {
        last_result = MISSION_REJECT;
        return false;
      }

      action_mutex.lock();
      int times = 0;
      while(!trigger)
      {
        action_cond.timed_wait(action_mutex, (boost::get_system_time() + boost::posix_time::seconds(1)));
        times++;
        if(times > timeout)
        {
          break;
        }
      }
      action_mutex.unlock();

      if(times > timeout)
      {
        last_result = MISSION_TIMEOUT;
        return false;
      }

      if(object->result == MISSION_ABORT)
      {
        last_result = MISSION_ABORT;
        return false;
      }

      return true;
    }

  };

}

#endif /* MISSION_ISSUER_H_ */
