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
    };
  
  typedef ServiceMap_<std::allocator<void> > ServiceMap;
  
  typedef boost::shared_ptr<ServiceMap> ServiceMapPtr;
  typedef boost::shared_ptr<ServiceMap const> ServiceMapConstPtr;

}

#endif /* SERVICE_SERVICETYPE_SERVICEMAP_H_ */
