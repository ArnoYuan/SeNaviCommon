/*
 * Quaternion.h
 *
 *  Created on: 2016年8月23日
 *      Author: seeing
 */

#ifndef _DATATYPE_QUATERNION_H_
#define _DATATYPE_QUATERNION_H_

#include <string>
#include <vector>
#include <ostream>
#include <boost/shared_ptr.hpp>
#include "DataBase.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{

  template< class ContainerAllocator >
  //struct Quaternion_: public DataBase
  struct Quaternion_
  {
    typedef Quaternion_< ContainerAllocator > Type;

    Quaternion_()
        : x(0.0), y(0.0), z(0.0), w(0.0)
    {
    }

    Quaternion_(const ContainerAllocator& _alloc)
        : x(0.0), y(0.0), z(0.0), w(0.0)
    {
    }

    typedef double _x_type, _y_type, _z_type, _w_type;

    double x, y, z, w;

    typedef boost::shared_ptr< Quaternion_< ContainerAllocator > > Ptr;
    typedef boost::shared_ptr< Quaternion_< ContainerAllocator > const > ConstPtr;
    /*
     public:
     virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
     {
     NS_NaviCommon::OStream stream(write_ptr, 1000000000);
     NS_NaviCommon::serialize(stream, x);
     NS_NaviCommon::serialize(stream, y);
     NS_NaviCommon::serialize(stream, z);
     NS_NaviCommon::serialize(stream, w);
     return stream.getData();
     }

     virtual uint8_t *deserialize(uint8_t *read_ptr)
     {
     NS_NaviCommon::IStream stream(read_ptr, 1000000000);
     NS_NaviCommon::deserialize(stream, x);
     NS_NaviCommon::deserialize(stream, y);
     NS_NaviCommon::deserialize(stream, z);
     NS_NaviCommon::deserialize(stream, w);
     return stream.getData();
     }

     virtual uint32_t serializationLength() const
     {
     uint32_t size = 0;
     size += NS_NaviCommon::serializationLength(x);
     size += NS_NaviCommon::serializationLength(y);
     size += NS_NaviCommon::serializationLength(z);
     size += NS_NaviCommon::serializationLength(w);
     return size;
     }
     */
  };

  typedef Quaternion_< std::allocator< void > > Quaternion;

  typedef boost::shared_ptr< Quaternion > QuaternionPtr;
  typedef boost::shared_ptr< Quaternion const > QuaternionConstPtr;

} /* namespace NS_NaviCommon */

namespace NS_NaviCommon
{

// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/tmp/binarydeb/ros-kinetic-geometry-msgs-1.12.5/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']

  template< class ContainerAllocator >
  struct IsFixedSize< NS_DataType::Quaternion_< ContainerAllocator > > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsFixedSize< NS_DataType::Quaternion_< ContainerAllocator > const > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage< NS_DataType::Quaternion_< ContainerAllocator > > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage< NS_DataType::Quaternion_< ContainerAllocator > const > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader< NS_DataType::Quaternion_< ContainerAllocator > > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader< NS_DataType::Quaternion_< ContainerAllocator > const > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct MD5Sum< NS_DataType::Quaternion_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "a779879fadf0160734f906b8c19c7004";
    }

    static const char*
    value(const NS_DataType::Quaternion_< ContainerAllocator >&)
    {
      return value();
    }
    static const uint64_t static_value1 = 0xa779879fadf01607ULL;
    static const uint64_t static_value2 = 0x34f906b8c19c7004ULL;
  };

  template< class ContainerAllocator >
  struct DataType< NS_DataType::Quaternion_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "geometry_msgs/Quaternion";
    }

    static const char*
    value(const NS_DataType::Quaternion_< ContainerAllocator >&)
    {
      return value();
    }
  };

  template< class ContainerAllocator >
  struct Definition< NS_DataType::Quaternion_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
    }

    static const char*
    value(const NS_DataType::Quaternion_< ContainerAllocator >&)
    {
      return value();
    }
  };

} // namespace message_traits

namespace NS_NaviCommon
{

  template< class ContainerAllocator >
  struct Serializer< NS_DataType::Quaternion_< ContainerAllocator > >
  {
    template< typename Stream, typename T >
    inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.w);
    }

    DECLARE_ALLINONE_SERIALIZER}; // struct Quaternion_

}
// namespace serialization

#endif /* GEOMETRY_QUATERNION_H_ */
