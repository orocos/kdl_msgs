#ifndef KDL_MSGS_MESSAGE_ROTATIONALINERTIA_H
#define KDL_MSGS_MESSAGE_ROTATIONALINERTIA_H

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <kdl/rotationalinertia.hpp>

#include <kdl_msgs/util/forward_traits.h>
#include <kdl_msgs/util/serialization.h>

namespace kdl_msgs
{
#ifndef BOOST_NO_CXX11_TEMPLATE_ALIASES
// using C++11 syntax ::KDL::RotationalInertia and kdl_msgs::RotationalInertia_ are exactly the same type
template <typename ContainerAllocator> using RotationalInertia_ = ::KDL::RotationalInertia;
#else
template <class ContainerAllocator>
struct RotationalInertia_ : public ::KDL::RotationalInertia
{
  typedef RotationalInertia_<ContainerAllocator> Type;
  typedef double value_type;

//  RotationalInertia_()
//  {}
  RotationalInertia_(const ContainerAllocator&)
  {}
  RotationalInertia_(double Ixx = 0, double Iyy = 0, double Izz = 0,
                     double Ixy = 0, double Ixz = 0, double Iyz = 0)
    : ::KDL::RotationalInertia(Ixx, Iyy, Izz, Ixy, Ixz, Iyz)
  {}
  RotationalInertia_(const value_type (&array)[9])
    : ::KDL::RotationalInertia(array[0], array[1], array[2],
                      array[3], array[4], array[5],
                      array[6], array[7], array[8])
  {}
  RotationalInertia_(const ::KDL::RotationalInertia& other)
    : ::KDL::RotationalInertia(other)
  {}

  // assignment operator
  Type& operator=(const Type& rhs)
  {
    static_cast< ::KDL::RotationalInertia&>(*this) = rhs;
    return *this;
  }
  Type& operator=(const ::KDL::RotationalInertia& rhs)
  {
    static_cast< ::KDL::RotationalInertia&>(*this) = rhs;
    return *this;
  }

  typedef value_type _data_type[9];

  typedef boost::shared_ptr< ::kdl_msgs::RotationalInertia_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kdl_msgs::RotationalInertia_<ContainerAllocator> const> ConstPtr;

}; // struct RotationalInertia_
#endif

typedef ::kdl_msgs::RotationalInertia_<std::allocator<void> > RotationalInertia;

typedef boost::shared_ptr< ::kdl_msgs::RotationalInertia > RotationalInertiaPtr;
typedef boost::shared_ptr< ::kdl_msgs::RotationalInertia const> RotationalInertiaConstPtr;

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kdl_msgs::RotationalInertia_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kdl_msgs::RotationalInertia_<ContainerAllocator> >::stream(s, "", v);
return s;
}
#endif

} // namespace kdl_msgs

namespace ros
{
namespace message_traits
{

template <>
struct IsFixedSize< ::KDL::RotationalInertia >
  : TrueType
  { };

template <>
struct IsFixedSize< ::KDL::RotationalInertia const>
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::RotationalInertia >
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::RotationalInertia const>
  : TrueType
  { };

template <>
struct HasHeader< ::KDL::RotationalInertia >
  : FalseType
  { };

template <>
struct HasHeader< ::KDL::RotationalInertia const>
  : FalseType
  { };


template<>
struct MD5Sum< ::KDL::RotationalInertia >
{
  static const char* value()
  {
    return "ca66b32e4ad9de837a30ea9fe5ade752";
  }

  static const char* value(const ::KDL::RotationalInertia&) { return value(); }
  static const uint64_t static_value1 = 0xca66b32e4ad9de83ULL;
  static const uint64_t static_value2 = 0x7a30ea9fe5ade752ULL;
};

template<>
struct DataType< ::KDL::RotationalInertia >
{
  static const char* value()
  {
    return "kdl_msgs/RotationalInertia";
  }

  static const char* value(const ::KDL::RotationalInertia&) { return value(); }
};

template<>
struct Definition< ::KDL::RotationalInertia >
{
  static const char* value()
  {
    return "# Represents a KDL::RotationalInertia instance.\n\
\n\
float64[9] data\n\
";
  }

  static const char* value(const ::KDL::RotationalInertia&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<> struct Serializer< ::KDL::RotationalInertia >
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
  }; // struct RotationalInertia_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<>
struct Printer< ::KDL::RotationalInertia >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::KDL::RotationalInertia& v)
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
FORWARD_ROS_MESSAGE_TRAITS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::RotationalInertia_<ContainerAllocator>, ::KDL::RotationalInertia)
FORWARD_ROS_SERIALIZER_TEMPLATE(class ContainerAllocator, ::kdl_msgs::RotationalInertia_<ContainerAllocator>, ::KDL::RotationalInertia)
FORWARD_ROS_MESSAGE_OPERATIONS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::RotationalInertia_<ContainerAllocator>, ::KDL::RotationalInertia)
#endif

#endif // KDL_MSGS_MESSAGE_ROTATIONALINERTIA_H
