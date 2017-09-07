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
    };
  
  typedef ServiceTransform_<std::allocator<void> > ServiceTransform;
  
  typedef boost::shared_ptr<ServiceTransform> ServiceTransformPtr;
  typedef boost::shared_ptr<ServiceTransform const> ServiceTransformConstPtr;

}

#endif /* SERVICE_SERVICETYPE_SERVICETRANSFORM_H_ */
