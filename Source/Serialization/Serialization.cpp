
#include "Serialization.h"


namespace NS_NaviCommon
{
  void throwStreamOverrun()
  {
    throw StreamOverrunException("Buffer Overrun");
  }
}

