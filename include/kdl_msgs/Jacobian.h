#ifndef KDL_MSGS_MESSAGE_JACOBIAN_H
#define KDL_MSGS_MESSAGE_JACOBIAN_H

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <kdl/jacobian.hpp>

#include <kdl_msgs/util/forward_traits.h>
#include <kdl_msgs/util/serialization.h>

namespace kdl_msgs
{
#ifndef BOOST_NO_CXX11_TEMPLATE_ALIASES
// using C++11 syntax ::KDL::Jacobian and kdl_msgs::Jacobian_ are exactly the same type
template <typename ContainerAllocator> using Jacobian_ = ::KDL::Jacobian;
#else
template <class ContainerAllocator>
struct Jacobian_ : public ::KDL::Jacobian
{
  typedef Jacobian_<ContainerAllocator> Type;
  typedef double value_type;

  Jacobian_()
  {}
  Jacobian_(const ContainerAllocator&)
  {}
  Jacobian_(unsigned int nr_of_columns)
    : ::KDL::Jacobian(nr_of_columns)
  {}
  Jacobian_(const ::KDL::Jacobian& other)
    : ::KDL::Jacobian(other)
  {}

  // assignment operator
  Type& operator=(const Type& rhs)
  {
    static_cast< ::KDL::Jacobian&>(*this) = rhs;
    return *this;
  }
  Type& operator=(const ::KDL::Jacobian& rhs)
  {
    static_cast< ::KDL::Jacobian&>(*this) = rhs;
    return *this;
  }


  typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _data_type;

  typedef boost::shared_ptr< ::kdl_msgs::Jacobian_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kdl_msgs::Jacobian_<ContainerAllocator> const> ConstPtr;

}; // struct Jacobian_
#endif

typedef ::kdl_msgs::Jacobian_<std::allocator<void> > Jacobian;

typedef boost::shared_ptr< ::kdl_msgs::Jacobian > JacobianPtr;
typedef boost::shared_ptr< ::kdl_msgs::Jacobian const> JacobianConstPtr;

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kdl_msgs::Jacobian_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kdl_msgs::Jacobian_<ContainerAllocator> >::stream(s, "", v);
return s;
}
#endif

} // namespace kdl_msgs

namespace ros
{
namespace message_traits
{

template <>
struct IsFixedSize< ::KDL::Jacobian >
  : FalseType
  { };

template <>
struct IsFixedSize< ::KDL::Jacobian const>
  : FalseType
  { };

template <>
struct IsMessage< ::KDL::Jacobian >
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Jacobian const>
  : TrueType
  { };

template <>
struct HasHeader< ::KDL::Jacobian >
  : FalseType
  { };

template <>
struct HasHeader< ::KDL::Jacobian const>
  : FalseType
  { };


template<>
struct MD5Sum< ::KDL::Jacobian >
{
  static const char* value()
  {
    return "788898178a3da2c3718461eecda8f714";
  }

  static const char* value(const ::KDL::Jacobian&) { return value(); }
  static const uint64_t static_value1 = 0x788898178a3da2c3ULL;
  static const uint64_t static_value2 = 0x718461eecda8f714ULL;
};

template<>
struct DataType< ::KDL::Jacobian >
{
  static const char* value()
  {
    return "kdl_msgs/Jacobian";
  }

  static const char* value(const ::KDL::Jacobian&) { return value(); }
};

template<>
struct Definition< ::KDL::Jacobian >
{
  static const char* value()
  {
    return "# Represents a KDL::Jacobian instance.\n\
# The Jacobian always has 6 rows and is represented column-major storage order.\n\
# The number of columns is variable.\n\
\n\
float64[] data\n\
";
  }

  static const char* value(const ::KDL::Jacobian&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<> struct Serializer< ::KDL::Jacobian >
  {
    template<typename Stream, typename T>
    inline static void write(Stream& stream, const T& m)
    {
      serialize(stream, m.data.data(), m.data.rows() * m.data.cols());
    }

    template<typename Stream, typename T>
    inline static void read(Stream& stream, T& m)
    {
      std::size_t size = stream.getLength() / sizeof(typename T::value_type);
      BOOST_ASSERT_MSG((size % 6) == 0, "Size of Jacobian must be a multiple of 6");
      m.resize(size / 6);
      deserialize(stream, m.data.data(), m.data.rows() * m.data.cols());
    }

    template<typename T>
    inline static uint32_t serializedLength(const T& m)
    {
      return serializationLength(m.data.data(), m.data.rows() * m.data.cols());
    }
  }; // struct Jacobian_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<>
struct Printer< ::KDL::Jacobian >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::KDL::Jacobian& v)
  {
    s << indent << "data[]" << std::endl;
    for (size_t i = 0; i < v.data.size(); ++i)
    {
      s << indent << "  data[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.data(i));
    }
  }
};

} // namespace message_operations
} // namespace ros

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
FORWARD_ROS_MESSAGE_TRAITS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Jacobian_<ContainerAllocator>, ::KDL::Jacobian)
FORWARD_ROS_SERIALIZER_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Jacobian_<ContainerAllocator>, ::KDL::Jacobian)
FORWARD_ROS_MESSAGE_OPERATIONS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Jacobian_<ContainerAllocator>, ::KDL::Jacobian)
#endif

#endif // KDL_MSGS_MESSAGE_JACOBIAN_H
