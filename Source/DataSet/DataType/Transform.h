/*
 * Transform.h
 *
 *  Created on: 2016年9月23日
 *      Author: seeing
 */

#ifndef _DATATYPE_TRANSFORM_H_
#define _DATATYPE_TRANSFORM_H_

#include "Quaternion.h"
#include "Vector3.h"
#include "DataBase.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    struct Transform_: public DataBase
    {
      typedef Transform_<ContainerAllocator> Type;
    public:
      Transform_ ()
          : translation (), rotation ()
      {
      }
      ;

      Transform_ (const ContainerAllocator& allocator)
          : translation (allocator), rotation (allocator)
      {
      }
      ;

      Vector3_<ContainerAllocator> translation;
      Quaternion_<ContainerAllocator> rotation;

      typedef boost::shared_ptr<Transform_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<Transform_<ContainerAllocator> const> ConstPtr;

    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, translation);
        NS_NaviCommon::serialize(stream, rotation);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, translation);
        NS_NaviCommon::deserialize(stream, rotation);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(translation);
        size += NS_NaviCommon::serializationLength(rotation);
        return size;
      }
    };
  
  typedef Transform_<std::allocator<void> > Transform;
  
  typedef boost::shared_ptr<Transform> TransformPtr;
  typedef boost::shared_ptr<Transform const> TransformConstPtr;

}

#endif /* GEOMETRY_TRANSFORM_H_ */
