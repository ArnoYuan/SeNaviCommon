/*
 * Point.h
 *
 *  Created on: 2016年8月18日
 *      Author: seeing
 */

#ifndef _DATATYPE_POINT_H_
#define _DATATYPE_POINT_H_

#include <string>
#include <vector>
#include <ostream>
#include <boost/shared_ptr.hpp>
#include "DataBase.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{

  template< class ContainerAllocator >
  //struct Point_: public DataBase
  struct Point_
  {
    typedef Point_< ContainerAllocator > Type;

    Point_()
        : x(0.0), y(0.0), z(0.0)
    {
    }

    Point_(const ContainerAllocator& _alloc)
        : x(0.0), y(0.0), z(0.0)
    {
    }

    typedef double _x_type, _y_type, _z_type;

    double x, y, z;

    typedef boost::shared_ptr< Point_< ContainerAllocator > > Ptr;
    typedef boost::shared_ptr< Point_< ContainerAllocator > const > ConstPtr;
    /*
     public:
     virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
     {
     NS_NaviCommon::OStream stream(write_ptr, 1000000000);
     NS_NaviCommon::serialize(stream, x);
     NS_NaviCommon::serialize(stream, y);
     NS_NaviCommon::serialize(stream, z);
     return stream.getData();
     }

     virtual uint8_t *deserialize(uint8_t *read_ptr)
     {
     NS_NaviCommon::IStream stream(read_ptr, 1000000000);
     NS_NaviCommon::deserialize(stream, x);
     NS_NaviCommon::deserialize(stream, y);
     NS_NaviCommon::deserialize(stream, z);
     return stream.getData();
     }

     virtual uint32_t serializationLength() const
     {
     uint32_t size = 0;
     size += NS_NaviCommon::serializationLength(x);
     size += NS_NaviCommon::serializationLength(y);
     size += NS_NaviCommon::serializationLength(z);
     return size;
     }
     */
  };

  typedef Point_< std::allocator< void > > Point;

  typedef boost::shared_ptr< Point > PointPtr;
  typedef boost::shared_ptr< Point const > PointConstPtr;

}

namespace NS_NaviCommon
{

// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/tmp/binarydeb/ros-kinetic-geometry-msgs-1.12.5/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']

  template< class ContainerAllocator >
  struct IsFixedSize< NS_DataType::Point_< ContainerAllocator > > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsFixedSize< NS_DataType::Point_< ContainerAllocator > const > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage< NS_DataType::Point_< ContainerAllocator > > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage< NS_DataType::Point_< ContainerAllocator > const > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader< NS_DataType::Point_< ContainerAllocator > > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader< NS_DataType::Point_< ContainerAllocator > const > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct MD5Sum< NS_DataType::Point_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "4a842b65f413084dc2b10fb484ea7f17";
    }

    static const char*
    value(const NS_DataType::Point_< ContainerAllocator >&)
    {
      return value();
    }
    static const uint64_t static_value1 = 0x4a842b65f413084dULL;
    static const uint64_t static_value2 = 0xc2b10fb484ea7f17ULL;
  };

  template< class ContainerAllocator >
  struct DataType< NS_DataType::Point_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "geometry_msgs/Point";
    }

    static const char*
    value(const NS_DataType::Point_< ContainerAllocator >&)
    {
      return value();
    }
  };

  template< class ContainerAllocator >
  struct Definition< NS_DataType::Point_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
    }

    static const char*
    value(const NS_DataType::Point_< ContainerAllocator >&)
    {
      return value();
    }
  };

} // namespace message_traits

namespace NS_NaviCommon
{

  template< class ContainerAllocator >
  struct Serializer< NS_DataType::Point_< ContainerAllocator > >
  {
    template< typename Stream, typename T >
    inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
    }

    DECLARE_ALLINONE_SERIALIZER}; // struct Point_

}
// namespace serialization

#endif /* _POINT_H_ */
