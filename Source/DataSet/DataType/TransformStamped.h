/*
 * TransformStamped.h
 *
 *  Created on: 2016年9月23日
 *      Author: seeing
 */

#ifndef _DATATYPE_TRANSFORMSTAMPED_H_
#define _DATATYPE_TRANSFORMSTAMPED_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "Transform.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  template<class ContainerAllocator>
    //struct TransformStamped_: public DataBase
    struct TransformStamped_
    {
      typedef TransformStamped_<ContainerAllocator> Type;
    public:
      TransformStamped_ ()
          : header (), child_frame_id (), transform ()
      {
      }
      ;

      TransformStamped_ (const ContainerAllocator& allocator)
          : header (allocator), child_frame_id (allocator),
              transform (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;

      std::basic_string<char, std::char_traits<char>,
          typename ContainerAllocator::template rebind<char>::other> child_frame_id;

      Transform_<ContainerAllocator> transform;

      typedef boost::shared_ptr<TransformStamped_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<TransformStamped_<ContainerAllocator> const> ConstPtr;
/*
    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, header);
        NS_NaviCommon::serialize(stream, child_frame_id);
        NS_NaviCommon::serialize(stream, transform);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, header);
        NS_NaviCommon::deserialize(stream, child_frame_id);
        NS_NaviCommon::deserialize(stream, transform);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(header);
        size += NS_NaviCommon::serializationLength(child_frame_id);
        size += NS_NaviCommon::serializationLength(transform);
        return size;
      }
      */
    };
  
  typedef TransformStamped_<std::allocator<void> > TransformStamped;
  
  typedef boost::shared_ptr<TransformStamped> TransformStampedPtr;
  typedef boost::shared_ptr<TransformStamped const> TransformStampedConstPtr;

}

#endif /* _TRANSFORMSTAMPED_H_ */
