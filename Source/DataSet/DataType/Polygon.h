/*
 * Polygon.h
 *
 *  Created on: 2016年11月3日
 *      Author: seeing
 */

#ifndef _DATATYPE_POLYGON_H_
#define _DATATYPE_POLYGON_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "Point32.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    //struct Polygon_: public DataBase
    struct Polygon_
    {
      typedef Polygon_<ContainerAllocator> Type;
    public:
      Polygon_ ()
          : points ()
      {
      }
      ;

      Polygon_ (const ContainerAllocator& allocator)
          : points (allocator)
      {
      }
      ;

      std::vector<Point32_<ContainerAllocator>,
          typename ContainerAllocator::template rebind<
              Point32_<ContainerAllocator> >::other> points;

      typedef boost::shared_ptr<Polygon_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<Polygon_<ContainerAllocator> const> ConstPtr;
      /*
       public:
       virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
       {
       NS_NaviCommon::OStream stream(write_ptr, 1000000000);
       NS_NaviCommon::serialize(stream, points);
       return stream.getData();
       }

       virtual uint8_t *deserialize(uint8_t *read_ptr)
       {
       NS_NaviCommon::IStream stream(read_ptr, 1000000000);
       NS_NaviCommon::deserialize(stream, points);
       return stream.getData();
       }

       virtual uint32_t serializationLength() const
       {
       uint32_t size = 0;
       size += NS_NaviCommon::serializationLength(points);
       return size;
       }
       */
    };
  
  typedef Polygon_<std::allocator<void> > Polygon;
  
  typedef boost::shared_ptr<Polygon> PolygonPtr;
  typedef boost::shared_ptr<Polygon const> PolygonConstPtr;

}

#endif /* DATASET_DATATYPE_POLYGON_H_ */
