#ifndef _SERIALIZATION_H_
#define _SERIALIZATION_H_

#include "../Common/MessageTraits.h"
#include "SerializedMessage.h"

#include <vector>
#include <map>

#include <boost/array.hpp>
#include <boost/call_traits.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/not.hpp>

#include <transform/transform2d.h>
#include <type/pose2d.h>
#include <sensor/lidar2d.h>
#include <type/map2d.h>
#include <type/point2d.h>
#include <type/odometry.h>
#include <type/velocity2d.h>
#include <linear-algebra/vector.h>
#include <linear-algebra/matrix.h>

#include <cstring>

/**
 * \brief Declare your serializer to use an allInOne member instead of requiring 3 different serialization
 * functions.
 *
 * The allinone method has the form:
 \verbatim
 template<typename Stream, typename T>
 inline static void allInOne(Stream& stream, T t)
 {
 stream.next(t.a);
 stream.next(t.b);
 ...
 }
 \endverbatim
 *
 * The only guarantee given is that Stream::next(T) is defined.
 */
#define DECLARE_ALLINONE_SERIALIZER \
  template<typename Stream, typename T> \
  inline static void write(Stream& stream, const T& t) \
  { \
    allInOne<Stream, const T&>(stream, t); \
  } \
  \
  template<typename Stream, typename T> \
  inline static void read(Stream& stream, T& t) \
  { \
    allInOne<Stream, T&>(stream, t); \
  } \
  \
  template<typename T> \
  inline static uint32_t serializedLength(const T& t) \
  { \
    LStream stream; \
    allInOne<LStream, const T&>(stream, t); \
    return stream.getLength(); \
  }

namespace NS_NaviCommon
{

  namespace mpl = boost::mpl;

  class StreamOverrunException: public Exception
  {
  public:
    StreamOverrunException(const std::string& what)
        : Exception(what)
    {
    }
  };

  void
  throwStreamOverrun();

  /**
   * \brief Templated serialization class.  Default implementation provides backwards compatibility with
   * old message types.
   *
   * Specializing the Serializer class is the only thing you need to do to get the ROS serialization system
   * to work with a type.
   */
  template< typename T >
  struct Serializer
  {
    /**
     * \brief Write an object to the stream.  Normally the stream passed in here will be a ros::serialization::OStream
     */
    template< typename Stream >
    inline static void write(Stream& stream,
                             typename boost::call_traits< T >::param_type t)
    {
      t.serialize(stream.getData(), 0);
    }

    /**
     * \brief Read an object from the stream.  Normally the stream passed in here will be a ros::serialization::IStream
     */
    template< typename Stream >
    inline static void read(Stream& stream,
                            typename boost::call_traits< T >::reference t)
    {
      t.deserialize(stream.getData());
    }

    /**
     * \brief Determine the serialized length of an object.
     */
    inline static uint32_t serializedLength(
        typename boost::call_traits< T >::param_type t)
    {
      return t.serializationLength();
    }
  };

  /**
   * \brief Serialize an object.  Stream here should normally be a ros::serialization::OStream
   */
  template< typename T, typename Stream >
  inline void serialize(Stream& stream, const T& t)
  {
    Serializer< T >::write(stream, t);
  }

  /**
   * \brief Deserialize an object.  Stream here should normally be a ros::serialization::IStream
   */
  template< typename T, typename Stream >
  inline void deserialize(Stream& stream, T& t)
  {
    Serializer< T >::read(stream, t);
  }

  /**
   * \brief Determine the serialized length of an object
   */
  template< typename T >
  inline uint32_t serializationLength(const T& t)
  {
    return Serializer< T >::serializedLength(t);
  }

#define CREATE_SIMPLE_SERIALIZER(Type) \
  template<> struct Serializer<Type> \
  { \
    template<typename Stream> inline static void write(Stream& stream, const Type v) \
    { \
      *reinterpret_cast<Type*>(stream.advance(sizeof(v))) = v; \
    } \
    \
    template<typename Stream> inline static void read(Stream& stream, Type& v) \
    { \
      v = *reinterpret_cast<Type*>(stream.advance(sizeof(v))); \
    } \
    \
    inline static uint32_t serializedLength(const Type&) \
    { \
      return sizeof(Type); \
    } \
  };

#define CREATE_SIMPLE_SERIALIZER_ARM(Type) \
  template<> struct Serializer<Type> \
  { \
    template<typename Stream> inline static void write(Stream& stream, const Type v) \
    { \
      memcpy(stream.advance(sizeof(v)), &v, sizeof(v) ); \
    } \
    \
    template<typename Stream> inline static void read(Stream& stream, Type& v) \
    { \
      memcpy(&v, stream.advance(sizeof(v)), sizeof(v) ); \
    } \
    \
    inline static uint32_t serializedLength(const Type&) \
      { \
      return sizeof(Type); \
    } \
};

#if defined(__arm__) || defined(__arm)
  CREATE_SIMPLE_SERIALIZER_ARM(char);
  CREATE_SIMPLE_SERIALIZER_ARM(unsigned long);
  CREATE_SIMPLE_SERIALIZER_ARM(long);

