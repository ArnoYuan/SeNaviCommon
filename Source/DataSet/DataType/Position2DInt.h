/*
 * Position2DInt.h
 *
 *  Created on: 2016年8月18日
 *      Author: seeing
 */

#ifndef _DATATYPE_POSITION2DINT_H_
#define _DATATYPE_POSITION2DINT_H_

#include <string>
#include <vector>
#include <ostream>
#include <boost/shared_ptr.hpp>
#include "DataBase.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{

  template< class ContainerAllocator >
  //struct Position2DInt_: public DataBase
  struct Position2DInt_
  {
    typedef Position2DInt_< ContainerAllocator > Type;

    Position2DInt_()
        : x(0), y(0)
    {
    }

    Position2DInt_(const ContainerAllocator& _alloc)
        : x(0), y(0)
    {
    }

    typedef long _x_type, _y_type;

    long x, y;

    typedef boost::shared_ptr< Position2DInt_< ContainerAllocator > > Ptr;
    typedef boost::shared_ptr< Position2DInt_< ContainerAllocator > const > ConstPtr;
    /*
     public:
     virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
     {
     NS_NaviCommon::OStream stream(write_ptr, 1000000000);
     NS_NaviCommon::serialize(stream, x);
     NS_NaviCommon::serialize(stream, y);
     return stream.getData();
     }

     virtual uint8_t *deserialize(uint8_t *read_ptr)
     {
     NS_NaviCommon::IStream stream(read_ptr, 1000000000);
     NS_NaviCommon::deserialize(stream, x);
     NS_NaviCommon::deserialize(stream, y);
     return stream.getData();
     }

     virtual uint32_t serializationLength() const
     {
     uint32_t size = 0;
     size += NS_NaviCommon::serializationLength(x);
     size += NS_NaviCommon::serializationLength(y);
     return size;
     }
     */
  };

  typedef Position2DInt_< std::allocator< void > > Position2DInt;

  typedef boost::shared_ptr< Point > Position2DIntPtr;
  typedef boost::shared_ptr< Point const > Position2DIntConstPtr;

}

#endif /* _Position2DInt_H_ */
