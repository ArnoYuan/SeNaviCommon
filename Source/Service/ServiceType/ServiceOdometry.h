/*
 * ServiceOdometry.h
 *
 *  Created on: 2016年10月15日
 *      Author: seeing
 */

#ifndef _SERVICETYPE_SERVICEODOMETRY_H_
#define _SERVICETYPE_SERVICEODOMETRY_H_

#include "../../DataSet/DataType/Odometry.h"
#include "ServiceBase.h"

namespace NS_ServiceType
{
  
  template<class ContainerAllocator>
  //struct ServiceOdometry_: public ServiceBase
  struct ServiceOdometry_
  {
    typedef ServiceOdometry_<ContainerAllocator> Type;
  public:
    ServiceOdometry_ ()
        : result (false), odom ()
    {
    }
    ;

    ServiceOdometry_ (const ContainerAllocator& allocator)
        : result (false), odom (allocator)
    {
    }
    ;

    bool result;
    NS_DataType::Odometry_<ContainerAllocator> odom;

    typedef boost::shared_ptr<ServiceOdometry_<ContainerAllocator> > Ptr;
    typedef boost::shared_ptr<ServiceOdometry_<ContainerAllocator> const> ConstPtr;
/*
  public:
    virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
    {
      NS_NaviCommon::OStream stream(write_ptr, 1000000000);
      NS_NaviCommon::serialize(stream, result);
      NS_NaviCommon::serialize(stream, odom);
      return stream.getData();
    }

    virtual uint8_t *deserialize(uint8_t *read_ptr)
    {
      NS_NaviCommon::IStream stream(read_ptr, 1000000000);
      NS_NaviCommon::deserialize(stream, result);
      NS_NaviCommon::deserialize(stream, odom);
      return stream.getData();
    }

    virtual uint32_t serializationLength() const
    {
      uint32_t size = 0;
      size += NS_NaviCommon::serializationLength(result);
      size += NS_NaviCommon::serializationLength(odom);
      return size;
    }
    */
  };
  
  typedef ServiceOdometry_<std::allocator<void> > ServiceOdometry;
  
  typedef boost::shared_ptr<ServiceOdometry> ServiceOdometryPtr;
  typedef boost::shared_ptr<ServiceOdometry const> ServiceOdometryConstPtr;

}

namespace NS_NaviCommon
{
template <class ContainerAllocator>
struct IsFixedSize< NS_ServiceType::ServiceOdometry_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< NS_ServiceType::ServiceOdometry_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< NS_ServiceType::ServiceOdometry_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< NS_ServiceType::ServiceOdometry_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< NS_ServiceType::ServiceOdometry_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< NS_ServiceType::ServiceOdometry_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< NS_ServiceType::ServiceOdometry_<ContainerAllocator> >
{
  static const char* value()
  {
    return "";
  }

  static const char* value(const NS_ServiceType::ServiceOdometry_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0;
  static const uint64_t static_value2 = 0;
};

template<class ContainerAllocator>
struct DataType< NS_ServiceType::ServiceOdometry_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ServiceOdometry";
  }

  static const char* value(const NS_ServiceType::ServiceOdometry_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< NS_ServiceType::ServiceOdometry_<ContainerAllocator> >
{
  static const char* value()
  {
    return "";
  }

  static const char* value(const NS_ServiceType::ServiceOdometry_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits

namespace NS_NaviCommon
{

  template<class ContainerAllocator> struct Serializer< NS_ServiceType::ServiceOdometry_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
      stream.next(m.odom);
    }

    DECLARE_ALLINONE_SERIALIZER
  }; // struct ServiceOdometry_

} // namespace serialization

#endif /* SERVICE_SERVICETYPE_SERVICEODOMETRY_H_ */
