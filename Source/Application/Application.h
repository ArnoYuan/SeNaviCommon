/*
 * Application.h
 *
 *  Created on: 2016年9月29日
 *      Author: seeing
 */

#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "stdio.h"
#include "signal.h"
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include "../Time/Time.h"
#include "../Time/Rate.h"
#include "../Console/Console.h"

class Application;

static Application* instance;

class Application
{
public:
  Application ()
  {
    instance = this;
  };
  virtual
  ~Application () {};

protected:
  bool running;
  bool initialized;

  NS_NaviCommon::Console console;

  boost::thread pending_thread;

private:
  static void
  signalAction (int signal)
  {
    instance->console.warning ("received a signal, id:%d!", signal);
    instance->quit ();
    instance->running = false;
    instance->pending_thread.join ();
  }

  void
  working ()
  {
    NS_NaviCommon::Rate rate (10);
    while (running)
    {
      rate.sleep ();
    }
  }

public:
  void
  registerSignal ()
  {
    signal (SIGINT, signalAction);
  }

  void
  pending ()
  {
    pending_thread.join ();
  }

  void
  initialize ()
  {
    NS_NaviCommon::Time::init ();

    running = true;
    pending_thread = boost::thread (boost::bind (&Application::working, this));
  }

  virtual void
  run () {};
  virtual void
  quit () {};

  bool
  isRunning ()
  {
    return running;
  }
  ;

  bool
  isInitialized ()
  {
    return initialized;
  }
  ;
};

#endif /* APPLICATION_APPLICATION_H_ */
