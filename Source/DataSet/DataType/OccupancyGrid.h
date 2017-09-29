/*
 * OccupancyGrid.h
 *
 *  Created on: 2016年10月14日
 *      Author: seeing
 */

#ifndef _DATATYPE_OCCUPANCYGRID_H_
#define _DATATYPE_OCCUPANCYGRID_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "MapMetaData.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  template<class ContainerAllocator>
    struct OccupancyGrid_: public DataBase
    {
      typedef OccupancyGrid_<ContainerAllocator> Type;
    public:
      OccupancyGrid_ ()
          : header (), info (), data ()
      {
      }
      ;

      OccupancyGrid_ (const ContainerAllocator& allocator)
          : header (allocator), info (allocator), data (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;
      MapMetaData_<ContainerAllocator> info;

      std::vector<int8_t,
          typename ContainerAllocator::template rebind<int8_t>::other> data;

      typedef boost::shared_ptr<OccupancyGrid_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<OccupancyGrid_<ContainerAllocator> const> ConstPtr;

    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, header);
        NS_NaviCommon::serialize(stream, info);
        NS_NaviCommon::serialize(stream, data);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, header);
        NS_NaviCommon::deserialize(stream, info);
        NS_NaviCommon::deserialize(stream, data);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(header);
        size += NS_NaviCommon::serializationLength(info);
        size += NS_NaviCommon::serializationLength(data);
        return size;
      }
    };
  
  typedef OccupancyGrid_<std::allocator<void> > OccupancyGrid;
  
  typedef boost::shared_ptr<OccupancyGrid> OccupancyGridPtr;
  typedef boost::shared_ptr<OccupancyGrid const> OccupancyGridConstPtr;

}

#endif /* DATASET_DATATYPE_OCCUPANCYGRID_H_ */
