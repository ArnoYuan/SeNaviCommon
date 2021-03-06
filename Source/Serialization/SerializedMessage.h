#ifndef _SERIALIZED_MESSAGE_H_
#define _SERIALIZED_MESSAGE_H_

#include <boost/shared_array.hpp>
#include <boost/shared_ptr.hpp>

namespace NS_NaviCommon
{

  class SerializedMessage
  {
  public:
    boost::shared_array< uint8_t > buf;
    size_t num_bytes;
    uint8_t* message_start;

    boost::shared_ptr< void const > message;
    const std::type_info* type_info;

    SerializedMessage()
        : buf(boost::shared_array< uint8_t >()), num_bytes(0), message_start(0),
          type_info(0)
    {
    }

    SerializedMessage(boost::shared_array< uint8_t > buf, size_t num_bytes)
        : buf(buf), num_bytes(num_bytes), message_start(buf ? buf.get() : 0),
          type_info(0)
    {
    }
  };

} // namespace ros

#endif // ROSLIB_SERIALIZED_MESSAGE_H
