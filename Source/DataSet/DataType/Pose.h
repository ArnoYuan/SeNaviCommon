/*
 * Pose.h
 *
 *  Created on: 2016年9月23日
 *      Author: seeing
 */

#ifndef _DATATYPE_POSE_H_
#define _DATATYPE_POSE_H_

#include "DataBase.h"
#include "Point.h"
#include "Quaternion.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  template< class ContainerAllocator >
  //struct Pose_: public DataBase
  struct Pose_
  {
    typedef Pose_< ContainerAllocator > Type;
  public:
    Pose_()
        : position(), orientation()
    {
    }
    ;

    Pose_(const ContainerAllocator& allocator)
        : position(allocator), orientation(allocator)
    {
    }
    ;

    Point_< ContainerAllocator > position;
    Quaternion_< ContainerAllocator > orientation;

    typedef boost::shared_ptr< Pose_< ContainerAllocator > > Ptr;
    typedef boost::shared_ptr< Pose_< ContainerAllocator > const > ConstPtr;
    /*
     public:
     virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
     {
     NS_NaviCommon::OStream stream(write_ptr, 1000000000);
     NS_NaviCommon::serialize(stream, position);
     NS_NaviCommon::serialize(stream, orientation);
     return stream.getData();
     }

     virtual uint8_t *deserialize(uint8_t *read_ptr)
     {
     NS_NaviCommon::IStream stream(read_ptr, 1000000000);
     NS_NaviCommon::deserialize(stream, position);
     NS_NaviCommon::deserialize(stream, orientation);
     return stream.getData();
     }

     virtual uint32_t serializationLength() const
     {
     uint32_t size = 0;
     size += NS_NaviCommon::serializationLength(position);
     size += NS_NaviCommon::serializationLength(orientation);
     return size;
     }
     */
  };

  typedef Pose_< std::allocator< void > > Pose;

  typedef boost::shared_ptr< Pose > PosePtr;
  typedef boost::shared_ptr< Pose const > PoseConstPtr;

}

namespace NS_NaviCommon
{

// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/tmp/binarydeb/ros-kinetic-geometry-msgs-1.12.5/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']

  template< class ContainerAllocator >
  struct IsFixedSize< NS_DataType::Pose_< ContainerAllocator > > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsFixedSize< NS_DataType::Pose_< ContainerAllocator > const > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage< NS_DataType::Pose_< ContainerAllocator > > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage< NS_DataType::Pose_< ContainerAllocator > const > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader< NS_DataType::Pose_< ContainerAllocator > > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader< NS_DataType::Pose_< ContainerAllocator > const > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct MD5Sum< NS_DataType::Pose_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "e45d45a5a1ce597b249e23fb30fc871f";
    }

    static const char*
    value(const NS_DataType::Pose_< ContainerAllocator >&)
    {
      return value();
    }
    static const uint64_t static_value1 = 0xe45d45a5a1ce597bULL;
    static const uint64_t static_value2 = 0x249e23fb30fc871fULL;
  };

  template< class ContainerAllocator >
  struct DataType< NS_DataType::Pose_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "geometry_msgs/Pose";
    }

    static const char*
    value(const NS_DataType::Pose_< ContainerAllocator >&)
    {
      return value();
    }
  };

  template< class ContainerAllocator >
  struct Definition< NS_DataType::Pose_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "# A representation of pose in free space, composed of position and orientation. \n\
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
    value(const NS_DataType::Pose_< ContainerAllocator >&)
    {
      return value();
    }
  };

} // namespace message_traits

namespace NS_NaviCommon
{

  template< class ContainerAllocator >
  struct Serializer< NS_DataType::Pose_< ContainerAllocator > >
  {
    template< typename Stream, typename T >
    inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.position);
      stream.next(m.orientation);
    }

    DECLARE_ALLINONE_SERIALIZER}; // struct Pose_

}
// namespace serialization

#endif /* _POSE_H_ */
