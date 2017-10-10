/*
 * Vector3Stamped.h
 *
 *  Created on: 2016年9月23日
 *      Author: seeing
 */

#ifndef _DATATYPE_VECTOR3STAMPED_H_
#define _DATATYPE_VECTOR3STAMPED_H_

#include "Vector3.h"
#include "DataBase.h"
#include "DataHeader.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    //struct Vector3Stamped_: public DataBase
    struct Vector3Stamped_
    {
      typedef Vector3Stamped_<ContainerAllocator> Type;
    public:
      Vector3Stamped_ ()
          : header (), vector ()
      {
      }
      ;

      Vector3Stamped_ (const ContainerAllocator& allocator)
          : header (allocator), vector (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;
      Vector3_<ContainerAllocator> vector;

      typedef boost::shared_ptr<Vector3Stamped_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<Vector3Stamped_<ContainerAllocator> const> ConstPtr;
/*
    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, header);
        NS_NaviCommon::serialize(stream, vector);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, header);
        NS_NaviCommon::deserialize(stream, vector);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(header);
        size += NS_NaviCommon::serializationLength(vector);
        return size;
      }
      */
    };
  
  typedef Vector3Stamped_<std::allocator<void> > Vector3Stamped;
  
  typedef boost::shared_ptr<Vector3Stamped> Vector3StampedPtr;
  typedef boost::shared_ptr<Vector3Stamped const> Vector3StampedConstPtr;

}

#endif /* DATASET_DATATYPE_VECTOR3STAMPED_H_ */
