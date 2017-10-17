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

using namespace std;
namespace NS_NaviCommon
{
#define COLOR_NONE "\033[m"
#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_CYAN "\033[1;36m"

#define DEBUG_FLAG_FILE "/tmp/seeing-debug-flag"

  class Console
  {
  public:
    Console()
    {
    }
    ;
    ~Console()
    {
    }
    ;
  private:
    bool use_vt100 = true;
  public:
    void message(const char* message_, ...)
    {
      char out[1024] =
        {0};
      va_list args;
      va_start(args, message_);
      vsnprintf(out, sizeof(out), message_, args);
      va_end(args);
      if(use_vt100)
        printf(COLOR_GREEN);
      printf("[MSG]: ");
      printf(out);
      if(use_vt100)
        printf(COLOR_NONE);
      printf("\r\n");
      fflush(stdout);
    }
    ;

    void warning(const char* warning_, ...)
    {
      char out[1024] =
        {0};
      va_list args;
      va_start(args, warning_);
      vsnprintf(out, sizeof(out), warning_, args);
      va_end(args);
      if(use_vt100)
        printf(COLOR_YELLOW);
      printf("[WARN]: ");
      printf(out);
      if(use_vt100)
        printf(COLOR_NONE);
      printf("\r\n");
      fflush(stdout);
    }
    ;

    void error(const char* error_, ...)
    {
      char out[1024] =
        {0};
      va_list args;
      va_start(args, error_);
      vsnprintf(out, sizeof(out), error_, args);
      va_end(args);
      if(use_vt100)
        printf(COLOR_RED);
      printf("[ERR]: ");
      printf(out);
      if(use_vt100)
        printf(COLOR_NONE);
      printf("\r\n");
      fflush(stdout);
    }
    ;

    void debug(const char* message_, ...)
    {
      char out[1024] =
        {0};
      va_list args;
      if(access(DEBUG_FLAG_FILE, F_OK) == 0)
      {
        va_start(args, message_);
        vsnprintf(out, sizeof(out), message_, args);
        va_end(args);
        if(use_vt100)
          printf(COLOR_CYAN);
        printf("[DBG]: ");
        printf(out);
        if(use_vt100)
          printf(COLOR_NONE);
        printf("\r\n");
        fflush(stdout);
      }
    }
    ;

    void debugOn()
    {
      char cmd[1024] =
        {0};
      strcat(cmd, "touch ");
      strcat(cmd, DEBUG_FLAG_FILE);
      system(cmd);
    }
    ;

    void debugOff()
    {
      char cmd[1024] =
        {0};
      strcat(cmd, "rm -f ");
      strcat(cmd, DEBUG_FLAG_FILE);
      system(cmd);
    }
    ;

    void dump(unsigned char* ptr_, size_t len_)
    {
      if(use_vt100)
        printf(COLOR_YELLOW);
      printf("[ ");
      for(size_t i = 0; i < len_; i++)
      {
        printf("%02X ", *(ptr_ + i));
      }
      printf(" ]");

      if(use_vt100)
        printf(COLOR_NONE);

      printf("\r\n");
      fflush(stdout);
    }

    void redirect(std::string log_file)
    {
      fflush(stdout);
      mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
      int log_fd = open(log_file.c_str(), O_CREAT | O_RDWR | O_TRUNC, mode);
      dup2(log_fd, STDOUT_FILENO);
    }
    ;

    void setVT100(bool use)
    {
      fflush(stdout);
      use_vt100 = use;
    }
    ;

  };

}

#endif /* _CONSOLE_H_ */
