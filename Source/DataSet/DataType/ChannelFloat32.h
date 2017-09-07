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
#include "Serialization/Serialization.h"

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

      std::basic_string<char, std::char_traits<char>,
          typename ContainerAllocator::template rebind<char>::other> name;
      std::basic_string<char, std::char_traits<char>,
          typename ContainerAllocator::template rebind<char>::other> values;

      typedef boost::shared_ptr<ChannelFloat32_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<ChannelFloat32_<ContainerAllocator> const> ConstPtr;

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
  
  typedef ChannelFloat32_<std::allocator<void> > ChannelFloat32;
  
  typedef boost::shared_ptr<ChannelFloat32> ChannelFloat32Ptr;
  typedef boost::shared_ptr<ChannelFloat32 const> ChannelFloat32ConstPtr;

}

#endif /* DATASET_DATATYPE_CHANNELFLOAT32_H_ */
