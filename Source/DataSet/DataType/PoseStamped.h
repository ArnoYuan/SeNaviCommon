/*
 * PoseStamped.h
 *
 *  Created on: 2016年9月23日
 *      Author: seeing
 */

#ifndef _DATATYPE_POSESTAMPED_H_
#define _DATATYPE_POSESTAMPED_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "Pose.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{

  template< class ContainerAllocator >
  //struct PoseStamped_: public DataBase
  struct PoseStamped_
  {
    typedef PoseStamped_< ContainerAllocator > Type;
  public:
    PoseStamped_()
        : header(), pose()
    {
    }
    ;

    PoseStamped_(const ContainerAllocator& allocator)
        : header(allocator), pose(allocator)
    {
    }
    ;

    DataHeader_< ContainerAllocator > header;
    Pose_< ContainerAllocator > pose;

    typedef boost::shared_ptr< PoseStamped_< ContainerAllocator > > Ptr;
    typedef boost::shared_ptr< PoseStamped_< ContainerAllocator > const > ConstPtr;
    /*
     public:
     virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
     {
     NS_NaviCommon::OStream stream(write_ptr, 1000000000);
     NS_NaviCommon::serialize(stream, header);
     NS_NaviCommon::serialize(stream, pose);
     return stream.getData();
     }

     virtual uint8_t *deserialize(uint8_t *read_ptr)
     {
     NS_NaviCommon::IStream stream(read_ptr, 1000000000);
     NS_NaviCommon::deserialize(stream, header);
     NS_NaviCommon::deserialize(stream, pose);
     return stream.getData();
     }

     virtual uint32_t serializationLength() const
     {
     uint32_t size = 0;
     size += NS_NaviCommon::serializationLength(header);
     size += NS_NaviCommon::serializationLength(pose);
     return size;
     }
     */
  };

  typedef PoseStamped_< std::allocator< void > > PoseStamped;

  typedef boost::shared_ptr< PoseStamped > PoseStampedPtr;
  typedef boost::shared_ptr< PoseStamped const > PoseStampedConstPtr;

}

namespace NS_NaviCommon
{

// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/tmp/binarydeb/ros-kinetic-geometry-msgs-1.12.5/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']

  template< class ContainerAllocator >
  struct IsFixedSize< NS_DataType::PoseStamped_< ContainerAllocator > > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct IsFixedSize< NS_DataType::PoseStamped_< ContainerAllocator > const > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage< NS_DataType::PoseStamped_< ContainerAllocator > > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage< NS_DataType::PoseStamped_< ContainerAllocator > const > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader< NS_DataType::PoseStamped_< ContainerAllocator > > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader< NS_DataType::PoseStamped_< ContainerAllocator > const > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct MD5Sum< NS_DataType::PoseStamped_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "d3812c3cbc69362b77dc0b19b345f8f5";
    }

    static const char*
    value(const NS_DataType::PoseStamped_< ContainerAllocator >&)
    {
      return value();
    }
    static const uint64_t static_value1 = 0xd3812c3cbc69362bULL;
    static const uint64_t static_value2 = 0x77dc0b19b345f8f5ULL;
  };

  template< class ContainerAllocator >
  struct DataType< NS_DataType::PoseStamped_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "geometry_msgs/PoseStamped";
    }

    static const char*
    value(const NS_DataType::PoseStamped_< ContainerAllocator >&)
    {
      return value();
    }
  };

  template< class ContainerAllocator >
  struct Definition< NS_DataType::PoseStamped_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
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
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
    }

    static const char*
    value(const NS_DataType::PoseStamped_< ContainerAllocator >&)
    {
      return value();
    }
  };

} // namespace message_traits

namespace NS_NaviCommon
{

  template< class ContainerAllocator >
  struct Serializer< NS_DataType::PoseStamped_< ContainerAllocator > >
  {
    template< typename Stream, typename T >
    inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.pose);
    }

    DECLARE_ALLINONE_SERIALIZER}; // struct PoseStamped_

}
// namespace serialization

#endif /* _POSESTAMPED_H_ */
