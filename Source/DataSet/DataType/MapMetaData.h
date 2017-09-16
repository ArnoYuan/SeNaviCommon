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
#include "../../Serialization/Serialization.h"

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
        NS_NaviCommon::serialize(stream, map_load_time);
        NS_NaviCommon::serialize(stream, resolution);
        NS_NaviCommon::serialize(stream, width);
        NS_NaviCommon::serialize(stream, height);
        NS_NaviCommon::serialize(stream, origin);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, map_load_time);
        NS_NaviCommon::deserialize(stream, resolution);
        NS_NaviCommon::deserialize(stream, width);
        NS_NaviCommon::deserialize(stream, height);
        NS_NaviCommon::deserialize(stream, origin);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(map_load_time);
        size += NS_NaviCommon::serializationLength(resolution);
        size += NS_NaviCommon::serializationLength(width);
        size += NS_NaviCommon::serializationLength(height);
        size += NS_NaviCommon::serializationLength(origin);
        return size;
      }
    };
  
  typedef MapMetaData_<std::allocator<void> > MapMetaData;
  
  typedef boost::shared_ptr<MapMetaData> MapMetaDataPtr;
  typedef boost::shared_ptr<MapMetaData const> MapMetaDataConstPtr;

}

#endif /* DATASET_DATATYPE_MAPMETADATA_H_ */
