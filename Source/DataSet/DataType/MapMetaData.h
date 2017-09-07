/*
 * MapMetaData.h
 *
 *  Created on: 2016年10月13日
 *      Author: seeing
 */

#ifndef _DATATYPE_MAPMETADATA_H_
#define _DATATYPE_MAPMETADATA_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "Pose.h"
#include "Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    struct MapMetaData_: public DataBase
    {
      typedef MapMetaData_<ContainerAllocator> Type;
    public:
      MapMetaData_ ()
          : map_load_time (), resolution (0.0), width (0), height (0), origin ()
      {
      }
      ;

      MapMetaData_ (const ContainerAllocator& allocator)
          : map_load_time (), resolution (0.0), width (0), height (0),
              origin (allocator)
      {
      }
      ;

      NS_NaviCommon::Time map_load_time;
      float resolution;
      int width;
      int height;

      Pose_<ContainerAllocator> origin;

      typedef boost::shared_ptr<MapMetaData_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<MapMetaData_<ContainerAllocator> const> ConstPtr;

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
  
  typedef MapMetaData_<std::allocator<void> > MapMetaData;
  
  typedef boost::shared_ptr<MapMetaData> MapMetaDataPtr;
  typedef boost::shared_ptr<MapMetaData const> MapMetaDataConstPtr;

}

#endif /* DATASET_DATATYPE_MAPMETADATA_H_ */
