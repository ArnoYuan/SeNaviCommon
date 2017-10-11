/*
 * Twist.h
 *
 *  Created on: 2016年9月24日
 *      Author: seeing
 */

#ifndef _DATATYPE_TWIST_H_
#define _DATATYPE_TWIST_H_

#include "DataBase.h"
#include "Vector3.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    //struct Twist_: public DataBase
    struct Twist_
    {
      typedef Twist_<ContainerAllocator> Type;
    public:
      Twist_ ()
          : linear (), angular ()
      {
      }
      ;

      Twist_ (const ContainerAllocator& allocator)
          : linear (allocator), angular (allocator)
      {
      }
      ;

      Vector3_<ContainerAllocator> linear;
      Vector3_<ContainerAllocator> angular;

      typedef boost::shared_ptr<Twist_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<Twist_<ContainerAllocator> const> ConstPtr;
      /*
       public:
       virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
       {
       NS_NaviCommon::OStream stream(write_ptr, 1000000000);
       NS_NaviCommon::serialize(stream, linear);
       NS_NaviCommon::serialize(stream, angular);
       return stream.getData();
       }

       virtual uint8_t *deserialize(uint8_t *read_ptr)
       {
       NS_NaviCommon::IStream stream(read_ptr, 1000000000);
       NS_NaviCommon::deserialize(stream, linear);
       NS_NaviCommon::deserialize(stream, angular);
       return stream.getData();
       }

       virtual uint32_t serializationLength() const
       {
       uint32_t size = 0;
       size += NS_NaviCommon::serializationLength(linear);
       size += NS_NaviCommon::serializationLength(angular);
       return size;
       }
       */
    };
  
  typedef Twist_<std::allocator<void> > Twist;
  
  typedef boost::shared_ptr<Twist> TwistPtr;
  typedef boost::shared_ptr<Twist const> TwistConstPtr;

}

namespace NS_NaviCommon
{
  
// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/tmp/binarydeb/ros-kinetic-geometry-msgs-1.12.5/msg']}
  
// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']
  
  template<class ContainerAllocator>
    struct IsFixedSize<NS_DataType::Twist_<ContainerAllocator> > : TrueType
    {
    };
  
  template<class ContainerAllocator>
    struct IsFixedSize<NS_DataType::Twist_<ContainerAllocator> const> : TrueType
    {
    };
  
  template<class ContainerAllocator>
    struct IsMessage<NS_DataType::Twist_<ContainerAllocator> > : TrueType
    {
    };
  
  template<class ContainerAllocator>
    struct IsMessage<NS_DataType::Twist_<ContainerAllocator> const> : TrueType
    {
    };
  
  template<class ContainerAllocator>
    struct HasHeader<NS_DataType::Twist_<ContainerAllocator> > : FalseType
    {
    };
  
  template<class ContainerAllocator>
    struct HasHeader<NS_DataType::Twist_<ContainerAllocator> const> : FalseType
    {
    };
  
  template<class ContainerAllocator>
    struct MD5Sum<NS_DataType::Twist_<ContainerAllocator> >
    {
      static const char*
      value ()
      {
        return "9f195f881246fdfa2798d1d3eebca84a";
      }
      
      static const char*
      value (const NS_DataType::Twist_<ContainerAllocator>&)
      {
        return value ();
      }
      static const uint64_t static_value1 = 0x9f195f881246fdfaULL;
      static const uint64_t static_value2 = 0x2798d1d3eebca84aULL;
    };
  
  template<class ContainerAllocator>
    struct DataType<NS_DataType::Twist_<ContainerAllocator> >
    {
      static const char*
      value ()
      {
        return "geometry_msgs/Twist";
      }
      
      static const char*
      value (const NS_DataType::Twist_<ContainerAllocator>&)
      {
        return value ();
      }
    };
  
  template<class ContainerAllocator>
    struct Definition<NS_DataType::Twist_<ContainerAllocator> >
    {
      static const char*
      value ()
      {
        return "# This expresses velocity in free space broken into its linear and angular parts.\n\
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
      
      static const char*
      value (const NS_DataType::Twist_<ContainerAllocator>&)
      {
        return value ();
      }
    };

} // namespace message_traits

namespace NS_NaviCommon
{
  
  template<class ContainerAllocator>
    struct Serializer<NS_DataType::Twist_<ContainerAllocator> >
    {
      template<typename Stream, typename T>
        inline static void
        allInOne (Stream& stream, T m)
        {
          stream.next (m.linear);
          stream.next (m.angular);
        }
      
      DECLARE_ALLINONE_SERIALIZER}; // struct Twist_
    
  }
  // namespace serialization
  
#endif /* _TWIST_H_ */
