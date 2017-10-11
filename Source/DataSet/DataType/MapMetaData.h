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
    //struct MapMetaData_: public DataBase
    struct MapMetaData_
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
      int16_t width;
      int16_t height;

      Pose_<ContainerAllocator> origin;

      typedef boost::shared_ptr<MapMetaData_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<MapMetaData_<ContainerAllocator> const> ConstPtr;
      /*
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
       */

    };
  
  typedef MapMetaData_<std::allocator<void> > MapMetaData;
  
  typedef boost::shared_ptr<MapMetaData> MapMetaDataPtr;
  typedef boost::shared_ptr<MapMetaData const> MapMetaDataConstPtr;

}

namespace NS_NaviCommon
{
  
// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/tmp/binarydeb/ros-kinetic-nav-msgs-1.12.5/msg', '/tmp/binarydeb/ros-kinetic-nav-msgs-1.12.5/obj-x86_64-linux-gnu/devel/share/nav_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}
  
// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']
  
  template<class ContainerAllocator>
    struct IsFixedSize<NS_DataType::MapMetaData_<ContainerAllocator> > : TrueType
    {
    };
  
  template<class ContainerAllocator>
    struct IsFixedSize<NS_DataType::MapMetaData_<ContainerAllocator> const> : TrueType
    {
    };
  
  template<class ContainerAllocator>
    struct IsMessage<NS_DataType::MapMetaData_<ContainerAllocator> > : TrueType
    {
    };
  
  template<class ContainerAllocator>
    struct IsMessage<NS_DataType::MapMetaData_<ContainerAllocator> const> : TrueType
    {
    };
  
  template<class ContainerAllocator>
    struct HasHeader<NS_DataType::MapMetaData_<ContainerAllocator> > : FalseType
    {
    };
  
  template<class ContainerAllocator>
    struct HasHeader<NS_DataType::MapMetaData_<ContainerAllocator> const> : FalseType
    {
    };
  
  template<class ContainerAllocator>
    struct MD5Sum<NS_DataType::MapMetaData_<ContainerAllocator> >
    {
      static const char*
      value ()
      {
        return "10cfc8a2818024d3248802c00c95f11b";
      }
      
      static const char*
      value (const NS_DataType::MapMetaData_<ContainerAllocator>&)
      {
        return value ();
      }
      static const uint64_t static_value1 = 0x10cfc8a2818024d3ULL;
      static const uint64_t static_value2 = 0x248802c00c95f11bULL;
    };
  
  template<class ContainerAllocator>
    struct DataType<NS_DataType::MapMetaData_<ContainerAllocator> >
    {
      static const char*
      value ()
      {
        return "nav_msgs/MapMetaData";
      }
      
      static const char*
      value (const NS_DataType::MapMetaData_<ContainerAllocator>&)
      {
        return value ();
      }
    };
  
  template<class ContainerAllocator>
    struct Definition<NS_DataType::MapMetaData_<ContainerAllocator> >
    {
      static const char*
      value ()
      {
        return "# This hold basic information about the characterists of the OccupancyGrid\n\
\n\
# The time at which the map was loaded\n\
time map_load_time\n\
# The map resolution [m/cell]\n\
float32 resolution\n\
# Map width [cells]\n\
uint32 width\n\
# Map height [cells]\n\
uint32 height\n\
# The origin of the map [m, m, rad].  This is the real-world pose of the\n\
# cell (0,0) in the map.\n\
geometry_msgs/Pose origin\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
      }
      
      static const char*
      value (const NS_DataType::MapMetaData_<ContainerAllocator>&)
      {
        return value ();
      }
    };

} // namespace message_traits

namespace NS_NaviCommon
{
  
  template<class ContainerAllocator>
    struct Serializer<NS_DataType::MapMetaData_<ContainerAllocator> >
    {
      template<typename Stream, typename T>
        inline static void
        allInOne (Stream& stream, T m)
        {
          stream.next (m.map_load_time);
          stream.next (m.resolution);
          stream.next (m.width);
          stream.next (m.height);
          stream.next (m.origin);
        }
      
      DECLARE_ALLINONE_SERIALIZER}; // struct MapMetaData_
    
  }
  // namespace serialization
  
#endif /* DATASET_DATATYPE_MAPMETADATA_H_ */
