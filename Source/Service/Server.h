/*
 * Server.h
 *
 *  Created on: Sep 1, 2017
 *      Author: root
 */

#ifndef _SERVICE_SERVER_H_
#define _SERVICE_SERVER_H_

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include "Service.h"
#include "../Console/Console.h"

namespace NS_Service
{

  using namespace boost::interprocess;

  template <typename SrvType>
  class Server
  {
    typedef boost::function<void (SrvType&)> ServiceEntryType;

  public:
    Server (std::string name, ServiceEntryType entry)
    {
      service_name = name;
      service_entry = entry;

      shared_memory_object::remove (service_name.c_str ());

      shared_memory_object oper_shm (create_only, service_name.c_str (), read_write);

      oper_shm.truncate (sizeof (ServiceOperation));

      oper_region = mapped_region (oper_shm, read_write);

      void* region_addr = oper_region.get_address ();

      operation = new (region_addr) ServiceOperation;

      if (operation)
      {
        active = true;
        service_thread = boost::thread (boost::bind (&Server::processor, this));
      }

    }

    virtual ~Server ()
    {
      shared_memory_object::remove (service_name.c_str ());
      if (active)
      {
        active = false;
        service_thread.join ();
      }
    }

  private:
    std::string service_name;

    ServiceEntryType service_entry;

    boost::mutex proc_lock;

    boost::thread service_thread;

    ServiceOperation* operation;

    mapped_region oper_region;
    mapped_region srv_region;

    bool active;

  private:

    void* getSrv ()
    {
      std::string srv_shm_name = service_name + "_SRV";

      shared_memory_object srv_shm (open_only, srv_shm_name.c_str (), read_write);

      srv_region = mapped_region (srv_shm, read_write);

      void* region_addr = srv_region.get_address ();

      return region_addr;
    }

    void resize (size_t size)
    {
      std::string srv_shm_name = service_name + "_SRV";

      shared_memory_object::remove (srv_shm_name.c_str ());

      shared_memory_object srv_shm (create_only, srv_shm_name.c_str (), read_write);

      srv_shm.truncate (size);

      operation->buf_len = size;
    }

    void processor ()
    {
      while (active)
      {
        if (operation)
        {
          scoped_lock<interprocess_mutex> lock (operation->lock);

          while (operation->status == SERVICE_IDLE)
          {
            operation->req_cond.timed_wait (lock, (boost::get_system_time () + boost::posix_time::seconds (1)));
          }

          if (service_entry)
          {
            unsigned char* addr;

            SrvType srv;

            service_entry (srv);

            resize (srv.serializationLength ());
            addr = (unsigned char*)getSrv ();

            srv.serialize (addr, operation->buf_len);

            operation->status = SERVICE_IDLE;
            operation->rep_cond.notify_all ();
          }
        }
      }
    }

  };
}


#endif /* SERVICE_SERVER_H_ */
