/*
 * ServiceTransform.h
 *
 *  Created on: 2016年10月22日
 *      Author: seeing
 */

#ifndef _SERVICETYPE_SERVICETRANSFORM_H_
#define _SERVICETYPE_SERVICETRANSFORM_H_

#include "../../DataSet/DataType/Transform.h"
#include "ServiceBase.h"

namespace NS_ServiceType
{

  template< class ContainerAllocator >
  //struct ServiceTransform_: public ServiceBase
  struct ServiceTransform_
  {
    typedef ServiceTransform_< ContainerAllocator > Type;
  public:
    ServiceTransform_()
        : result(false), transform()
    {
    }
    ;

    ServiceTransform_(const ContainerAllocator& allocator)
        : result(false), transform(allocator)
    {
    }
    ;

    bool result;
    NS_DataType::Transform_< ContainerAllocator > transform;

    typedef boost::shared_ptr< ServiceTransform_< ContainerAllocator > > Ptr;
    typedef boost::shared_ptr< ServiceTransform_< ContainerAllocator > const > ConstPtr;
    /*
     public:
     virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
     {
     NS_NaviCommon::OStream stream(write_ptr, 1000000000);
     NS_NaviCommon::serialize(stream, result);
     NS_NaviCommon::serialize(stream, transform);
     return stream.getData();
     }

     virtual uint8_t *deserialize(uint8_t *read_ptr)
     {
     NS_NaviCommon::IStream stream(read_ptr, 1000000000);
     NS_NaviCommon::deserialize(stream, result);
     NS_NaviCommon::deserialize(stream, transform);
     return stream.getData();
     }

     virtual uint32_t serializationLength() const
     {
     uint32_t size = 0;
     size += NS_NaviCommon::serializationLength(result);
     size += NS_NaviCommon::serializationLength(transform);
     return size;
     }
     */
  };

  typedef ServiceTransform_< std::allocator< void > > ServiceTransform;

  typedef boost::shared_ptr< ServiceTransform > ServiceTransformPtr;
  typedef boost::shared_ptr< ServiceTransform const > ServiceTransformConstPtr;

}

namespace NS_NaviCommon
{
  template< class ContainerAllocator >
  struct IsFixedSize< NS_ServiceType::ServiceTransform_< ContainerAllocator > > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsFixedSize<
      NS_ServiceType::ServiceTransform_< ContainerAllocator > const > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage< NS_ServiceType::ServiceTransform_< ContainerAllocator > > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage<
      NS_ServiceType::ServiceTransform_< ContainerAllocator > const > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader< NS_ServiceType::ServiceTransform_< ContainerAllocator > > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader<
      NS_ServiceType::ServiceTransform_< ContainerAllocator > const > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct MD5Sum< NS_ServiceType::ServiceTransform_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "";
    }

    static const char*
    value(const NS_ServiceType::ServiceTransform_< ContainerAllocator >&)
    {
      return value();
    }
    static const uint64_t static_value1 = 0;
    static const uint64_t static_value2 = 0;
  };

  template< class ContainerAllocator >
  struct DataType< NS_ServiceType::ServiceTransform_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "ServiceTransform";
    }

    static const char*
    value(const NS_ServiceType::ServiceTransform_< ContainerAllocator >&)
    {
      return value();
    }
  };

  template< class ContainerAllocator >
  struct Definition< NS_ServiceType::ServiceTransform_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "";
    }

    static const char*
    value(const NS_ServiceType::ServiceTransform_< ContainerAllocator >&)
    {
      return value();
    }
  };

} // namespace message_traits

namespace NS_NaviCommon
{

  template< class ContainerAllocator >
  struct Serializer< NS_ServiceType::ServiceTransform_< ContainerAllocator > >
  {
    template< typename Stream, typename T >
    inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
      stream.next(m.transform);
    }

    DECLARE_ALLINONE_SERIALIZER}; // struct ServiceTransform_

}
// namespace serialization

#endif /* SERVICE_SERVICETYPE_SERVICETRANSFORM_H_ */
