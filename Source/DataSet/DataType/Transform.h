/*
 * Transform.h
 *
 *  Created on: 2016年9月23日
 *      Author: seeing
 */

#ifndef _DATATYPE_TRANSFORM_H_
#define _DATATYPE_TRANSFORM_H_

#include "Quaternion.h"
#include "Vector3.h"
#include "DataBase.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{

  template< class ContainerAllocator >
  //struct Transform_: public DataBase
  struct Transform_
  {
    typedef Transform_< ContainerAllocator > Type;
  public:
    Transform_()
        : translation(), rotation()
    {
    }
    ;

    Transform_(const ContainerAllocator& allocator)
        : translation(allocator), rotation(allocator)
    {
    }
    ;

    Vector3_< ContainerAllocator > translation;
    Quaternion_< ContainerAllocator > rotation;

    typedef boost::shared_ptr< Transform_< ContainerAllocator > > Ptr;
    typedef boost::shared_ptr< Transform_< ContainerAllocator > const > ConstPtr;
    /*
     public:
     virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
     {
     NS_NaviCommon::OStream stream(write_ptr, 1000000000);
     NS_NaviCommon::serialize(stream, translation);
     NS_NaviCommon::serialize(stream, rotation);
     return stream.getData();
     }

     virtual uint8_t *deserialize(uint8_t *read_ptr)
     {
     NS_NaviCommon::IStream stream(read_ptr, 1000000000);
     NS_NaviCommon::deserialize(stream, translation);
     NS_NaviCommon::deserialize(stream, rotation);
     return stream.getData();
     }

     virtual uint32_t serializationLength() const
     {
     uint32_t size = 0;
     size += NS_NaviCommon::serializationLength(translation);
     size += NS_NaviCommon::serializationLength(rotation);
     return size;
     }
     */
  };

  typedef Transform_< std::allocator< void > > Transform;

  typedef boost::shared_ptr< Transform > TransformPtr;
  typedef boost::shared_ptr< Transform const > TransformConstPtr;

}

namespace NS_NaviCommon
{

// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/tmp/binarydeb/ros-kinetic-geometry-msgs-1.12.5/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']

  template< class ContainerAllocator >
  struct IsFixedSize< NS_DataType::Transform_< ContainerAllocator > > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsFixedSize< NS_DataType::Transform_< ContainerAllocator > const > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage< NS_DataType::Transform_< ContainerAllocator > > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage< NS_DataType::Transform_< ContainerAllocator > const > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader< NS_DataType::Transform_< ContainerAllocator > > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader< NS_DataType::Transform_< ContainerAllocator > const > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct MD5Sum< NS_DataType::Transform_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "ac9eff44abf714214112b05d54a3cf9b";
    }

    static const char*
    value(const NS_DataType::Transform_< ContainerAllocator >&)
    {
      return value();
    }
    static const uint64_t static_value1 = 0xac9eff44abf71421ULL;
    static const uint64_t static_value2 = 0x4112b05d54a3cf9bULL;
  };

  template< class ContainerAllocator >
  struct DataType< NS_DataType::Transform_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "geometry_msgs/Transform";
    }

    static const char*
    value(const NS_DataType::Transform_< ContainerAllocator >&)
    {
      return value();
    }
  };

  template< class ContainerAllocator >
  struct Definition< NS_DataType::Transform_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "# This represents the transform between two coordinate frames in free space.\n\
\n\
Vector3 translation\n\
Quaternion rotation\n\
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
    value(const NS_DataType::Transform_< ContainerAllocator >&)
    {
      return value();
    }
  };

} // namespace message_traits

namespace NS_NaviCommon
{

  template< class ContainerAllocator >
  struct Serializer< NS_DataType::Transform_< ContainerAllocator > >
  {
    template< typename Stream, typename T >
    inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.translation);
      stream.next(m.rotation);
    }

    DECLARE_ALLINONE_SERIALIZER}; // struct Transform_

}
// namespace serialization

#endif /* GEOMETRY_TRANSFORM_H_ */
