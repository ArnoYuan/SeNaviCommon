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

  public:
    virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
    {
      NS_NaviCommon::OStream stream(write_ptr, 1000000000);

      return stream.getData();
    }

    virtual uint8_t *deserialize(uint8_t *read_ptr)
    {
      NS_NaviCommon::IStream stream(read_ptr, 1000000000);

      return stream.getData();
    }

    virtual uint32_t serializationLength() const
    {
      uint32_t size = 0;

      return size;
    }
  };
  
  typedef ServiceOdometry_<std::allocator<void> > ServiceOdometry;
  
  typedef boost::shared_ptr<ServiceOdometry> ServiceOdometryPtr;
  typedef boost::shared_ptr<ServiceOdometry const> ServiceOdometryConstPtr;

}

#endif /* SERVICE_SERVICETYPE_SERVICEODOMETRY_H_ */
