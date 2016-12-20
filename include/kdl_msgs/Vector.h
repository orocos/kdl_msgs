#ifndef KDL_MSGS_MESSAGE_VECTOR_H
#define KDL_MSGS_MESSAGE_VECTOR_H

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
// using C++11 syntax ::KDL::Vector and kdl_msgs::Vector_ are exactly the same type
template <typename ContainerAllocator> using Vector_ = ::KDL::Vector;
#else
template <class ContainerAllocator>
struct Vector_ : public ::KDL::Vector
{
  typedef Vector_<ContainerAllocator> Type;
  typedef double value_type;

  Vector_()
  {}
  Vector_(const ContainerAllocator&)
  {}
  Vector_(value_type x, value_type y, value_type z)
    : ::KDL::Vector(x, y, z)
  {}
  Vector_(const value_type (&array)[3])
    : ::KDL::Vector(array[0], array[1], array[2])
  {}
  Vector_(const ::KDL::Vector& other)
    : ::KDL::Vector(other)
  {}

  // assignment operator
  Type& operator=(const Type& rhs)
  {
    static_cast< ::KDL::Vector&>(*this) = rhs;
    return *this;
  }
  Type& operator=(const ::KDL::Vector& rhs)
  {
    static_cast< ::KDL::Vector&>(*this) = rhs;
    return *this;
  }

  typedef value_type _data_type[3];
  typedef value_type _x_type;
  typedef value_type _y_type;
  typedef value_type _z_type;

  typedef boost::shared_ptr< ::kdl_msgs::Vector_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kdl_msgs::Vector_<ContainerAllocator> const> ConstPtr;

}; // struct Vector_
#endif

typedef ::kdl_msgs::Vector_<std::allocator<void> > Vector;

typedef boost::shared_ptr< ::kdl_msgs::Vector > VectorPtr;
typedef boost::shared_ptr< ::kdl_msgs::Vector const> VectorConstPtr;

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kdl_msgs::Vector_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kdl_msgs::Vector_<ContainerAllocator> >::stream(s, "", v);
return s;
}
#endif

} // namespace kdl_msgs

namespace ros
{
namespace message_traits
{

template <>
struct IsFixedSize< ::KDL::Vector >
  : TrueType
  { };

template <>
struct IsFixedSize< ::KDL::Vector const>
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Vector >
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Vector const>
  : TrueType
  { };

template <>
struct HasHeader< ::KDL::Vector >
  : FalseType
  { };

template <>
struct HasHeader< ::KDL::Vector const>
  : FalseType
  { };

template<>
struct MD5Sum< ::KDL::Vector >
{
  static const char* value()
  {
    return "4a842b65f413084dc2b10fb484ea7f17";
  }

  static const char* value(const ::KDL::Vector&) { return value(); }
  static const uint64_t static_value1 = 0x4a842b65f413084dULL;
  static const uint64_t static_value2 = 0xc2b10fb484ea7f17ULL;
};

template<>
struct DataType< ::KDL::Vector >
{
  static const char* value()
  {
    return "kdl_msgs/Vector";
  }

  static const char* value(const ::KDL::Vector&) { return value(); }
};

template<>
struct Definition< ::KDL::Vector >
{
  static const char* value()
  {
    return "# Represents a KDL::Vector instance.\n\
# This message is compatible to geometry_msgs/Vector3.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::KDL::Vector&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{
  template<> struct Serializer< ::KDL::Vector >
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
  }; // struct Vector_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<>
struct Printer< ::KDL::Vector >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::KDL::Vector& v)
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.data[0]);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.data[1]);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.data[2]);
  }
};

} // namespace message_operations
} // namespace ros

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
FORWARD_ROS_MESSAGE_TRAITS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Vector_<ContainerAllocator>, ::KDL::Vector)
FORWARD_ROS_SERIALIZER_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Vector_<ContainerAllocator>, ::KDL::Vector)
FORWARD_ROS_MESSAGE_OPERATIONS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Vector_<ContainerAllocator>, ::KDL::Vector)
#endif

#endif // KDL_MSGS_MESSAGE_VECTOR_H
