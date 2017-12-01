/*
 * Executor.h
 *
 *  Created on: Jul 19, 2017
 *      Author: root
 */

#ifndef _MISSION_EXECUTOR_H_
#define _MISSION_EXECUTOR_H_

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/function.hpp>
#include "Mission.h"

namespace NS_Mission
{
  using namespace boost::interprocess;

  class Executor
  {
    typedef boost::function< bool(MissionGoal&) > GoalCallbackType;
    typedef boost::function< void() > CancelCallbackType;

  public:
    Executor()
    {
      makeObject();
    }

    virtual ~Executor()
    {
      if(active)
      {
        active = false;
        proc_thread.join();
      }
    }

  public:
    void registerGoalCallback(GoalCallbackType goal_cb)
    {
      onGoalSetAndValid = goal_cb;
    }

    void registerCancelCallback(CancelCallbackType cancel_cb)
    {
      onCancel = cancel_cb;
    }

    void abort()
    {
      scoped_lock< interprocess_mutex > lock(object->lock);
      if(object)
      {
        if(object->status == MISSION_ACTING)
        {
          object->result = MISSION_ABORT;
          object->executor_cond.notify_all();
        }
      }
    }

    void done()
    {
      scoped_lock< interprocess_mutex > lock(object->lock);
      if(object)
      {
        if(object->status == MISSION_ACTING)
        {
          object->result = MISSION_SUCCEED;
          object->executor_cond.notify_all();
        }
      }
    }

  private:
    GoalCallbackType onGoalSetAndValid;
    CancelCallbackType onCancel;

    mapped_region object_region;
    MissionObject* object;

    boost::thread proc_thread;
    bool active;

  private:
    void makeObject()
    {
      //shared_memory_object::remove (dataset_name.c_str ());

      try
      {
        shared_memory_object oper_shm(open_or_create, SHM_NAME, read_write);

        oper_shm.truncate(sizeof(MissionObject));

        object_region = mapped_region(oper_shm, read_write);

        void* region_addr = object_region.get_address();

        object = new (region_addr) MissionObject;

      }
      catch(interprocess_exception&_exception)
      {
        printf("create object fail!\n");
        return;
      }

      active = true;
      proc_thread = boost::thread(boost::bind(&Executor::process, this));

      return;
    }

    void process()
    {
      while(active)
      {
        if(object)
        {
          scoped_lock< interprocess_mutex > lock(object->lock);

          bool timeout = false;

          while((object->status != MISSION_STANDBY) && (object->status != MISSION_ACTING))
          {
            timeout = object->issuer_cond.timed_wait(lock, (boost::get_system_time() + boost::posix_time::seconds(1)));
          }

          if(!timeout)
          {
            if(object->status == MISSION_STANDBY)
            {
              if(object->operation == MISSION_SET_GOAL)
              {
                if(onGoalSetAndValid)
                {
                  bool result = onGoalSetAndValid(object->goal);
                  if(result)
                  {
                    object->result = MISSION_ACCEPT;
                  }else{
                    object->result = MISSION_REJECT;
                  }
                  object->status = MISSION_VALIDATING;
                  object->executor_cond.notify_all();
                }
              }
            }else if(object->status == MISSION_ACTING)
            {
              if(object->operation == MISSION_CANCEL)
              {
                if(onCancel)
                {
                  onCancel();
                }
                object->result = MISSION_ABORT;
                object->executor_cond.notify_all();
              }
            }
          }
        }
      }
    }

  };

}

#endif /* MISSION_EXECUTOR_H_ */
