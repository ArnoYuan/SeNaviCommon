/*
 * Client.h
 *
 *  Created on: Sep 4, 2017
 *      Author: root
 */

#ifndef _SERVICE_CLIENT_H_
#define _SERVICE_CLIENT_H_

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include "Service.h"
#include "../Console/Console.h"

namespace NS_Service
{
  
  using namespace boost::interprocess;
  
  template<typename SrvType>
    class Client
    {
    public:
      Client (std::string name)
      {
        service_name = name;
        operation = NULL;
        obtainOper ();
      }
      
      virtual
      ~Client ()
      {
        
      }
    private:
      std::string service_name;

      ServiceOperation* operation;

      mapped_region oper_region;
      mapped_region srv_region;

      void
      obtainOper ()
      {
        shared_memory_object oper_shm;
        
        try
        {
          oper_shm = shared_memory_object (open_only, service_name.c_str (),
                                           read_write);
        }
        catch (interprocess_exception& exception)
        {
          return;
        }
        
        offset_t oper_size = 0;
        if (oper_shm.get_size (oper_size)
            && oper_size == sizeof(ServiceOperation))
        {
          oper_region = mapped_region (oper_shm, read_write);
          
          void* region_addr = oper_region.get_address ();
          if (region_addr)
          {
            operation = static_cast<ServiceOperation*> (region_addr);
          }
        }
      }
      
    public:
      bool
      call (SrvType& srv)
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
        
        operation->status = SERVICE_PROCESSING;
        operation->req_cond.notify_all ();
        
        int try_times = 10;
        bool timeout = false;
        while (operation->status == SERVICE_PROCESSING)
        {
          operation->req_cond.timed_wait (
              lock,
              (boost::get_system_time () + boost::posix_time::microseconds (100)));
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
        
        std::string srv_shm_name = service_name + "_SRV";
        
        shared_memory_object srv_shm (open_only, srv_shm_name.c_str (),
                                      read_write);
        
        srv_region = mapped_region (srv_shm, read_write);
        
        void* region_addr = srv_region.get_address ();
        
        NS_NaviCommon::IStream stream ((unsigned char*) region_addr,
                                       operation->buf_len);
        
        NS_NaviCommon::deserialize (stream, srv);
        
        return true;
      }
    };

}

#endif /* SERVICE_CLIENT_H_ */
