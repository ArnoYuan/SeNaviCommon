/*
 * Quaternion.h
 *
 *  Created on: 2016年8月23日
 *      Author: seeing
 */

#ifndef _DATATYPE_QUATERNION_H_
#define _DATATYPE_QUATERNION_H_

#include <string>
#include <vector>
#include <ostream>
#include <boost/shared_ptr.hpp>
#include "DataBase.h"
#include "Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    struct Quaternion_: public DataBase
    {
      typedef Quaternion_<ContainerAllocator> Type;

      Quaternion_ ()
          : x (0.0), y (0.0), z (0.0), w (0.0)
      {
      }
      
      Quaternion_ (const ContainerAllocator& _alloc)
          : x (0.0), y (0.0), z (0.0), w (0.0)
      {
      }
      
      typedef double _x_type, _y_type, _z_type, _w_type;

      double x, y, z, w;

      typedef boost::shared_ptr<Quaternion_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<Quaternion_<ContainerAllocator> const> ConstPtr;

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
  
  typedef Quaternion_<std::allocator<void> > Quaternion;
  
  typedef boost::shared_ptr<Quaternion> QuaternionPtr;
  typedef boost::shared_ptr<Quaternion const> QuaternionConstPtr;

} /* namespace NS_NaviCommon */

#endif /* GEOMETRY_QUATERNION_H_ */
