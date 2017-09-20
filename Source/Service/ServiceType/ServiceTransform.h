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
  
  template<class ContainerAllocator>
  struct ServiceTransform_: public ServiceBase
  {
    typedef ServiceTransform_<ContainerAllocator> Type;
  public:
    ServiceTransform_ ()
        : transform ()
    {
    }
    ;

    ServiceTransform_ (const ContainerAllocator& allocator)
        : transform (allocator)
    {
    }
    ;

    NS_DataType::Transform_<ContainerAllocator> transform;

    typedef boost::shared_ptr<ServiceTransform_<ContainerAllocator> > Ptr;
    typedef boost::shared_ptr<ServiceTransform_<ContainerAllocator> const> ConstPtr;

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
  };
  
  typedef ServiceTransform_<std::allocator<void> > ServiceTransform;
  
  typedef boost::shared_ptr<ServiceTransform> ServiceTransformPtr;
  typedef boost::shared_ptr<ServiceTransform const> ServiceTransformConstPtr;

}

#endif /* SERVICE_SERVICETYPE_SERVICETRANSFORM_H_ */
