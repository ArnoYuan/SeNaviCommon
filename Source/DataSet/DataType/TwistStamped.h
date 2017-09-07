#ifndef _DATATYPE_TWISTSTAMPED_H_
#define _DATATYPE_TWISTSTAMPED_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "Twist.h"
#include "Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    struct TwistStamped_: public DataBase
    {
      typedef TwistStamped_<ContainerAllocator> Type;
    public:
      TwistStamped_ ()
          : header (), twist ()
      {
      }
      ;

      TwistStamped_ (const ContainerAllocator& allocator)
          : header (allocator), twist (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;

      Twist_<ContainerAllocator> twist;

      typedef boost::shared_ptr<TwistStamped_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<TwistStamped_<ContainerAllocator> const> ConstPtr;

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
  
  typedef TwistStamped_<std::allocator<void> > TwistStamped;
  
  typedef boost::shared_ptr<TwistStamped> TwistStampedPtr;
  typedef boost::shared_ptr<TwistStamped const> TwistStampedConstPtr;

}

#endif /* _TWISTSTAMPED_H_ */
