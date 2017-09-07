/*
 * ServiceMap.h
 *
 *  Created on: 2016年10月14日
 *      Author: seeing
 */

#ifndef _SERVICETYPE_SERVICEMAP_H_
#define _SERVICETYPE_SERVICEMAP_H_

#include "../../DataSet/DataType/OccupancyGrid.h"
#include "ServiceBase.h"

namespace NS_ServiceType
{
  
  template<class ContainerAllocator>
  struct ServiceMap_: public ServiceBase
  {
    typedef ServiceMap_<ContainerAllocator> Type;
  public:
    ServiceMap_ ()
        : map ()
    {
    }
    ;

    ServiceMap_ (const ContainerAllocator& allocator)
        : map (allocator)
    {
    }
    ;

    NS_DataType::OccupancyGrid_<ContainerAllocator> map;

    typedef boost::shared_ptr<ServiceMap_<ContainerAllocator> > Ptr;
    typedef boost::shared_ptr<ServiceMap_<ContainerAllocator> const> ConstPtr;

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
  
  typedef ServiceMap_<std::allocator<void> > ServiceMap;
  
  typedef boost::shared_ptr<ServiceMap> ServiceMapPtr;
  typedef boost::shared_ptr<ServiceMap const> ServiceMapConstPtr;

}

#endif /* SERVICE_SERVICETYPE_SERVICEMAP_H_ */
