/*
 * OccupancyGridUpdate.h
 *
 *  Created on: 2016年11月4日
 *      Author: seeing
 */

#ifndef _DATATYPE_OCCUPANCYGRIDUPDATE_H_
#define _DATATYPE_OCCUPANCYGRIDUPDATE_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    struct OccupancyGridUpdate_: public DataBase
    {
      typedef OccupancyGridUpdate_<ContainerAllocator> Type;
    public:
      OccupancyGridUpdate_ ()
          : header (), x (0), y (0), width (0), height (0), data ()
      {
      }
      ;

      OccupancyGridUpdate_ (const ContainerAllocator& allocator)
          : header (allocator), x (0), y (0), width (0), height (0),
              data (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;

      int x;
      int y;

      int width;
      int height;

      std::vector<char,
          typename ContainerAllocator::template rebind<char>::other> data;

      typedef boost::shared_ptr<OccupancyGridUpdate_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<OccupancyGridUpdate_<ContainerAllocator> const> ConstPtr;
/*
    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, header);
        NS_NaviCommon::serialize(stream, x);
        NS_NaviCommon::serialize(stream, y);
        NS_NaviCommon::serialize(stream, width);
        NS_NaviCommon::serialize(stream, height);
        NS_NaviCommon::serialize(stream, data);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, header);
        NS_NaviCommon::deserialize(stream, x);
        NS_NaviCommon::deserialize(stream, y);
        NS_NaviCommon::deserialize(stream, width);
        NS_NaviCommon::deserialize(stream, height);
        NS_NaviCommon::deserialize(stream, data);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(header);
        size += NS_NaviCommon::serializationLength(x);
        size += NS_NaviCommon::serializationLength(y);
        size += NS_NaviCommon::serializationLength(width);
        size += NS_NaviCommon::serializationLength(height);
        size += NS_NaviCommon::serializationLength(data);
        return size;
      }
      */

    };
  
  typedef OccupancyGridUpdate_<std::allocator<void> > OccupancyGridUpdate;
  
  typedef boost::shared_ptr<OccupancyGridUpdate> OccupancyGridUpdatePtr;
  typedef boost::shared_ptr<OccupancyGridUpdate const> OccupancyGridUpdateConstPtr;

}

#endif /* DATASET_DATATYPE_OCCUPANCYGRIDUPDATE_H_ */
