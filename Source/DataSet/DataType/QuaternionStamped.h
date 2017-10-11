/*
 * QuaternionStamped.h
 *
 *  Created on: 2016年9月23日
 *      Author: seeing
 */

#ifndef _DATATYPE_QUATERNIONSTAMPED_H_
#define _DATATYPE_QUATERNIONSTAMPED_H_

#include "Quaternion.h"
#include "DataBase.h"
#include "DataHeader.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{

  template< class ContainerAllocator >
  //struct QuaternionStamped_: public DataBase
  struct QuaternionStamped_
  {
    typedef QuaternionStamped_< ContainerAllocator > Type;
  public:
    QuaternionStamped_()
        : header(), quaternion()
    {
    }
    ;

    QuaternionStamped_(const ContainerAllocator& allocator)
        : header(allocator), quaternion(allocator)
    {
    }
    ;

    DataHeader_< ContainerAllocator > header;
    Quaternion_< ContainerAllocator > quaternion;

    typedef boost::shared_ptr< QuaternionStamped_< ContainerAllocator > > Ptr;
    typedef boost::shared_ptr< QuaternionStamped_< ContainerAllocator > const > ConstPtr;
    /*
     public:
     virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
     {
     NS_NaviCommon::OStream stream(write_ptr, 1000000000);
     NS_NaviCommon::serialize(stream, header);
     NS_NaviCommon::serialize(stream, quaternion);
     return stream.getData();
     }

     virtual uint8_t *deserialize(uint8_t *read_ptr)
     {
     NS_NaviCommon::IStream stream(read_ptr, 1000000000);
     NS_NaviCommon::deserialize(stream, header);
     NS_NaviCommon::deserialize(stream, quaternion);
     return stream.getData();
     }

     virtual uint32_t serializationLength() const
     {
     uint32_t size = 0;
     size += NS_NaviCommon::serializationLength(header);
     size += NS_NaviCommon::serializationLength(quaternion);
     return size;
     }
     */
  };

  typedef QuaternionStamped_< std::allocator< void > > QuaternionStamped;

  typedef boost::shared_ptr< QuaternionStamped > QuaternionStampedPtr;
  typedef boost::shared_ptr< QuaternionStamped const > QuaternionStampedConstPtr;

}

#endif /* DATASET_DATATYPE_QUATERNIONSTAMPED_H_ */
