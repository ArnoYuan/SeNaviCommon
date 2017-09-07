/*
 * ServiceOdometry.h
 *
 *  Created on: 2016年10月15日
 *      Author: seeing
 */

#ifndef _SERVICETYPE_SERVICEODOMETRY_H_
#define _SERVICETYPE_SERVICEODOMETRY_H_

#include "../../DataSet/DataType/Odometry.h"
#include "ServiceBase.h"

namespace NS_ServiceType
{
  
  template<class ContainerAllocator>
    struct ServiceOdometry_: public ServiceBase
    {
      typedef ServiceOdometry_<ContainerAllocator> Type;
    public:
      ServiceOdometry_ ()
          : odom ()
      {
      }
      ;

      ServiceOdometry_ (const ContainerAllocator& allocator)
          : odom (allocator)
      {
      }
      ;

      NS_DataType::Odometry_<ContainerAllocator> odom;

      typedef boost::shared_ptr<ServiceOdometry_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<ServiceOdometry_<ContainerAllocator> const> ConstPtr;
    };
  
  typedef ServiceOdometry_<std::allocator<void> > ServiceOdometry;
  
  typedef boost::shared_ptr<ServiceOdometry> ServiceOdometryPtr;
  typedef boost::shared_ptr<ServiceOdometry const> ServiceOdometryConstPtr;

}

#endif /* SERVICE_SERVICETYPE_SERVICEODOMETRY_H_ */