  CREATE_SIMPLE_SERIALIZER_ARM(uint8_t);
  CREATE_SIMPLE_SERIALIZER_ARM(int8_t);
  CREATE_SIMPLE_SERIALIZER_ARM(uint16_t);
  CREATE_SIMPLE_SERIALIZER_ARM(int16_t);
  CREATE_SIMPLE_SERIALIZER_ARM(uint32_t);
  CREATE_SIMPLE_SERIALIZER_ARM(int32_t);
  CREATE_SIMPLE_SERIALIZER_ARM(uint64_t);
  CREATE_SIMPLE_SERIALIZER_ARM(int64_t);
  CREATE_SIMPLE_SERIALIZER_ARM(float);
  CREATE_SIMPLE_SERIALIZER_ARM(double);
#else
  CREATE_SIMPLE_SERIALIZER(char);
  CREATE_SIMPLE_SERIALIZER(uint8_t);
  CREATE_SIMPLE_SERIALIZER(int8_t);
  CREATE_SIMPLE_SERIALIZER(uint16_t);
  CREATE_SIMPLE_SERIALIZER(int16_t);
  CREATE_SIMPLE_SERIALIZER(uint32_t);
  CREATE_SIMPLE_SERIALIZER(int32_t);
  CREATE_SIMPLE_SERIALIZER(uint64_t);
  CREATE_SIMPLE_SERIALIZER(int64_t);
  CREATE_SIMPLE_SERIALIZER(float);
  CREATE_SIMPLE_SERIALIZER(double);
#endif

  /**
   * \brief Serializer specialized for bool (serialized as uint8)
   */
  template< >
  struct Serializer< bool >
  {
    template< typename Stream >
    inline static void write(Stream& stream, const bool v)
    {
      uint8_t b = (uint8_t)v;
#if defined(__arm__) || defined(__arm)
      memcpy(stream.advance(1), &b, 1 );
#else
      *reinterpret_cast< uint8_t* >(stream.advance(1)) = b;
#endif
    }

    template< typename Stream >
    inline static void read(Stream& stream, bool& v)
    {
      uint8_t b;
#if defined(__arm__) || defined(__arm)
      memcpy(&b, stream.advance(1), 1 );
#else
      b = *reinterpret_cast< uint8_t* >(stream.advance(1));
#endif
      v = (bool)b;
    }

    inline static uint32_t serializedLength(bool)
    {
      return 1;
    }
  };

  /**
   * \brief  Serializer specialized for std::string
   */
  template< class ContainerAllocator >
  struct Serializer<
      std::basic_string< char, std::char_traits< char >, ContainerAllocator > >
  {
    typedef std::basic_string< char, std::char_traits< char >,
        ContainerAllocator > StringType;

    template< typename Stream >
    inline static void write(Stream& stream, const StringType& str)
    {
      size_t len = str.size();
      stream.next((uint32_t)len);

      if(len > 0)
      {
        memcpy(stream.advance((uint32_t)len), str.data(), len);
      }
    }

    template< typename Stream >
    inline static void read(Stream& stream, StringType& str)
    {
      uint32_t len;
      stream.next(len);
      if(len > 0)
      {
        str = StringType((char*)stream.advance(len), len);
      }
      else
      {
        str.clear();
      }
    }

    inline static uint32_t serializedLength(const StringType& str)
    {
      return 4 + (uint32_t)str.size();
    }
  };

  /**
   * \brief Serializer specialized for ros::Time
   */
  template< >
  struct Serializer< NS_NaviCommon::Time >
  {
    template< typename Stream >
    inline static void write(Stream& stream, const NS_NaviCommon::Time& v)
    {
      stream.next(v.sec);
      stream.next(v.nsec);
    }

