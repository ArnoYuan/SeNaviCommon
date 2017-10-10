/*
 * Odometry.h
 *
 *  Created on: 2016年10月14日
 *      Author: seeing
 */

#ifndef _DATATYPE_ODOMETRY_H_
#define _DATATYPE_ODOMETRY_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "Pose.h"
#include "Twist.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    //struct Odometry_: public DataBase
    struct Odometry_
    {
      typedef Odometry_<ContainerAllocator> Type;
    public:
      Odometry_ ()
          : header (), child_frame_id(), pose (), twist ()
      {
      }
      ;

      Odometry_ (const ContainerAllocator& allocator)
          : header (allocator), child_frame_id(allocator), pose (allocator), twist (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;

      typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _child_frame_id_type;
      _child_frame_id_type child_frame_id;

      Pose_<ContainerAllocator> pose;
      Twist_<ContainerAllocator> twist;

      typedef boost::shared_ptr<Odometry_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<Odometry_<ContainerAllocator> const> ConstPtr;
/*
    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, header);
        NS_NaviCommon::serialize(stream, pose);
        NS_NaviCommon::serialize(stream, twist);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, header);
        NS_NaviCommon::deserialize(stream, pose);
        NS_NaviCommon::deserialize(stream, twist);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(header);
        size += NS_NaviCommon::serializationLength(pose);
        size += NS_NaviCommon::serializationLength(twist);
        return size;
      }
      */
    };
  
  typedef Odometry_<std::allocator<void> > Odometry;
  
  typedef boost::shared_ptr<Odometry> OdometryPtr;
  typedef boost::shared_ptr<Odometry const> OdometryConstPtr;

}

namespace NS_NaviCommon
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'nav_msgs': ['/tmp/binarydeb/ros-kinetic-nav-msgs-1.12.5/msg', '/tmp/binarydeb/ros-kinetic-nav-msgs-1.12.5/obj-x86_64-linux-gnu/devel/share/nav_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< NS_DataType::Odometry_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< NS_DataType::Odometry_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< NS_DataType::Odometry_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< NS_DataType::Odometry_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< NS_DataType::Odometry_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< NS_DataType::Odometry_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< NS_DataType::Odometry_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cd5e73d190d741a2f92e81eda573aca7";
  }

  static const char* value(const NS_DataType::Odometry_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xcd5e73d190d741a2ULL;
  static const uint64_t static_value2 = 0xf92e81eda573aca7ULL;
};

template<class ContainerAllocator>
struct DataType< NS_DataType::Odometry_<ContainerAllocator> >
{
  static const char* value()
  {
    return "nav_msgs/Odometry";
  }

  static const char* value(const NS_DataType::Odometry_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< NS_DataType::Odometry_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# This represents an estimate of a position and velocity in free space.  \n\
# The pose in this message should be specified in the coordinate frame given by header.frame_id.\n\
# The twist in this message should be specified in the coordinate frame given by the child_frame_id\n\
Header header\n\
string child_frame_id\n\
geometry_msgs/PoseWithCovariance pose\n\
geometry_msgs/TwistWithCovariance twist\n\
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
MSG: geometry_msgs/PoseWithCovariance\n\
# This represents a pose in free space with uncertainty.\n\
\n\
Pose pose\n\
\n\
# Row-major representation of the 6x6 covariance matrix\n\
# The orientation parameters use a fixed-axis representation.\n\
# In order, the parameters are:\n\
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n\
float64[36] covariance\n\
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
\n\
================================================================================\n\
MSG: geometry_msgs/TwistWithCovariance\n\
# This expresses velocity in free space with uncertainty.\n\
\n\
Twist twist\n\
\n\
# Row-major representation of the 6x6 covariance matrix\n\
# The orientation parameters use a fixed-axis representation.\n\
# In order, the parameters are:\n\
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n\
float64[36] covariance\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Twist\n\
# This expresses velocity in free space broken into its linear and angular parts.\n\
Vector3  linear\n\
Vector3  angular\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
# It is only meant to represent a direction. Therefore, it does not\n\
# make sense to apply a translation to it (e.g., when applying a \n\
# generic rigid transformation to a Vector3, tf2 will only apply the\n\
# rotation). If you want your data to be translatable too, use the\n\
# geometry_msgs/Point message instead.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const NS_DataType::Odometry_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits


namespace NS_NaviCommon
{

  template<class ContainerAllocator> struct Serializer< NS_DataType::Odometry_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.child_frame_id);
      stream.next(m.pose);
      stream.next(m.twist);
    }

    DECLARE_ALLINONE_SERIALIZER
  }; // struct Odometry_

} // namespace serialization


#endif /* DATASET_DATATYPE_ODOMETRY_H_ */
