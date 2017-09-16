/*
 * Odometry.h
 *
 *  Created on: 2016年10月14日
 *      Author: seeing
 */

#ifndef _DATATYPE_ODOMETRY_H_
#define _DATATYPE_ODOMETRY_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "Pose.h"
#include "Twist.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    struct Odometry_: public DataBase
    {
      typedef Odometry_<ContainerAllocator> Type;
    public:
      Odometry_ ()
          : header (), pose (), twist ()
      {
      }
      ;

      Odometry_ (const ContainerAllocator& allocator)
          : header (allocator), pose (allocator), twist (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;
      Pose_<ContainerAllocator> pose;
      Twist_<ContainerAllocator> twist;

      typedef boost::shared_ptr<Odometry_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<Odometry_<ContainerAllocator> const> ConstPtr;

    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, header);
        NS_NaviCommon::serialize(stream, pose);
        NS_NaviCommon::serialize(stream, twist);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, header);
        NS_NaviCommon::deserialize(stream, pose);
        NS_NaviCommon::deserialize(stream, twist);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(header);
        size += NS_NaviCommon::serializationLength(pose);
        size += NS_NaviCommon::serializationLength(twist);
        return size;
      }
    };
  
  typedef Odometry_<std::allocator<void> > Odometry;
  
  typedef boost::shared_ptr<Odometry> OdometryPtr;
  typedef boost::shared_ptr<Odometry const> OdometryConstPtr;

}

#endif /* DATASET_DATATYPE_ODOMETRY_H_ */