    template< typename Stream >
    inline static void read(Stream& stream, NS_NaviCommon::Time& v)
    {
      stream.next(v.sec);
      stream.next(v.nsec);
    }

    inline static uint32_t serializedLength(const NS_NaviCommon::Time&)
    {
      return 8;
    }
  };

  /**
   * \brief Serializer specialized for ros::Duration
   */
  template< >
  struct Serializer< NS_NaviCommon::Duration >
  {
    template< typename Stream >
    inline static void write(Stream& stream, const NS_NaviCommon::Duration& v)
    {
      stream.next(v.sec);
      stream.next(v.nsec);
    }

    template< typename Stream >
    inline static void read(Stream& stream, NS_NaviCommon::Duration& v)
    {
      stream.next(v.sec);
      stream.next(v.nsec);
    }

    inline static uint32_t serializedLength(const NS_NaviCommon::Duration&)
    {
      return 8;
    }
  };

  /**
   * brief Transform2D serializer.
   */
  template< >
  struct Serializer<sgbot::tf::Transform2D>
  {
    template<typename Stream>
    inline static void write(Stream& stream, const sgbot::tf::Transform2D& transform)
    {
      float x, y, theta, scalar;

      transform.getValue(x,y,theta, scalar);

      stream.next(x);
      stream.next(y);
      stream.next(theta);
      stream.next(scalar);
    }
    template<typename Stream>
    inline static void read(Stream& stream, sgbot::tf::Transform2D& transform)
    {
      float x, y, theta, scalar;
      stream.next(x);
      stream.next(y);
      stream.next(theta);
      stream.next(scalar);
    }
    inline static uint32_t serializedLength(const sgbot::tf::Transform2D& transform)
    {
      return sizeof(float)*4;
    }
  };
/*
  template< >
  struct Serializer<sgbot::MapPointType>
  {
    template<typename Stream>
    inline static void write(Stream& stream, const sgbot::MapPointType& m)
    {
      stream.next(m);
    };

    template<typename Stream>
    inline static void read(Stream& stream, sgbot::MapPointType& m)
    {
      stream.next(m);
    }
    inline static uint32_t serializedLength(const sgbot::MapPointType& m)
    {
      return sizeof(m);
    }

  };
*/
  CREATE_SIMPLE_SERIALIZER(sgbot::MapPointType);


  template< >
  struct Serializer<sgbot::Pose2D>
  {
    template<typename Stream>
    inline static void write(Stream& stream, const sgbot::Pose2D& pose2d)
    {

      stream.next(pose2d.x());
      stream.next(pose2d.y());
      stream.next(pose2d.theta());
    }

    template<typename Stream>
    inline static void read(Stream& stream, sgbot::Pose2D& pose2d)
    {
      stream.next(pose2d.x());
      stream.next(pose2d.y());
      stream.next(pose2d.theta());
    }

    inline static uint32_t serializedLength(const sgbot::Pose2D& pose2d)
    {
      return sizeof(float)*3;
    }
  };

  template< >
  struct Serializer<sgbot::Point2D>
  {
    template<typename Stream>
    inline static void write(Stream& stream, const sgbot::Point2D& point2d)
    {
      stream.next(point2d.x());
      stream.next(point2d.y());
    }

    template<typename Stream>
    inline static void read(Stream& stream, sgbot::Point2D& point2d)
    {
      stream.next(point2d.x());
      stream.next(point2d.y());
    }


    inline static uint32_t serializedLength(const sgbot::Point2D& point2d)
    {
      return sizeof(float)*2;
    }
  };

  template< >
  struct Serializer<sgbot::Map2D>
  {
    template<typename Stream>
    inline static void write(Stream& stream, const sgbot::Map2D& map2d)
    {
      stream.next(map2d.height_);
      stream.next(map2d.width_);
      stream.next(map2d.origin_);
      //printf("points>>start\n");
      stream.next(map2d.points_);
      //printf("points>>end\n");
      stream.next(map2d.resolution_);
    }
    template<typename Stream>
    inline static void read(Stream& stream, sgbot::Map2D& map2d)
    {
      stream.next(map2d.height_);
      stream.next(map2d.width_);
      stream.next(map2d.origin_);
      stream.next(map2d.points_);
      stream.next(map2d.resolution_);
    }

