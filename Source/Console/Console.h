/*
 * Console.h
 *
 *  Created on: 2016年8月16日
 *      Author: seeing
 */

#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <iostream>
#include <stdarg.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../Time/Utils.h"

using namespace std;
namespace NS_NaviCommon
{
  class Console
  {
  public:
    Console():
      app_name("UNKNOWN"),
      show_debug(false),
      log_fifo_id(-1)
    {
    };

    Console(std::string name):
      app_name(name),
      show_debug(true),
      log_fifo_id(-1)
    {
    };

    ~Console()
    {
      if(log_fifo_id > 0)
        close(log_fifo_id);
    };
  private:
    std::string app_name;
    bool show_debug;
    int log_fifo_id;
  public:
    bool redirect()
    {
      std::string log_fifo_path = "/tmp/" + app_name + ".log";

      maskStdout();

      if(mkfifo(log_fifo_path.c_str(), S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0 && errno != EEXIST)
      {
        return false;
      }

      log_fifo_id = open(log_fifo_path.c_str(), O_WRONLY);
      if(log_fifo_id < 0)
      {
        return false;
      }

      return true;
    }

    void message(const char* message_, ...)
    {
      char out[1000] = {0};
      char msg[900] = {0};
      va_list args;
      va_start(args, message_);
      vsnprintf(msg, sizeof(msg), message_, args);
      va_end(args);
      strcat(out, "[");
      strcat(out, NS_NaviCommon::getTimeString().c_str());
      strcat(out, "][");
      strcat(out, app_name.c_str());
      strcat(out, "][M]:");
      strcat(out, msg);
      strcat(out, "\n");

      if(log_fifo_id > 0)
        write(log_fifo_id, out, strlen(out));
      else printf("%s", out);
    }
    ;

    void warning(const char* warning_, ...)
    {
      char out[1000] = {0};
      char msg[900] = {0};
      va_list args;
      va_start(args, warning_);
      vsnprintf(msg, sizeof(msg), warning_, args);
      va_end(args);
      strcat(out, "[");
      strcat(out, NS_NaviCommon::getTimeString().c_str());
      strcat(out, "][");
      strcat(out, app_name.c_str());
      strcat(out, "][W]:");
      strcat(out, msg);
      strcat(out, "\n");

      if(log_fifo_id > 0)
        write(log_fifo_id, out, strlen(out));
      else printf("%s", out);
    }
    ;

    void error(const char* error_, ...)
    {
      char out[1000] = {0};
      char msg[900] = {0};
      va_list args;
      va_start(args, error_);
      vsnprintf(msg, sizeof(msg), error_, args);
      va_end(args);
      strcat(out, "[");
      strcat(out, NS_NaviCommon::getTimeString().c_str());
      strcat(out, "][");
      strcat(out, app_name.c_str());
      strcat(out, "][E]:");
      strcat(out, msg);
      strcat(out, "\n");

      if(log_fifo_id > 0)
        write(log_fifo_id, out, strlen(out));
      else printf("%s", out);
    }
    ;

    void debug(const char* message_, ...)
    {
      char out[1000] = {0};
      char msg[900] = {0};
      va_list args;

      if(!show_debug)
        return;

      va_start(args, message_);
      vsnprintf(msg, sizeof(msg), message_, args);
      va_end(args);
      strcat(out, "[");
      strcat(out, NS_NaviCommon::getTimeString().c_str());
      strcat(out, "][");
      strcat(out, app_name.c_str());
      strcat(out, "][E]:");
      strcat(out, msg);
      strcat(out, "\n");

      if(log_fifo_id > 0)
        write(log_fifo_id, out, strlen(out));
      else printf("%s", out);
    }
    ;

    void showDebug(bool on)
    {
      show_debug = on;
    }
  private:
    void maskStdout()
    {
      fflush(stdout);
      int log_fd = open("/dev/null", O_RDWR);
      dup2(log_fd, STDOUT_FILENO);
    }
    ;

  };

}

#endif /* _CONSOLE_H_ */
