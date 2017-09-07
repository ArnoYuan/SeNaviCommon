/*
 * Pose.h
 *
 *  Created on: 2016年9月23日
 *      Author: seeing
 */

#ifndef _DATATYPE_POSE_H_
#define _DATATYPE_POSE_H_

#include "DataBase.h"
#include "Point.h"
#include "Quaternion.h"
#include "Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    struct Pose_: public DataBase
    {
      typedef Pose_<ContainerAllocator> Type;
    public:
      Pose_ ()
          : position (), orientation ()
      {
      }
      ;

      Pose_ (const ContainerAllocator& allocator)
          : position (allocator), orientation (allocator)
      {
      }
      ;

      Point_<ContainerAllocator> position;
      Quaternion_<ContainerAllocator> orientation;

      typedef boost::shared_ptr<Pose_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<Pose_<ContainerAllocator> const> ConstPtr;

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
  
  typedef Pose_<std::allocator<void> > Pose;
  
  typedef boost::shared_ptr<Pose> PosePtr;
  typedef boost::shared_ptr<Pose const> PoseConstPtr;

}

#endif /* _POSE_H_ */