    inline static uint32_t serializedLength(const sgbot::Map2D& map2d)
    {
      int vec_size = 0;
      for(int i=0;i<map2d.points_[i].size();i++)
      {
        vec_size += map2d.points_[i].size();
      }
      //return sizeof(map2d.height_)+sizeof(map2d.width_)+sizeof(float)*2+sizeof(map2d.resolution_);
      return sizeof(map2d.height_)+sizeof(map2d.width_)+sizeof(sgbot::MapPointType)*vec_size+sizeof(float)*2+sizeof(map2d.resolution_);
    }
  };

  template< >
  struct Serializer<sgbot::Velocity2D>
  {
    template<typename Stream>
    inline static void write(Stream& stream, const sgbot::Velocity2D& velocity2d)
    {
      stream.next(velocity2d.linear);
      stream.next(velocity2d.angular);
    }
    template<typename Stream>
    inline static void read(Stream& stream, sgbot::Velocity2D& velocity2d)
    {
      stream.next(velocity2d.linear);
      stream.next(velocity2d.angular);
    }
    inline static uint32_t serializedLength(const sgbot::Velocity2D& velocity2d)
    {
      return sizeof(float)*2;
    }
  };

  template< >
  struct Serializer<sgbot::Odometry>
  {
    template<typename Stream>
    inline static void write(Stream& stream, const sgbot::Odometry& odom)
    {
      stream.next(odom.pose2d);
      stream.next(odom.velocity2d);
    }

    template<typename Stream>
    inline static void read(Stream& stream, sgbot::Odometry& odom)
    {
      stream.next(odom.pose2d);
      stream.next(odom.velocity2d);
    }

    inline static uint32_t serializedLength(const sgbot::Odometry& odom)
    {
      return sizeof(float)*3+sizeof(float)*2;
    }

  };
/*
  template< >
  struct Serializer<sgbot::sensor::Lidar2D>
  {
    template<typename Stream>
    inline static void write(Stream& stream, const sgbot::sensor::Lidar2D& lidar2d)
    {

      stream.next(lidar2d.origin_);
      stream.next(lidar2d.points_);
    }

    template<typename Stream>
    inline static void read(Stream& stream, sgbot::sensor::Lidar2D& lidar2d)
    {
      stream.next(lidar2d.origin_);
      stream.next(lidar2d.points_);
    }

    inline static uint32_t serializedLength(const sgbot::sensor::Lidar2D& lidar2d)
    {
      return sizeof(lidar2d.origin_)+sizeof(lidar2d.points_);
    }
  };
*/
  /**
   * \brief Vector serializer.  Default implementation does nothing
   */
  template< typename T, class ContainerAllocator, class Enabled = void >
  struct VectorSerializer
  {
  };

  /**
   * \brief Vector serializer, specialized for non-fixed-size, non-simple types
   */
  template< typename T, class ContainerAllocator >
  struct VectorSerializer< T, ContainerAllocator,
      typename boost::disable_if< NS_NaviCommon::IsFixedSize< T > >::type >
  {
    typedef std::vector< T,
        typename ContainerAllocator::template rebind< T >::other > VecType;
    typedef typename VecType::iterator IteratorType;
    typedef typename VecType::const_iterator ConstIteratorType;

    template< typename Stream >
    inline static void write(Stream& stream, const VecType& v)
    {
      stream.next((uint32_t)v.size());
      ConstIteratorType it = v.begin();
      ConstIteratorType end = v.end();
      for(; it != end; ++it)
      {
        stream.next(*it);
      }
    }

    template< typename Stream >
    inline static void read(Stream& stream, VecType& v)
    {
      uint32_t len;
      stream.next(len);
      v.resize(len);
      IteratorType it = v.begin();
      IteratorType end = v.end();
      for(; it != end; ++it)
      {
        stream.next(*it);
      }
    }

    inline static uint32_t serializedLength(const VecType& v)
    {
      uint32_t size = 4;
      ConstIteratorType it = v.begin();
      ConstIteratorType end = v.end();
      for(; it != end; ++it)
      {
        size += serializationLength(*it);
      }

      return size;
    }
  };

