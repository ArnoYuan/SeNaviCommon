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

namespace NS_Mission
{
  using namespace boost::interprocess;

  class Executor
  {
    typedef boost::function< void(MissionGoal&) > GoalCallbackType;
    typedef boost::function< void() > CancelCallbackType;

  public:
    Executor()
    {

    }

    virtual ~Executor()
    {

    }

  public:
    void registerGoalCallback(GoalCallbackType goal_cb)
    {
      onGoalSet = goal_cb;
    }

    void registerCancelCallback(CancelCallbackType cancel_cb)
    {
      onCancel = cancel_cb;
    }

  private:
    GoalCallbackType onGoalSet;
    CancelCallbackType onCancel;

    mapped_region object_region;
    MissionObject* object;

    boost::thread proc_thread;
    bool active;

  private:
    void process()
    {

    }

  };

}

#endif /* MISSION_EXECUTOR_H_ */
