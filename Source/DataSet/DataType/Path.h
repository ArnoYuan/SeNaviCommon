/*
 * Path.h
 *
 *  Created on: 2016年12月12日
 *      Author: seeing
 */

#ifndef _DATATYPE_PATH_H_
#define _DATATYPE_PATH_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "PoseStamped.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    struct Path_: public DataBase
    {
      typedef Path_<ContainerAllocator> Type;
    public:
      Path_ ()
          : header (), poses ()
      {
      }
      ;

      Path_ (const ContainerAllocator& allocator)
          : header (allocator), poses (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;
      std::vector<PoseStamped_<ContainerAllocator>,
          typename ContainerAllocator::template rebind<
              PoseStamped_<ContainerAllocator> >::other> poses;

      typedef boost::shared_ptr<Path_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<Path_<ContainerAllocator> const> ConstPtr;

    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, header);
        NS_NaviCommon::serialize(stream, poses);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, header);
        NS_NaviCommon::deserialize(stream, poses);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(header);
        size += NS_NaviCommon::serializationLength(poses);
        return size;
      }
    };
  
  typedef Path_<std::allocator<void> > Path;
  
  typedef boost::shared_ptr<Path> PathPtr;
  typedef boost::shared_ptr<Path const> PathConstPtr;

}

#endif /* DATASET_DATATYPE_PATH_H_ */