  /**
   * \brief Vector serializer, specialized for fixed-size simple types
   */
  template< typename T, class ContainerAllocator >
  struct VectorSerializer< T, ContainerAllocator,
      typename boost::enable_if< NS_NaviCommon::IsSimple< T > >::type >
  {
    typedef std::vector< T,
        typename ContainerAllocator::template rebind< T >::other > VecType;
    typedef typename VecType::iterator IteratorType;
    typedef typename VecType::const_iterator ConstIteratorType;

    template< typename Stream >
    inline static void write(Stream& stream, const VecType& v)
    {
      uint32_t len = (uint32_t)v.size();
      stream.next(len);
      if(!v.empty())
      {
        const uint32_t data_len = len * (uint32_t)sizeof(T);
        memcpy(stream.advance(data_len), &v.front(), data_len);
      }
    }

    template< typename Stream >
    inline static void read(Stream& stream, VecType& v)
    {
      uint32_t len;
      stream.next(len);
      v.resize(len);

      if(len > 0)
      {
        const uint32_t data_len = (uint32_t)sizeof(T) * len;
        memcpy(&v.front(), stream.advance(data_len), data_len);
      }
    }

    inline static uint32_t serializedLength(const VecType& v)
    {
      return 4 + v.size() * (uint32_t)sizeof(T);
    }
  };

  /**
   * \brief Vector serializer, specialized for fixed-size non-simple types
   */
  template< typename T, class ContainerAllocator >
  struct VectorSerializer< T, ContainerAllocator,
      typename boost::enable_if<
          mpl::and_< NS_NaviCommon::IsFixedSize< T >,
              mpl::not_< NS_NaviCommon::IsSimple< T > > > >::type >
  {
    typedef std::vector< T,
        typename ContainerAllocator::template rebind< T >::other > VecType;
    typedef typename VecType::iterator IteratorType;
    typedef typename VecType::const_iterator ConstIteratorType;

    template< typename Stream >
    inline static void write(Stream& stream, const VecType& v)
    {
      stream.next((uint32_t)v.size());
      ConstIteratorType it = v.begin();
      ConstIteratorType end = v.end();
      for(; it != end; ++it)
      {
        stream.next(*it);
      }
    }

    template< typename Stream >
    inline static void read(Stream& stream, VecType& v)
    {
      uint32_t len;
      stream.next(len);
      v.resize(len);
      IteratorType it = v.begin();
      IteratorType end = v.end();
      for(; it != end; ++it)
      {
        stream.next(*it);
      }
    }

    inline static uint32_t serializedLength(const VecType& v)
    {
      uint32_t size = 4;
      if(!v.empty())
      {
        uint32_t len_each = serializationLength(v.front());
        size += len_each * (uint32_t)v.size();
      }

      return size;
    }
  };

  /**
   * \brief serialize version for std::vector
   */
  template< typename T, class ContainerAllocator, typename Stream >
  inline void serialize(Stream& stream,
                        const std::vector< T, ContainerAllocator >& t)
  {
    VectorSerializer< T, ContainerAllocator >::write(stream, t);
  }

  /**
   * \brief deserialize version for std::vector
   */
  template< typename T, class ContainerAllocator, typename Stream >
  inline void deserialize(Stream& stream,
                          std::vector< T, ContainerAllocator >& t)
  {
    VectorSerializer< T, ContainerAllocator >::read(stream, t);
  }

  /**
   * \brief serializationLength version for std::vector
   */
  template< typename T, class ContainerAllocator >
  inline uint32_t serializationLength(
      const std::vector< T, ContainerAllocator >& t)
  {
    return VectorSerializer< T, ContainerAllocator >::serializedLength(t);
  }

  /**
   * \brief Array serializer, default implementation does nothing
   */
  template< typename T, size_t N, class Enabled = void >
  struct ArraySerializer
  {
  };

  /**
   * \brief Array serializer, specialized for non-fixed-size, non-simple types
   */
  template< typename T, size_t N >
  struct ArraySerializer< T, N,
      typename boost::disable_if< NS_NaviCommon::IsFixedSize< T > >::type >
  {
    typedef boost::array< T, N > ArrayType;
    typedef typename ArrayType::iterator IteratorType;
    typedef typename ArrayType::const_iterator ConstIteratorType;

    template< typename Stream >
    inline static void write(Stream& stream, const ArrayType& v)
    {
      ConstIteratorType it = v.begin();
      ConstIteratorType end = v.end();
      for(; it != end; ++it)
      {
        stream.next(*it);
      }
    }

    template< typename Stream >
    inline static void read(Stream& stream, ArrayType& v)
    {
      IteratorType it = v.begin();
      IteratorType end = v.end();
      for(; it != end; ++it)
      {
        stream.next(*it);
      }
    }

    inline static uint32_t serializedLength(const ArrayType& v)
    {
      uint32_t size = 0;
      ConstIteratorType it = v.begin();
      ConstIteratorType end = v.end();
      for(; it != end; ++it)
      {
        size += serializationLength(*it);
      }

      return size;
    }
  };

