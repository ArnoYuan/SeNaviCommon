/*
 * Client.h
 *
 *  Created on: Sep 6, 2017
 *      Author: root
 */

#ifndef _DATASET_PUBLISHER_H_
#define _DATASET_PUBLISHER_H_

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include "DataSet.h"
#include "../Serialization/Serialization.h"

namespace NS_DataSet
{

  using namespace boost::interprocess;

  template <typename DataType>
  class Publisher
  {
  public:
    Publisher (std::string name)
    {
      dataset_name = name;
      operation = NULL;
      obtainOper ();
    }

    virtual ~Publisher ()
    {

    }

  private:
    std::string dataset_name;

    DataSetOperation* operation;

    mapped_region oper_region;
    mapped_region ds_region;

  private:

    void obtainOper ()
    {
      shared_memory_object oper_shm;

      try
      {
        oper_shm = shared_memory_object (open_only, dataset_name.c_str (), read_write);
      }catch (interprocess_exception& exception)
      {
        return;
      }

      offset_t oper_size = 0;
      if (oper_shm.get_size (oper_size) && oper_size == sizeof (DataSetOperation))
      {

        oper_region = mapped_region (oper_shm, read_write);

        void* region_addr = oper_region.get_address ();
        if (region_addr)
        {
          operation = static_cast<DataSetOperation*> (region_addr);
          operation->status = DATASET_IDLE;
        }
      }
    }

    void* getSrv ()
    {
      std::string ds_shm_name = dataset_name + "_DS";

      shared_memory_object ds_shm (open_only, ds_shm_name.c_str (), read_write);

      ds_region = mapped_region (ds_shm, read_write);

      void* region_addr = ds_region.get_address ();

      return region_addr;
    }

    void resize (size_t size)
    {
      std::string srv_shm_name = dataset_name + "_DS";

      shared_memory_object::remove (srv_shm_name.c_str ());

      shared_memory_object srv_shm (create_only, srv_shm_name.c_str (), read_write);

      srv_shm.truncate (size);

      operation->buf_len = size;
    }

  public:
    bool publish (DataType& ds)
    {
      if (!operation)
      {
        obtainOper ();
        if (!operation)
        {
          return false;
        }
      }

      scoped_lock<interprocess_mutex> lock (operation->lock);

      operation->buf_len = NS_NaviCommon::serializationLength (ds);

      resize (operation->buf_len);

      unsigned char* addr = (unsigned char*)getSrv ();

      NS_NaviCommon::OStream stream (addr, operation->buf_len);
      NS_NaviCommon::serialize (stream, ds);

      operation->status = DATASET_PROCESSING;
      operation->req_cond.notify_all ();

      int try_times = 10;
      bool timeout = false;
      while (operation->status == DATASET_PROCESSING)
      {
        operation->req_cond.timed_wait (lock, (boost::get_system_time () + boost::posix_time::microseconds (100)));
        if (try_times-- < 0)
        {
          timeout = true;
          break;
        }
      }

      if (timeout)
      {
        return false;
      }

      return true;
    }
  };

}



#endif /* DATASET_PUBLISHER_H_ */
