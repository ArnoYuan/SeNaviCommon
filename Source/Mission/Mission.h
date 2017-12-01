/*
 * Mission.h
 *
 *  Created on: Jul 28, 2017
 *      Author: root
 */

#ifndef _MISSION_MISSION_H_
#define _MISSION_MISSION_H_

#include <map>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>

namespace NS_Mission
{
#define SHM_NAME "MISSION"

  typedef struct
  {
    double x;
    double y;
    double yaw;
  }MissionGoal;

  typedef enum
  {
    MISSION_STANDBY,
    MISSION_VALIDATING,
    MISSION_ACTING,
  }MissionStatus;

  typedef enum
  {
    MISSION_SET_GOAL,
    MISSION_CANCEL,
  }MissionOperation;

  typedef enum
  {
    MISSION_ACCEPT,
    MISSION_REJECT,
    MISSION_ABORT,
    MISSION_TIMEOUT,
    MISSION_SUCCEED,
  }MissionResult;

  typedef struct
  {
    MissionStatus status;
    MissionResult result;
    MissionOperation operation;

    boost::interprocess::interprocess_mutex lock;
    boost::interprocess::interprocess_condition issuer_cond;
    boost::interprocess::interprocess_condition executor_cond;

    int mission_id;
    MissionGoal goal;

  }MissionObject;
}

#endif /* MISSION_MISSION_H_ */
