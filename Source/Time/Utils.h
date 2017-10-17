#ifndef _TIME_DELAY_H_
#define _TIME_DELAY_H_

#include <unistd.h>
#include <string>
#include <sstream>
#include <iostream>

namespace NS_NaviCommon
{

  static inline void delay(unsigned long ms)
  {
    while(ms >= 1000)
    {
      usleep(1000 * 1000);
      ms -= 1000;
    };
    if(ms != 0)
      usleep(ms * 1000);
  }

// TODO: the highest timer interface should be clock_gettime

  unsigned long
  getUs();
  unsigned int
  getMs();

  static inline time_t getTimeStamp()
  {
    time_t timestamp;
    time(&timestamp);
    return timestamp;
  }

  static inline std::string getTimeString()
  {
    std::stringstream time_str;

    time_t now = getTimeStamp();
    struct tm* t;

    t = localtime(&now);

    time_str << (t->tm_year + 1900);
    time_str << "-";
    time_str << (t->tm_mon + 1);
    time_str << "-";
    time_str << t->tm_mday;
    time_str << " ";
    time_str << t->tm_hour;
    time_str << ":";
    time_str << t->tm_min;
    time_str << ":";
    time_str << t->tm_sec;

    return time_str.str();
  }

}

#endif
