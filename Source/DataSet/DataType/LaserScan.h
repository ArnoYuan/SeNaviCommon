/*
 * LaserScan.h
 *
 *  Created on: 2016年9月28日
 *      Author: seeing
 */

#ifndef _DATATYPE_LASERSCAN_H_
#define _DATATYPE_LASERSCAN_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    struct LaserScan_: public DataBase
    {
      typedef LaserScan_<ContainerAllocator> Type;
    public:
      LaserScan_ ()
          : header (), angle_min (0.0), angle_max (0.0), angle_increment (0.0),
              time_increment (0.0), scan_time (0.0), range_min (0.0),
              range_max (0.0), ranges (), intensities ()
      {
      }
      ;

      LaserScan_ (const ContainerAllocator& allocator)
          : header (allocator), angle_min (0.0), angle_max (0.0),
              angle_increment (0.0), time_increment (0.0), scan_time (0.0),
              range_min (0.0), range_max (0.0), ranges (allocator),
              intensities (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;
      float angle_min;
      float angle_max;
      float angle_increment;
      float time_increment;
      float scan_time;
      float range_min;
      float range_max;

      std::vector<float,
          typename ContainerAllocator::template rebind<float>::other> ranges;
      std::vector<float,
          typename ContainerAllocator::template rebind<float>::other> intensities;

      typedef boost::shared_ptr<LaserScan_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<LaserScan_<ContainerAllocator> const> ConstPtr;


    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, header);
        NS_NaviCommon::serialize(stream, angle_min);
        NS_NaviCommon::serialize(stream, angle_max);
        NS_NaviCommon::serialize(stream, angle_increment);
        NS_NaviCommon::serialize(stream, time_increment);
        NS_NaviCommon::serialize(stream, scan_time);
        NS_NaviCommon::serialize(stream, range_min);
        NS_NaviCommon::serialize(stream, range_max);
        NS_NaviCommon::serialize(stream, ranges);
        NS_NaviCommon::serialize(stream, intensities);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, header);
        NS_NaviCommon::deserialize(stream, angle_min);
        NS_NaviCommon::deserialize(stream, angle_max);
        NS_NaviCommon::deserialize(stream, angle_increment);
        NS_NaviCommon::deserialize(stream, time_increment);
        NS_NaviCommon::deserialize(stream, scan_time);
        NS_NaviCommon::deserialize(stream, range_min);
        NS_NaviCommon::deserialize(stream, range_max);
        NS_NaviCommon::deserialize(stream, ranges);
        NS_NaviCommon::deserialize(stream, intensities);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(header);
        size += NS_NaviCommon::serializationLength(angle_min);
        size += NS_NaviCommon::serializationLength(angle_max);
        size += NS_NaviCommon::serializationLength(angle_increment);
        size += NS_NaviCommon::serializationLength(time_increment);
        size += NS_NaviCommon::serializationLength(scan_time);
        size += NS_NaviCommon::serializationLength(range_min);
        size += NS_NaviCommon::serializationLength(range_max);
        size += NS_NaviCommon::serializationLength(ranges);
        size += NS_NaviCommon::serializationLength(intensities);
        return size;
      }
    };
  
  typedef LaserScan_<std::allocator<void> > LaserScan;
  
  typedef boost::shared_ptr<LaserScan> LaserScanPtr;
  typedef boost::shared_ptr<LaserScan const> LaserScanConstPtr;

}

#endif /* _LASERSCAN_H_ */
