/*
 * LaserScan.h
 *
 *  Created on: 2016年9月28日
 *      Author: seeing
 */

#ifndef _DATATYPE_LASERSCAN_H_
#define _DATATYPE_LASERSCAN_H_

#include "DataBase.h"
#include "DataHeader.h"
#include "../../Serialization/Serialization.h"

namespace NS_DataType
{
  
  template<class ContainerAllocator>
    //struct LaserScan_: public DataBase
    struct LaserScan_
    {
      typedef LaserScan_<ContainerAllocator> Type;
    public:
      LaserScan_ ()
          : header (), angle_min (0.0), angle_max (0.0), angle_increment (0.0),
              time_increment (0.0), scan_time (0.0), range_min (0.0),
              range_max (0.0), ranges (), intensities ()
      {
      }
      ;

      LaserScan_ (const ContainerAllocator& allocator)
          : header (allocator), angle_min (0.0), angle_max (0.0),
              angle_increment (0.0), time_increment (0.0), scan_time (0.0),
              range_min (0.0), range_max (0.0), ranges (allocator),
              intensities (allocator)
      {
      }
      ;

      DataHeader_<ContainerAllocator> header;
      float angle_min;
      float angle_max;
      float angle_increment;
      float time_increment;
      float scan_time;
      float range_min;
      float range_max;

      std::vector<float,
          typename ContainerAllocator::template rebind<float>::other> ranges;
      std::vector<float,
          typename ContainerAllocator::template rebind<float>::other> intensities;

      typedef boost::shared_ptr<LaserScan_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr<LaserScan_<ContainerAllocator> const> ConstPtr;
/*
    public:
      virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
      {
        NS_NaviCommon::OStream stream(write_ptr, 1000000000);
        NS_NaviCommon::serialize(stream, header);
        NS_NaviCommon::serialize(stream, angle_min);
        NS_NaviCommon::serialize(stream, angle_max);
        NS_NaviCommon::serialize(stream, angle_increment);
        NS_NaviCommon::serialize(stream, time_increment);
        NS_NaviCommon::serialize(stream, scan_time);
        NS_NaviCommon::serialize(stream, range_min);
        NS_NaviCommon::serialize(stream, range_max);
        NS_NaviCommon::serialize(stream, ranges);
        NS_NaviCommon::serialize(stream, intensities);
        return stream.getData();
      }

      virtual uint8_t *deserialize(uint8_t *read_ptr)
      {
        NS_NaviCommon::IStream stream(read_ptr, 1000000000);
        NS_NaviCommon::deserialize(stream, header);
        NS_NaviCommon::deserialize(stream, angle_min);
        NS_NaviCommon::deserialize(stream, angle_max);
        NS_NaviCommon::deserialize(stream, angle_increment);
        NS_NaviCommon::deserialize(stream, time_increment);
        NS_NaviCommon::deserialize(stream, scan_time);
        NS_NaviCommon::deserialize(stream, range_min);
        NS_NaviCommon::deserialize(stream, range_max);
        NS_NaviCommon::deserialize(stream, ranges);
        NS_NaviCommon::deserialize(stream, intensities);
        return stream.getData();
      }

      virtual uint32_t serializationLength() const
      {
        uint32_t size = 0;
        size += NS_NaviCommon::serializationLength(header);
        size += NS_NaviCommon::serializationLength(angle_min);
        size += NS_NaviCommon::serializationLength(angle_max);
        size += NS_NaviCommon::serializationLength(angle_increment);
        size += NS_NaviCommon::serializationLength(time_increment);
        size += NS_NaviCommon::serializationLength(scan_time);
        size += NS_NaviCommon::serializationLength(range_min);
        size += NS_NaviCommon::serializationLength(range_max);
        size += NS_NaviCommon::serializationLength(ranges);
        size += NS_NaviCommon::serializationLength(intensities);
        return size;
      }
*/
    };
  
  typedef LaserScan_<std::allocator<void> > LaserScan;
  
  typedef boost::shared_ptr<LaserScan> LaserScanPtr;
  typedef boost::shared_ptr<LaserScan const> LaserScanConstPtr;
}


namespace NS_NaviCommon
{

// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'sensor_msgs': ['/tmp/binarydeb/ros-kinetic-sensor-msgs-1.12.5/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< NS_DataType::LaserScan_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< NS_DataType::LaserScan_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< NS_DataType::LaserScan_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< NS_DataType::LaserScan_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< NS_DataType::LaserScan_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< NS_DataType::LaserScan_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< NS_DataType::LaserScan_<ContainerAllocator> >
{
  static const char* value()
  {
    return "90c7ef2dc6895d81024acba2ac42f369";
  }

  static const char* value(const NS_DataType::LaserScan_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x90c7ef2dc6895d81ULL;
  static const uint64_t static_value2 = 0x024acba2ac42f369ULL;
};

template<class ContainerAllocator>
struct DataType< NS_DataType::LaserScan_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sensor_msgs/LaserScan";
  }

  static const char* value(const NS_DataType::LaserScan_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< NS_DataType::LaserScan_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Single scan from a planar laser range-finder\n\
#\n\
# If you have another ranging device with different behavior (e.g. a sonar\n\
# array), please find or create a different message, since applications\n\
# will make fairly laser-specific assumptions about this data\n\
\n\
Header header            # timestamp in the header is the acquisition time of \n\
                         # the first ray in the scan.\n\
                         #\n\
                         # in frame frame_id, angles are measured around \n\
                         # the positive Z axis (counterclockwise, if Z is up)\n\
                         # with zero angle being forward along the x axis\n\
                         \n\
float32 angle_min        # start angle of the scan [rad]\n\
float32 angle_max        # end angle of the scan [rad]\n\
float32 angle_increment  # angular distance between measurements [rad]\n\
\n\
float32 time_increment   # time between measurements [seconds] - if your scanner\n\
                         # is moving, this will be used in interpolating position\n\
                         # of 3d points\n\
float32 scan_time        # time between scans [seconds]\n\
\n\
float32 range_min        # minimum range value [m]\n\
float32 range_max        # maximum range value [m]\n\
\n\
float32[] ranges         # range data [m] (Note: values < range_min or > range_max should be discarded)\n\
float32[] intensities    # intensity data [device-specific units].  If your\n\
                         # device does not provide intensities, please leave\n\
                         # the array empty.\n\
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
";
  }

  static const char* value(const NS_DataType::LaserScan_<ContainerAllocator>&) { return value(); }
};
}

namespace NS_NaviCommon
{
  template<class ContainerAllocator> struct Serializer< NS_DataType::LaserScan_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.angle_min);
      stream.next(m.angle_max);
      stream.next(m.angle_increment);
      stream.next(m.time_increment);
      stream.next(m.scan_time);
      stream.next(m.range_min);
      stream.next(m.range_max);
      stream.next(m.ranges);
      stream.next(m.intensities);
    }

    DECLARE_ALLINONE_SERIALIZER
  }; // struct LaserScan_
}


#endif /* _LASERSCAN_H_ */
