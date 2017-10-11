/*
 * OccupancyGrid.h
 *
 *  Created on: 2016年10月14日
 *      Author: seeing
 */

#ifndef _DATATYPE_OCCUPANCYGRID_H_
#define _DATATYPE_OCCUPANCYGRID_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "MapMetaData.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  template<class ContainerAllocator>
    //struct OccupancyGrid_: public DataBase
    struct OccupancyGrid_
    {
      typedef OccupancyGrid_<ContainerAllocator> Type;
    public:
      OccupancyGrid_ ()
          : header (), info (), data ()
      {
      }
      ;

      OccupancyGrid_ (const ContainerAllocator& allocator)
          : header (allocator), info (allocator), data (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;
      MapMetaData_<ContainerAllocator> info;

      std::vector<char,
          typename ContainerAllocator::template rebind<char>::other> data;

      typedef boost::shared_ptr<OccupancyGrid_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<OccupancyGrid_<ContainerAllocator> const> ConstPtr;
      /*
       public:
       virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
       {
       NS_NaviCommon::OStream stream(write_ptr, 1000000000);
       NS_NaviCommon::serialize(stream, header);
       NS_NaviCommon::serialize(stream, info);
       NS_NaviCommon::serialize(stream, data);
       return stream.getData();
       }

       virtual uint8_t *deserialize(uint8_t *read_ptr)
       {
       NS_NaviCommon::IStream stream(read_ptr, 1000000000);
       NS_NaviCommon::deserialize(stream, header);
       NS_NaviCommon::deserialize(stream, info);
       NS_NaviCommon::deserialize(stream, data);
       return stream.getData();
       }

       virtual uint32_t serializationLength() const
       {
       uint32_t size = 0;
       size += NS_NaviCommon::serializationLength(header);
       size += NS_NaviCommon::serializationLength(info);
       size += NS_NaviCommon::serializationLength(data);
       return size;
       }
       */
    };
  
  typedef OccupancyGrid_<std::allocator<void> > OccupancyGrid;
  
  typedef boost::shared_ptr<OccupancyGrid> OccupancyGridPtr;
  typedef boost::shared_ptr<OccupancyGrid const> OccupancyGridConstPtr;

}

namespace NS_NaviCommon
{
  
// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'nav_msgs': ['/tmp/binarydeb/ros-kinetic-nav-msgs-1.12.5/msg', '/tmp/binarydeb/ros-kinetic-nav-msgs-1.12.5/obj-x86_64-linux-gnu/devel/share/nav_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}
  
// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']
  
  template<class ContainerAllocator>
    struct IsFixedSize<NS_DataType::OccupancyGrid_<ContainerAllocator> > : FalseType
    {
    };
  
  template<class ContainerAllocator>
    struct IsFixedSize<NS_DataType::OccupancyGrid_<ContainerAllocator> const> : FalseType
    {
    };
  
  template<class ContainerAllocator>
    struct IsMessage<NS_DataType::OccupancyGrid_<ContainerAllocator> > : TrueType
    {
    };
  
  template<class ContainerAllocator>
    struct IsMessage<NS_DataType::OccupancyGrid_<ContainerAllocator> const> : TrueType
    {
    };
  
  template<class ContainerAllocator>
    struct HasHeader<NS_DataType::OccupancyGrid_<ContainerAllocator> > : TrueType
    {
    };
  
  template<class ContainerAllocator>
    struct HasHeader<NS_DataType::OccupancyGrid_<ContainerAllocator> const> : TrueType
    {
    };
  
  template<class ContainerAllocator>
    struct MD5Sum<NS_DataType::OccupancyGrid_<ContainerAllocator> >
    {
      static const char*
      value ()
      {
        return "3381f2d731d4076ec5c71b0759edbe4e";
      }
      
      static const char*
      value (const NS_DataType::OccupancyGrid_<ContainerAllocator>&)
      {
        return value ();
      }
      static const uint64_t static_value1 = 0x3381f2d731d4076eULL;
      static const uint64_t static_value2 = 0xc5c71b0759edbe4eULL;
    };
  
  template<class ContainerAllocator>
    struct DataType<NS_DataType::OccupancyGrid_<ContainerAllocator> >
    {
      static const char*
      value ()
      {
        return "nav_msgs/OccupancyGrid";
      }
      
      static const char*
      value (const NS_DataType::OccupancyGrid_<ContainerAllocator>&)
      {
        return value ();
      }
    };
  
  template<class ContainerAllocator>
    struct Definition<NS_DataType::OccupancyGrid_<ContainerAllocator> >
    {
      static const char*
      value ()
      {
        return "# This represents a 2-D grid map, in which each cell represents the probability of\n\
# occupancy.\n\
\n\
Header header \n\
\n\
#MetaData for the map\n\
MapMetaData info\n\
\n\
# The map data, in row-major order, starting with (0,0).  Occupancy\n\
# probabilities are in the range [0,100].  Unknown is -1.\n\
int8[] data\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: nav_msgs/MapMetaData\n\
# This hold basic information about the characterists of the OccupancyGrid\n\
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
      value (const NS_DataType::OccupancyGrid_<ContainerAllocator>&)
      {
        return value ();
      }
    };

} // namespace message_traits

namespace NS_NaviCommon
{
  template<class ContainerAllocator>
    struct Serializer<NS_DataType::OccupancyGrid_<ContainerAllocator> >
    {
      template<typename Stream, typename T>
        inline static void
        allInOne (Stream& stream, T m)
        {
          stream.next (m.header);
          stream.next (m.info);
          stream.next (m.data);
        }
      
      DECLARE_ALLINONE_SERIALIZER}; // struct OccupancyGrid_
    
  }
  // namespace serialization
  
#endif /* DATASET_DATATYPE_OCCUPANCYGRID_H_ */
