/*
 * PolygonStamped.h
 *
 *  Created on: 2016年11月3日
 *      Author: seeing
 */

#ifndef _DATATYPE_POLYGONSTAMPED_H_
#define _DATATYPE_POLYGONSTAMPED_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "Polygon.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    //struct PolygonStamped_: public DataBase
    struct PolygonStamped_
    {
      typedef PolygonStamped_<ContainerAllocator> Type;
    public:
      PolygonStamped_ ()
          : header (), polygon ()
      {
      }
      ;

      PolygonStamped_ (const ContainerAllocator& allocator)
          : header (allocator), polygon (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;
      Polygon_<ContainerAllocator> polygon;

      typedef boost::shared_ptr<PolygonStamped_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<PolygonStamped_<ContainerAllocator> const> ConstPtr;
/*
    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, header);
        NS_NaviCommon::serialize(stream, polygon);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, header);
        NS_NaviCommon::deserialize(stream, polygon);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(header);
        size += NS_NaviCommon::serializationLength(polygon);
        return size;
      }
      */
    };
  
  typedef PolygonStamped_<std::allocator<void> > PolygonStamped;
  
  typedef boost::shared_ptr<PolygonStamped> PolygonStampedPtr;
  typedef boost::shared_ptr<PolygonStamped const> PolygonStampedConstPtr;

}

#endif /* DATASET_DATATYPE_POLYGONSTAMPED_H_ */
