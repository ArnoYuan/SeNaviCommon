/*
 * Service.h
 *
 *  Created on: 2016年9月21日
 *      Author: seeing
 */

#ifndef _SERVICE_SERVICE_H_
#define _SERVICE_SERVICE_H_

#include <map>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/interprocess/sync/interprocess_condition.hpp>
#include "ServiceType/ServiceBase.h"

namespace NS_Service
{
  typedef enum
  {
    SERVICE_IDLE,
    SERVICE_PROCESSING,
  } ServiceStatus;

  typedef struct
  {
    boost::interprocess::interprocess_mutex lock;
    boost::interprocess::interprocess_condition req_cond;
    boost::interprocess::interprocess_condition rep_cond;
    ServiceStatus status;

    size_t buf_len;
  } ServiceOperation;

} /* namespace NS_NaviCommon */

#endif /* SERVICE_SERVICE_H_ */
