/*
 * Application.h
 *
 *  Created on: 2016年9月29日
 *      Author: seeing
 */

#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <stdio.h>
#include <signal.h>
#include <sched.h>
#include <sys/sysinfo.h>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include "../Time/Time.h"
#include "../Time/Rate.h"
#include "../Console/Console.h"
#include <boost/program_options.hpp>

class Application
{
public:
  Application()
  {
    std::string self_name = getSelfName();
    console = NS_NaviCommon::Console(self_name);
  }
  ;
  virtual ~Application()
  {
  }
  ;

protected:
  bool running;
  bool pending_;

  NS_NaviCommon::Console console;

  boost::thread pending_thread;

private:

  std::string getSelfName()
  {
    char full_path[1024] = {0};

    if(readlink("/proc/self/exe", full_path, sizeof(full_path)) <= 0)
        return "";

    std::string path_str(full_path);
    int last_slash_index = path_str.find_last_of('/');
    std::string exe_name = path_str.substr(last_slash_index + 1, -1);

    return exe_name;
  }

  void working()
  {
    NS_NaviCommon::Rate rate(10);
    while(pending_ && running)
    {
      rate.sleep();
    }
  }

public:

  void pending()
  {
    pending_ = true;
    pending_thread = boost::thread(boost::bind(&Application::working, this));
    pending_thread.join();
  }

  bool initialize(int argc, char* argv[])
  {
    NS_NaviCommon::Time::init();

    console.message("Application is initializing...");

    boost::program_options::options_description options("Application options");
    options.add_options()("help,h", "application help message")
        ("log,l", "dump logs to remote")
        ("verbose,v", "run debug output")
        ("core,c", boost::program_options::value< int >(), "if application run in smp mode, use this parameter to bind cpu core");

    boost::program_options::variables_map vm;
    boost::program_options::store(
        boost::program_options::parse_command_line(argc, argv, options), vm);
    boost::program_options::notify(vm);

    if(vm.count("help"))
    {
      std::cout << options << std::endl;
      return false;
    }

    if(vm.count("verbose"))
    {
      console.showDebug(true);
    }
    else
    {
      console.showDebug(false);
    }

    if(vm.count("log"))
    {
      console.redirect();
    }

    if(vm.count("core"))
    {
      int core_id = vm["core"].as< int >();
      int cpu_core_num = get_nprocs();

      if(core_id > (cpu_core_num - 1))
      {
        console.error("invalid core id!");
        return false;
      }

      console.message("CPU has %d core, let application runs on core %d.",
                      cpu_core_num, core_id);

      cpu_set_t mask;
      cpu_set_t get;

      CPU_ZERO(&mask);
      CPU_SET(core_id, &mask);

      if(sched_setaffinity(0, sizeof(mask), &mask) == -1)
      {
        console.warning("could not set CPU affinity, continuing");
      }

      CPU_ZERO(&get);
      if(sched_getaffinity(0, sizeof(get), &get) == -1)
      {
        console.warning("cound not get cpu affinity");
      }
      for(int i = 0; i < cpu_core_num; i++)
      {
        if(CPU_ISSET(i, &get))
        {
          console.debug("this process %d is running processor : %d", getpid(),
                        i);
          break;
        }
      }
    }

    return true;
  }

  virtual void run()
  {
  }
  ;
  virtual void quit()
  {
  }
  ;

  void terminate()
  {
    pending_ = false;
    pending_thread.join();
  }

  bool isRunning()
  {
    return running;
  }
  ;
};

#endif /* APPLICATION_APPLICATION_H_ */
