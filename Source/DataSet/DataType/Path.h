/*
 * Path.h
 *
 *  Created on: 2016年12月12日
 *      Author: seeing
 */

#ifndef _DATATYPE_PATH_H_
#define _DATATYPE_PATH_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "PoseStamped.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    //struct Path_: public DataBase
    struct Path_
    {
      typedef Path_<ContainerAllocator> Type;
    public:
      Path_ ()
          : header (), poses ()
      {
      }
      ;

      Path_ (const ContainerAllocator& allocator)
          : header (allocator), poses (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;
      std::vector<PoseStamped_<ContainerAllocator>,
          typename ContainerAllocator::template rebind<
              PoseStamped_<ContainerAllocator> >::other> poses;

      typedef boost::shared_ptr<Path_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<Path_<ContainerAllocator> const> ConstPtr;
/*
    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, header);
        NS_NaviCommon::serialize(stream, poses);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, header);
        NS_NaviCommon::deserialize(stream, poses);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(header);
        size += NS_NaviCommon::serializationLength(poses);
        return size;
      }
      */
    };
  
  typedef Path_<std::allocator<void> > Path;
  
  typedef boost::shared_ptr<Path> PathPtr;
  typedef boost::shared_ptr<Path const> PathConstPtr;

}

namespace NS_NaviCommon
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'nav_msgs': ['/tmp/binarydeb/ros-kinetic-nav-msgs-1.12.5/msg', '/tmp/binarydeb/ros-kinetic-nav-msgs-1.12.5/obj-x86_64-linux-gnu/devel/share/nav_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< NS_DataType::Path_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< NS_DataType::Path_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< NS_DataType::Path_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< NS_DataType::Path_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< NS_DataType::Path_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< NS_DataType::Path_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< NS_DataType::Path_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6227e2b7e9cce15051f669a5e197bbf7";
  }

  static const char* value(const NS_DataType::Path_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6227e2b7e9cce150ULL;
  static const uint64_t static_value2 = 0x51f669a5e197bbf7ULL;
};

template<class ContainerAllocator>
struct DataType< NS_DataType::Path_<ContainerAllocator> >
{
  static const char* value()
  {
    return "nav_msgs/Path";
  }

  static const char* value(const NS_DataType::Path_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< NS_DataType::Path_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#An array of poses that represents a Path for a robot to follow\n\
Header header\n\
geometry_msgs/PoseStamped[] poses\n\
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
MSG: geometry_msgs/PoseStamped\n\
# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
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

  static const char* value(const NS_DataType::Path_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits

namespace NS_NaviCommon
{

  template<class ContainerAllocator> struct Serializer< NS_DataType::Path_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.poses);
    }

    DECLARE_ALLINONE_SERIALIZER
  }; // struct Path_

} // namespace serialization

#endif /* DATASET_DATATYPE_PATH_H_ */