  /**
   * \brief Array serializer, specialized for fixed-size, simple types
   */
  template< typename T, size_t N >
  struct ArraySerializer< T, N,
      typename boost::enable_if< NS_NaviCommon::IsSimple< T > >::type >
  {
    typedef boost::array< T, N > ArrayType;
    typedef typename ArrayType::iterator IteratorType;
    typedef typename ArrayType::const_iterator ConstIteratorType;

    template< typename Stream >
    inline static void write(Stream& stream, const ArrayType& v)
    {
      const uint32_t data_len = N * sizeof(T);
      memcpy(stream.advance(data_len), &v.front(), data_len);
    }

    template< typename Stream >
    inline static void read(Stream& stream, ArrayType& v)
    {
      const uint32_t data_len = N * sizeof(T);
      memcpy(&v.front(), stream.advance(data_len), data_len);
    }

    inline static uint32_t serializedLength(const ArrayType&)
    {
      return N * sizeof(T);
    }
  };

  /**
   * \brief Array serializer, specialized for fixed-size, non-simple types
   */
  template< typename T, size_t N >
  struct ArraySerializer< T, N,
      typename boost::enable_if<
          mpl::and_< NS_NaviCommon::IsFixedSize< T >,
              mpl::not_< NS_NaviCommon::IsSimple< T > > > >::type >
  {
    typedef boost::array< T, N > ArrayType;
    typedef typename ArrayType::iterator IteratorType;
    typedef typename ArrayType::const_iterator ConstIteratorType;

    template< typename Stream >
    inline static void write(Stream& stream, const ArrayType& v)
    {
      ConstIteratorType it = v.begin();
      ConstIteratorType end = v.end();
      for(; it != end; ++it)
      {
        stream.next(*it);
      }
    }

    template< typename Stream >
    inline static void read(Stream& stream, ArrayType& v)
    {
      IteratorType it = v.begin();
      IteratorType end = v.end();
      for(; it != end; ++it)
      {
        stream.next(*it);
      }
    }

    inline static uint32_t serializedLength(const ArrayType& v)
    {
      return serializationLength(v.front()) * N;
    }
  };

  /**
   * \brief serialize version for boost::array
   */
  template< typename T, size_t N, typename Stream >
  inline void serialize(Stream& stream, const boost::array< T, N >& t)
  {
    ArraySerializer< T, N >::write(stream, t);
  }

  /**
   * \brief deserialize version for boost::array
   */
  template< typename T, size_t N, typename Stream >
  inline void deserialize(Stream& stream, boost::array< T, N >& t)
  {
    ArraySerializer< T, N >::read(stream, t);
  }

  /**
   * \brief serializationLength version for boost::array
   */
  template< typename T, size_t N >
  inline uint32_t serializationLength(const boost::array< T, N >& t)
  {
    return ArraySerializer< T, N >::serializedLength(t);
  }

  /**
   * \brief Enum
   */
  namespace stream_types
  {
    enum StreamType
    {
      Input,
      Output,
      Length
    };
  }
  typedef stream_types::StreamType StreamType;

  /**
   * \brief Stream base-class, provides common functionality for IStream and OStream
   */
  struct Stream
  {
    /*
     * \brief Returns a pointer to the current position of the stream
     */
    inline uint8_t*
    getData()
    {
      return data_;
    }
    /**
     * \brief Advances the stream, checking bounds, and returns a pointer to the position before it
     * was advanced.
     * \throws StreamOverrunException if len would take this stream past the end of its buffer
     */
    uint8_t*
    advance(uint32_t len)
    {
      uint8_t* old_data = data_;
      data_ += len;
      if(data_ > end_)
      {
        // Throwing directly here causes a significant speed hit due to the extra code generated
        // for the throw statement
        throwStreamOverrun();
      }
      return old_data;
    }

