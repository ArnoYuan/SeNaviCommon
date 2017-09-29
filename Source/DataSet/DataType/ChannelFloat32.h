/*
 * ChannelFloat32.h
 *
 *  Created on: 2016年9月28日
 *      Author: seeing
 */

#ifndef _DATATYPE_CHANNELFLOAT32_H_
#define _DATATYPE_CHANNELFLOAT32_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    struct ChannelFloat32_: public DataBase
    {
      typedef ChannelFloat32_<ContainerAllocator> Type;
    public:
      ChannelFloat32_ ()
          : name (), values ()
      {
      }
      ;

      ChannelFloat32_ (const ContainerAllocator& allocator)
          : name (allocator), values (allocator)
      {
      }
      ;

      std::basic_string<int8_t, std::char_traits<int8_t>,
          typename ContainerAllocator::template rebind<int8_t>::other> name;
      std::basic_string<int8_t, std::char_traits<int8_t>,
          typename ContainerAllocator::template rebind<int8_t>::other> values;

      typedef boost::shared_ptr<ChannelFloat32_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<ChannelFloat32_<ContainerAllocator> const> ConstPtr;

    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, name);
        NS_NaviCommon::serialize(stream, values);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, name);
        NS_NaviCommon::deserialize(stream, values);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(name);
        size += NS_NaviCommon::serializationLength(values);
        return size;
      }
    };
  
  typedef ChannelFloat32_<std::allocator<void> > ChannelFloat32;
  
  typedef boost::shared_ptr<ChannelFloat32> ChannelFloat32Ptr;
  typedef boost::shared_ptr<ChannelFloat32 const> ChannelFloat32ConstPtr;

}

#endif /* DATASET_DATATYPE_CHANNELFLOAT32_H_ */
