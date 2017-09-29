/*
 * Subscriber.h
 *
 *  Created on: Sep 6, 2017
 *      Author: root
 */

#ifndef _DATASET_SUBSCRIBER_H_
#define _DATASET_SUBSCRIBER_H_


#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include "DataSet.h"

namespace NS_DataSet
{

  using namespace boost::interprocess;

  template <typename DataType>
  class Subscriber
  {
    typedef boost::function<void (DataType&)> DataCallbackType;
  public:
    Subscriber (std::string name, DataCallbackType cb)
    {
      dataset_name = name;
      callback = cb;
      makeSrv ();
    }

    virtual ~Subscriber ()
    {
      shared_memory_object::remove (dataset_name.c_str ());
      if (active)
      {
        active = false;
        dataset_thread.join ();
      }
    }
  private:
    std::string dataset_name;
    DataCallbackType callback;
    DataSetOperation* operation;

    boost::mutex proc_lock;

    boost::thread dataset_thread;

    mapped_region oper_region;
    mapped_region ds_region;

    bool active;
  private:

    void makeSrv ()
    {
      shared_memory_object::remove (dataset_name.c_str ());

      try{
        shared_memory_object oper_shm (create_only, dataset_name.c_str (), read_write);

        oper_shm.truncate (sizeof (DataSetOperation));

        oper_region = mapped_region (oper_shm, read_write);

        void* region_addr = oper_region.get_address ();

        operation = new (region_addr) DataSetOperation;

      }catch (interprocess_exception&_exception)
      {
        printf ("create dataset fail!\n");
        return;
      }

      if (operation)
      {
        active = true;
        dataset_thread = boost::thread (boost::bind (&Subscriber::processor, this));
      }
      return;
    }

    void* getSrv ()
    {
      std::string ds_shm_name = dataset_name + "_DS";

      shared_memory_object ds_shm (open_only, ds_shm_name.c_str (), read_write);

      ds_region = mapped_region (ds_shm, read_write);

      void* region_addr = ds_region.get_address ();

      return region_addr;
    }

    void processor ()
    {
      while (active)
      {
        if (operation)
        {
          scoped_lock<interprocess_mutex> lock (operation->lock);

          while (operation->status == DATASET_IDLE)
          {
            operation->req_cond.timed_wait (lock, (boost::get_system_time () + boost::posix_time::seconds (1)));
          }

          if (callback)
          {
            unsigned char* addr = (unsigned char*)getSrv ();

            DataType ds;

            ds.deserialize (addr);

            callback (ds);

            operation->status = DATASET_IDLE;
            operation->rep_cond.notify_all ();
          }
        }
      }
    }

  };

}


#endif /* DATASET_SUBSCRIBER_H_ */
