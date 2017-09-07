
#ifndef _DATATYPE_POSEWITHCOVARIANCESTAMPED_H_
#define _DATATYPE_POSEWITHCOVARIANCESTAMPED_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "Pose.h"
#include "Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    struct PoseWithCovarianceStamped_: public DataBase
    {
      typedef PoseWithCovarianceStamped_<ContainerAllocator> Type;
    public:
      PoseWithCovarianceStamped_ ()
          : header (), pose ()
      {
      }
      ;

      PoseWithCovarianceStamped_ (const ContainerAllocator& allocator)
          : header (allocator), pose (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;
      Pose_<ContainerAllocator> pose;

      double covariance[36];

      typedef boost::shared_ptr<PoseWithCovarianceStamped_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<PoseWithCovarianceStamped_<ContainerAllocator> const> ConstPtr;

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
  
  typedef PoseWithCovarianceStamped_<std::allocator<void> > PoseWithCovarianceStamped;
  
  typedef boost::shared_ptr<PoseWithCovarianceStamped> PoseWithCovarianceStampedPtr;
  typedef boost::shared_ptr<PoseWithCovarianceStamped const> PoseWithCovarianceStampedConstPtr;

}

#endif /* _DATATYPE_POSEWITHCOVARIANCESTAMPED_H_ */
