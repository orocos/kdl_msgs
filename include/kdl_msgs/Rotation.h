#ifndef KDL_MSGS_MESSAGE_ROTATION_H
#define KDL_MSGS_MESSAGE_ROTATION_H

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <kdl/frames.hpp>

#include <kdl_msgs/util/forward_traits.h>
#include <kdl_msgs/util/serialization.h>

namespace kdl_msgs
{
#ifndef BOOST_NO_CXX11_TEMPLATE_ALIASES
// using C++11 syntax ::KDL::Rotation and kdl_msgs::Rotation_ are exactly the same type
template <typename ContainerAllocator> using Rotation_ = ::KDL::Rotation;
#else
template <class ContainerAllocator>
struct Rotation_ : public ::KDL::Rotation
{
  typedef Rotation_<ContainerAllocator> Type;
  typedef double value_type;

  Rotation_()
  {}
  Rotation_(const ContainerAllocator&)
  {}
  Rotation_(value_type Xx, value_type Yx, value_type Zx,
            value_type Xy, value_type Yy, value_type Zy,
            value_type Xz, value_type Yz, value_type Zz)
    : ::KDL::Rotation(Xx, Yx, Zx, Xy, Yy, Zy, Xz, Yx, Zz)
  {}
  Rotation_(const ::KDL::Vector& x, const ::KDL::Vector& y, const ::KDL::Vector& z)
    : ::KDL::Rotation(x, y, z)
  {}
  Rotation_(const value_type (&array)[9])
    : ::KDL::Rotation(array[0], array[1], array[2],
                      array[3], array[4], array[5],
                      array[6], array[7], array[8])
  {}
  Rotation_(const ::KDL::Rotation& other)
    : ::KDL::Rotation(other)
  {}

  // assignment operator
  Type& operator=(const Type& rhs)
  {
    static_cast< ::KDL::Rotation&>(*this) = rhs;
    return *this;
  }
  Type& operator=(const ::KDL::Rotation& rhs)
  {
    static_cast< ::KDL::Rotation&>(*this) = rhs;
    return *this;
  }

  typedef value_type _data_type[9];

  typedef boost::shared_ptr< ::kdl_msgs::Rotation_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kdl_msgs::Rotation_<ContainerAllocator> const> ConstPtr;

}; // struct Rotation_
#endif

typedef ::kdl_msgs::Rotation_<std::allocator<void> > Rotation;

typedef boost::shared_ptr< ::kdl_msgs::Rotation > RotationPtr;
typedef boost::shared_ptr< ::kdl_msgs::Rotation const> RotationConstPtr;

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kdl_msgs::Rotation_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kdl_msgs::Rotation_<ContainerAllocator> >::stream(s, "", v);
return s;
}
#endif

} // namespace kdl_msgs

namespace ros
{
namespace message_traits
{

template <>
struct IsFixedSize< ::KDL::Rotation >
  : TrueType
  { };

template <>
struct IsFixedSize< ::KDL::Rotation const>
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Rotation >
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Rotation const>
  : TrueType
  { };

template <>
struct HasHeader< ::KDL::Rotation >
  : FalseType
  { };

template <>
struct HasHeader< ::KDL::Rotation const>
  : FalseType
  { };


template<>
struct MD5Sum< ::KDL::Rotation >
{
  static const char* value()
  {
    return "ca66b32e4ad9de837a30ea9fe5ade752";
  }

  static const char* value(const ::KDL::Rotation&) { return value(); }
  static const uint64_t static_value1 = 0xca66b32e4ad9de83ULL;
  static const uint64_t static_value2 = 0x7a30ea9fe5ade752ULL;
};

template<>
struct DataType< ::KDL::Rotation >
{
  static const char* value()
  {
    return "kdl_msgs/Rotation";
  }

  static const char* value(const ::KDL::Rotation&) { return value(); }
};

template<>
struct Definition< ::KDL::Rotation >
{
  static const char* value()
  {
    return "# Represents a KDL::Rotation instance.\n\
\n\
float64[9] data\n\
";
  }

  static const char* value(const ::KDL::Rotation&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<> struct Serializer< ::KDL::Rotation >
  {
    template<typename Stream, typename T>
    inline static void write(Stream& stream, const T& m)
    {
      stream.next(m.data);
    }

    template<typename Stream, typename T>
    inline static void read(Stream& stream, T& m)
    {
      stream.next(m.data);
    }

    template<typename T>
    inline static uint32_t serializedLength(const T& m)
    {
      return serializationLength(m.data);
    }
  }; // struct Rotation_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<>
struct Printer< ::KDL::Rotation >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::KDL::Rotation& v)
  {
    s << indent << "data[]" << std::endl;
    for (size_t i = 0; i < 9; ++i)
    {
      s << indent << "  data[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.data[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
FORWARD_ROS_MESSAGE_TRAITS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Rotation_<ContainerAllocator>, ::KDL::Rotation)
FORWARD_ROS_SERIALIZER_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Rotation_<ContainerAllocator>, ::KDL::Rotation)
FORWARD_ROS_MESSAGE_OPERATIONS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Rotation_<ContainerAllocator>, ::KDL::Rotation)
#endif

#endif // KDL_MSGS_MESSAGE_ROTATION_H
