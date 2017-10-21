/*
 * ChannelFloat32.h
 *
 *  Created on: 2016年9月28日
 *      Author: seeing
 */

#ifndef _DATATYPE_CHANNELFLOAT32_H_
#define _DATATYPE_CHANNELFLOAT32_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{

  template< class ContainerAllocator >
  //struct ChannelFloat32_: public DataBase
  struct ChannelFloat32_
  {
    typedef ChannelFloat32_< ContainerAllocator > Type;
  public:
    ChannelFloat32_()
        : name(), values()
    {
    }
    ;

    ChannelFloat32_(const ContainerAllocator& allocator)
        : name(allocator), values(allocator)
    {
    }
    ;

    std::basic_string< char, std::char_traits< char >,
        typename ContainerAllocator::template rebind< char >::other > name;
    std::basic_string< char, std::char_traits< char >,
        typename ContainerAllocator::template rebind< char >::other > values;

    typedef boost::shared_ptr< ChannelFloat32_< ContainerAllocator > > Ptr;
    typedef boost::shared_ptr< ChannelFloat32_< ContainerAllocator > const > ConstPtr;
    /*
     public:
     virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
     {
     NS_NaviCommon::OStream stream(write_ptr, 1000000000);
     NS_NaviCommon::serialize(stream, name);
     NS_NaviCommon::serialize(stream, values);
     return stream.getData();
     }

     virtual uint8_t *deserialize(uint8_t *read_ptr)
     {
     NS_NaviCommon::IStream stream(read_ptr, 1000000000);
     NS_NaviCommon::deserialize(stream, name);
     NS_NaviCommon::deserialize(stream, values);
     return stream.getData();
     }

     virtual uint32_t serializationLength() const
     {
     uint32_t size = 0;
     size += NS_NaviCommon::serializationLength(name);
     size += NS_NaviCommon::serializationLength(values);
     return size;
     }

     */
  };

  typedef ChannelFloat32_< std::allocator< void > > ChannelFloat32;

  typedef boost::shared_ptr< ChannelFloat32 > ChannelFloat32Ptr;
  typedef boost::shared_ptr< ChannelFloat32 const > ChannelFloat32ConstPtr;

}

namespace NS_NaviCommon
{

// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'sensor_msgs': ['/tmp/binarydeb/ros-kinetic-sensor-msgs-1.12.5/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']

  template< class ContainerAllocator >
  struct IsFixedSize< NS_DataType::ChannelFloat32_< ContainerAllocator > > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct IsFixedSize< NS_DataType::ChannelFloat32_< ContainerAllocator > const > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage< NS_DataType::ChannelFloat32_< ContainerAllocator > > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage< NS_DataType::ChannelFloat32_< ContainerAllocator > const > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader< NS_DataType::ChannelFloat32_< ContainerAllocator > > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader< NS_DataType::ChannelFloat32_< ContainerAllocator > const > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct MD5Sum< NS_DataType::ChannelFloat32_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "3d40139cdd33dfedcb71ffeeeb42ae7f";
    }

    static const char*
    value(const NS_DataType::ChannelFloat32_< ContainerAllocator >&)
    {
      return value();
    }
    static const uint64_t static_value1 = 0x3d40139cdd33dfedULL;
    static const uint64_t static_value2 = 0xcb71ffeeeb42ae7fULL;
  };

  template< class ContainerAllocator >
  struct DataType< NS_DataType::ChannelFloat32_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "sensor_msgs/ChannelFloat32";
    }

    static const char*
    value(const NS_DataType::ChannelFloat32_< ContainerAllocator >&)
    {
      return value();
    }
  };

  template< class ContainerAllocator >
  struct Definition< NS_DataType::ChannelFloat32_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "# This message is used by the PointCloud message to hold optional data\n\
# associated with each point in the cloud. The length of the values\n\
# array should be the same as the length of the points array in the\n\
# PointCloud, and each value should be associated with the corresponding\n\
# point.\n\
\n\
# Channel names in existing practice include:\n\
#   \"u\", \"v\" - row and column (respectively) in the left stereo image.\n\
#              This is opposite to usual conventions but remains for\n\
#              historical reasons. The newer PointCloud2 message has no\n\
#              such problem.\n\
#   \"rgb\" - For point clouds produced by color stereo cameras. uint8\n\
#           (R,G,B) values packed into the least significant 24 bits,\n\
#           in order.\n\
#   \"intensity\" - laser or pixel intensity.\n\
#   \"distance\"\n\
\n\
# The channel name should give semantics of the channel (e.g.\n\
# \"intensity\" instead of \"value\").\n\
string name\n\
\n\
# The values array should be 1-1 with the elements of the associated\n\
# PointCloud.\n\
float32[] values\n\
";
    }

    static const char*
    value(const NS_DataType::ChannelFloat32_< ContainerAllocator >&)
    {
      return value();
    }
  };

} // namespace message_traits

namespace NS_NaviCommon
{

  template< class ContainerAllocator >
  struct Serializer< NS_DataType::ChannelFloat32_< ContainerAllocator > >
  {
    template< typename Stream, typename T >
    inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.values);
    }

    DECLARE_ALLINONE_SERIALIZER
  }; // struct ChannelFloat32_

}
// namespace serialization

#endif /* DATASET_DATATYPE_CHANNELFLOAT32_H_ */
