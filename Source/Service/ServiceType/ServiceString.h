/*
 * ServiceString.h
 *
 *  Created on: 2016年10月14日
 *      Author: seeing
 */

#ifndef _SERVICETYPE_SERVICESTRING_H_
#define _SERVICETYPE_SERVICESTRING_H_

#include "ServiceBase.h"
#include "../../Serialization/Serialization.h"

namespace NS_ServiceType
{

  template< class ContainerAllocator >
  //struct ServiceString_: public ServiceBase
  struct ServiceString_
  {
    typedef ServiceString_< ContainerAllocator > Type;
  public:
    ServiceString_()
        : result(false), text()
    {
    }
    ;

    ServiceString_(const ContainerAllocator& allocator)
        : result(false), text(allocator)
    {
    }
    ;

    bool result;
    std::basic_string< char, std::char_traits< char >, typename ContainerAllocator::template rebind< char >::other > text;

    typedef boost::shared_ptr< ServiceString_< ContainerAllocator > > Ptr;
    typedef boost::shared_ptr< ServiceString_< ContainerAllocator > const > ConstPtr;
  };

  typedef ServiceString_< std::allocator< void > > ServiceString;

  typedef boost::shared_ptr< ServiceString > ServiceStringPtr;
  typedef boost::shared_ptr< ServiceString const > ServiceStringConstPtr;

}

namespace NS_NaviCommon
{
  template< class ContainerAllocator >
  struct IsFixedSize< NS_ServiceType::ServiceString_< ContainerAllocator > > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct IsFixedSize< NS_ServiceType::ServiceString_< ContainerAllocator > const > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage< NS_ServiceType::ServiceString_< ContainerAllocator > > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct IsMessage< NS_ServiceType::ServiceString_< ContainerAllocator > const > : TrueType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader< NS_ServiceType::ServiceString_< ContainerAllocator > > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct HasHeader< NS_ServiceType::ServiceString_< ContainerAllocator > const > : FalseType
  {
  };

  template< class ContainerAllocator >
  struct MD5Sum< NS_ServiceType::ServiceString_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "";
    }

    static const char*
    value(const NS_ServiceType::ServiceString_< ContainerAllocator >&)
    {
      return value();
    }
    static const uint64_t static_value1 = 0;
    static const uint64_t static_value2 = 0;
  };

  template< class ContainerAllocator >
  struct DataType< NS_ServiceType::ServiceString_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "ServiceString";
    }

    static const char*
    value(const NS_ServiceType::ServiceString_< ContainerAllocator >&)
    {
      return value();
    }
  };

  template< class ContainerAllocator >
  struct Definition< NS_ServiceType::ServiceString_< ContainerAllocator > >
  {
    static const char*
    value()
    {
      return "";
    }

    static const char*
    value(const NS_ServiceType::ServiceString_< ContainerAllocator >&)
    {
      return value();
    }
  };

} // namespace message_traits

namespace NS_NaviCommon
{

  template< class ContainerAllocator >
  struct Serializer< NS_ServiceType::ServiceString_< ContainerAllocator > >
  {
    template< typename Stream, typename T >
    inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
      stream.next(m.text);
    }

    DECLARE_ALLINONE_SERIALIZER
  }; // struct ServiceString_

}
// namespace serialization

#endif /* SERVICE_SERVICETYPE_SERVICEMAP_H_ */