    /**
     * \brief Returns the amount of space left in the stream
     */
    inline uint32_t getLength()
    {
      return (uint32_t)(end_ - data_);
    }

  protected:
    Stream(uint8_t* _data, uint32_t _count)
        : data_(_data), end_(_data + _count)
    {
    }

  private:
    uint8_t* data_;
    uint8_t* end_;
  };

  /**
   * \brief Input stream
   */
  struct IStream: public Stream
  {
    static const StreamType stream_type = stream_types::Input;

    IStream(uint8_t* data, uint32_t count)
        : Stream(data, count)
    {
    }

    /**
     * \brief Deserialize an item from this input stream
     */
    template< typename T >
    void next(T& t)
    {
      deserialize(*this, t);
    }

    template< typename T >
    IStream&
    operator>>(T& t)
    {
      deserialize(*this, t);
      return *this;
    }
  };

  /**
   * \brief Output stream
   */
  struct OStream: public Stream
  {
    static const StreamType stream_type = stream_types::Output;

    OStream(uint8_t* data, uint32_t count)
        : Stream(data, count)
    {
    }

    /**
     * \brief Serialize an item to this output stream
     */
    template< typename T >
    void next(const T& t)
    {
      serialize(*this, t);
    }

    template< typename T >
    OStream&
    operator<<(const T& t)
    {
      serialize(*this, t);
      return *this;
    }
  };

  /**
   * \brief Length stream
   *
   * LStream is not what you would normally think of as a stream, but it is used in order to support
   * allinone serializers.
   */
  struct LStream
  {
    static const StreamType stream_type = stream_types::Length;

    LStream()
        : count_(0)
    {
    }

    /**
     * \brief Add the length of an item to this length stream
     */
    template< typename T >
    void next(const T& t)
    {
      count_ += serializationLength(t);
    }

    /**
     * \brief increment the length by len
     */
    uint32_t advance(uint32_t len)
    {
      uint32_t old = count_;
      count_ += len;
      return old;
    }

    /**
     * \brief Get the total length of this tream
     */
    inline uint32_t getLength()
    {
      return count_;
    }

  private:
    uint32_t count_;
  };

  /**
   * \brief Serialize a message
   */
  template< typename M >
  inline SerializedMessage serializeMessage(const M& message)
  {
    SerializedMessage m;
    uint32_t len = serializationLength(message);
    m.num_bytes = len + 4;
    m.buf.reset(new uint8_t[m.num_bytes]);

    OStream s(m.buf.get(), (uint32_t)m.num_bytes);
    serialize(s, (uint32_t)m.num_bytes - 4);
    m.message_start = s.getData();
    serialize(s, message);

    return m;
  }

  /**
   * \brief Serialize a service response
   */
  template< typename M >
  inline SerializedMessage serializeServiceResponse(bool ok, const M& message)
  {
    SerializedMessage m;

    if(ok)
    {
      uint32_t len = serializationLength(message);
      m.num_bytes = len + 5;
      m.buf.reset(new uint8_t[m.num_bytes]);

      OStream s(m.buf.get(), (uint32_t)m.num_bytes);
      serialize(s, (uint8_t)ok);
      serialize(s, (uint32_t)m.num_bytes - 5);
      serialize(s, message);
    }
    else
    {
      uint32_t len = serializationLength(message);
      m.num_bytes = len + 1;
      m.buf.reset(new uint8_t[m.num_bytes]);

      OStream s(m.buf.get(), (uint32_t)m.num_bytes);
      serialize(s, (uint8_t)ok);
      serialize(s, message);
    }

    return m;
  }

  /**
   * \brief Deserialize a message.  If includes_length is true, skips the first 4 bytes
   */
  template< typename M >
  inline void deserializeMessage(const SerializedMessage& m, M& message)
  {
    IStream s(m.message_start, m.num_bytes - (m.message_start - m.buf.get()));
    deserialize(s, message);
  }

// Additional serialization traits

  template< typename M >
  struct PreDeserializeParams
  {
    boost::shared_ptr< M > message;
    boost::shared_ptr< std::map< std::string, std::string > > connection_header;
  };

  /**
   * \brief called by the SubscriptionCallbackHelper after a message is
   * instantiated but before that message is deserialized
   */
  template< typename M >
  struct PreDeserialize
  {
    static void notify(const PreDeserializeParams< M >&)
    {
    }
  };

}

#endif
