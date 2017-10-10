/*
 * ServiceMap.h
 *
 *  Created on: 2016年10月14日
 *      Author: seeing
 */

#ifndef _SERVICETYPE_SERVICEMAP_H_
#define _SERVICETYPE_SERVICEMAP_H_

#include "../../DataSet/DataType/OccupancyGrid.h"
#include "ServiceBase.h"

namespace NS_ServiceType
{
  
  template<class ContainerAllocator>
  //struct ServiceMap_: public ServiceBase
  struct ServiceMap_
  {
    typedef ServiceMap_<ContainerAllocator> Type;
  public:
    ServiceMap_ ()
        : result (false), map ()
    {
    }
    ;

    ServiceMap_ (const ContainerAllocator& allocator)
        : result (false), map (allocator)
    {
    }
    ;

    bool result;
    NS_DataType::OccupancyGrid_<ContainerAllocator> map;

    typedef boost::shared_ptr<ServiceMap_<ContainerAllocator> > Ptr;
    typedef boost::shared_ptr<ServiceMap_<ContainerAllocator> const> ConstPtr;
/*
  public:
    virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
    {
      NS_NaviCommon::OStream stream(write_ptr, 1000000000);
      NS_NaviCommon::serialize(stream, result);
      NS_NaviCommon::serialize(stream, map);
      return stream.getData();
    }

    virtual uint8_t *deserialize(uint8_t *read_ptr)
    {
      NS_NaviCommon::IStream stream(read_ptr, 1000000000);
      NS_NaviCommon::deserialize(stream, result);
      NS_NaviCommon::deserialize(stream, map);
      return stream.getData();
    }

    virtual uint32_t serializationLength() const
    {
      uint32_t size = 0;
      size += NS_NaviCommon::serializationLength(result);
      size += NS_NaviCommon::serializationLength(map);
      return size;
    }
    */
  };
  
  typedef ServiceMap_<std::allocator<void> > ServiceMap;
  
  typedef boost::shared_ptr<ServiceMap> ServiceMapPtr;
  typedef boost::shared_ptr<ServiceMap const> ServiceMapConstPtr;

}

namespace NS_NaviCommon
{
template <class ContainerAllocator>
struct IsFixedSize< NS_ServiceType::ServiceMap_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< NS_ServiceType::ServiceMap_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< NS_ServiceType::ServiceMap_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< NS_ServiceType::ServiceMap_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< NS_ServiceType::ServiceMap_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< NS_ServiceType::ServiceMap_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< NS_ServiceType::ServiceMap_<ContainerAllocator> >
{
  static const char* value()
  {
    return "";
  }

  static const char* value(const NS_ServiceType::ServiceMap_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0;
  static const uint64_t static_value2 = 0;
};

template<class ContainerAllocator>
struct DataType< NS_ServiceType::ServiceMap_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ServiceMap";
  }

  static const char* value(const NS_ServiceType::ServiceMap_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< NS_ServiceType::ServiceMap_<ContainerAllocator> >
{
  static const char* value()
  {
    return "";
  }

  static const char* value(const NS_ServiceType::ServiceMap_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits

namespace NS_NaviCommon
{

  template<class ContainerAllocator> struct Serializer< NS_ServiceType::ServiceMap_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
      stream.next(m.map);
    }

    DECLARE_ALLINONE_SERIALIZER
  }; // struct ServiceMap_

} // namespace serialization

#endif /* SERVICE_SERVICETYPE_SERVICEMAP_H_ */
