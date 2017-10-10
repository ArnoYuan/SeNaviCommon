#ifndef _DATATYPE_DATAHEADER_H_
#define _DATATYPE_DATAHEADER_H_

#include <string>
#include <vector>
#include "../../Time/Time.h"
#include "DataBase.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  template<class ContainerAllocator>
    //struct DataHeader_: public DataBase
    struct DataHeader_
    {
      typedef DataHeader_<ContainerAllocator> Type;
    public:
      DataHeader_ ()
          : seq (0), stamp (), frame_id ()
      {
      }
      ;

      DataHeader_ (const ContainerAllocator& allocator)
          : seq (0), stamp (allocator), frame_id (allocator)
      {
      }
      ;

      unsigned long seq;
      NS_NaviCommon::Time stamp;

      std::basic_string<char, std::char_traits<char>,
          typename ContainerAllocator::template rebind<char>::other> frame_id;

      typedef boost::shared_ptr<DataHeader_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<DataHeader_<ContainerAllocator> const> ConstPtr;
/*
    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, this->seq);
        NS_NaviCommon::serialize(stream, stamp);
        NS_NaviCommon::serialize(stream, frame_id);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, seq);
        NS_NaviCommon::deserialize(stream, stamp);
        NS_NaviCommon::deserialize(stream, frame_id);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(seq);
        size += NS_NaviCommon::serializationLength(stamp);
        size += NS_NaviCommon::serializationLength(frame_id);
        return size;
      }
      */
    };
  
  typedef DataHeader_<std::allocator<void> > DataHeader;
  
  typedef boost::shared_ptr<DataHeader> DataHeaderPtr;
  typedef boost::shared_ptr<DataHeader const> DataHeaderConstPtr;

} /* namespace NS_NaviCommon */


namespace NS_NaviCommon
{

// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/tmp/binarydeb/ros-kinetic-std-msgs-0.5.11/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']

template <class ContainerAllocator>
struct IsFixedSize<NS_DataType::DataHeader_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< NS_DataType::DataHeader_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< NS_DataType::DataHeader_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< NS_DataType::DataHeader_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< NS_DataType::DataHeader_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< NS_DataType::DataHeader_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< NS_DataType::DataHeader_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2176decaecbce78abc3b96ef049fabed";
  }

  static const char* value(const NS_DataType::DataHeader_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2176decaecbce78aULL;
  static const uint64_t static_value2 = 0xbc3b96ef049fabedULL;
};

template<class ContainerAllocator>
struct DataType< NS_DataType::DataHeader_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header";
  }

  static const char* value(const NS_DataType::DataHeader_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< NS_DataType::DataHeader_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const NS_DataType::DataHeader_<ContainerAllocator>&) { return value(); }
};

}

namespace NS_NaviCommon
{

  template<class ContainerAllocator> struct Serializer<NS_DataType::DataHeader_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.seq);
      stream.next(m.stamp);
      stream.next(m.frame_id);
    }

    DECLARE_ALLINONE_SERIALIZER
  }; // struct Header_

}

#endif /* _DATAHEADER_H_ */
