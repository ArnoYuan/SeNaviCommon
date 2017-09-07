/*
 * Point32.h
 *
 *  Created on: 2016年9月28日
 *      Author: seeing
 */

#ifndef _DATATYPE_POINT32_H_
#define _DATATYPE_POINT32_H_

#include <string>
#include <vector>
#include "../../Time/Time.h"
#include "DataBase.h"
#include "Serialization/Serialization.h"

namespace NS_DataType
{
  template<class ContainerAllocator>
    struct Point32_: public DataBase
    {
      typedef Point32_<ContainerAllocator> Type;
    public:
      Point32_ ()
          : x (0.0), y (0.0), z (0.0)
      {
      }
      ;

      Point32_ (const ContainerAllocator& allocator)
          : x (0.0), y (0.0), z (0.0)
      {
      }
      ;

      float x, y, z;

      typedef boost::shared_ptr<Point32_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<Point32_<ContainerAllocator> const> ConstPtr;

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
  
  typedef Point32_<std::allocator<void> > Point32;
  
  typedef boost::shared_ptr<Point32> Point32Ptr;
  typedef boost::shared_ptr<Point32 const> Point32ConstPtr;

} /* namespace NS_NaviCommon */

#endif /* _POINT32_H_ */
