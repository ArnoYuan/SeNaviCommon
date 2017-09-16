/*
 * PointCloud.h
 *
 *  Created on: 2016年9月28日
 *      Author: seeing
 */

#ifndef _DATATYPE_POINTCLOUD_H_
#define _DATATYPE_POINTCLOUD_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "Point32.h"
#include "ChannelFloat32.h"
#include "Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    struct PointCloud_: public DataBase
    {
      typedef PointCloud_<ContainerAllocator> Type;
    public:
      PointCloud_ ()
          : header (), points (), channels ()
      {
      }
      ;

      PointCloud_ (const ContainerAllocator& allocator)
          : header (allocator), points (allocator), channels (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;
      std::vector<Point32_<ContainerAllocator>,
          typename ContainerAllocator::template rebind<
              Point32_<ContainerAllocator> >::other> points;
      std::vector<ChannelFloat32_<ContainerAllocator>,
          typename ContainerAllocator::template rebind<
              ChannelFloat32_<ContainerAllocator> >::other> channels;

      typedef boost::shared_ptr<PointCloud_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<PointCloud_<ContainerAllocator> const> ConstPtr;

    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, header);
        NS_NaviCommon::serialize(stream, points);
        NS_NaviCommon::serialize(stream, channels);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, header);
        NS_NaviCommon::deserialize(stream, points);
        NS_NaviCommon::deserialize(stream, channels);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(header);
        size += NS_NaviCommon::serializationLength(points);
        size += NS_NaviCommon::serializationLength(channels);
        return size;
      }
    };
  
  typedef PointCloud_<std::allocator<void> > PointCloud;
  
  typedef boost::shared_ptr<PointCloud> PointCloudPtr;
  typedef boost::shared_ptr<PointCloud const> PointCloudConstPtr;

}

#endif /* _POINTCLOUD_H_ */
