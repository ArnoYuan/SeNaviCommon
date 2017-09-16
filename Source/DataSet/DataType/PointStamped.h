/*
 * PointStamped.h
 *
 *  Created on: 2016年9月23日
 *      Author: seeing
 */

#ifndef _DATATYPE_POINTSTAMPED_H_
#define _DATATYPE_POINTSTAMPED_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "Point.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    struct PointStamped_: public DataBase
    {
      typedef PointStamped_<ContainerAllocator> Type;
    public:
      PointStamped_ ()
          : header (), point ()
      {
      }
      ;

      PointStamped_ (const ContainerAllocator& allocator)
          : header (allocator), point (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;
      Point_<ContainerAllocator> point;

      typedef boost::shared_ptr<PointStamped_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<PointStamped_<ContainerAllocator> const> ConstPtr;

    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, header);
        NS_NaviCommon::serialize(stream, point);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, header);
        NS_NaviCommon::deserialize(stream, point);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(header);
        size += NS_NaviCommon::serializationLength(point);
        return size;
      }
    };
  
  typedef PointStamped_<std::allocator<void> > PointStamped;
  
  typedef boost::shared_ptr<PointStamped> PointStampedPtr;
  typedef boost::shared_ptr<PointStamped const> PointStampedConstPtr;

}

#endif /* _POINTSTAMPED_H_ */
