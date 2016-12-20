#ifndef KDL_MSGS_MESSAGE_WRENCH_H
#define KDL_MSGS_MESSAGE_WRENCH_H

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <kdl_msgs/Vector.h>

#include <kdl_msgs/util/forward_traits.h>

namespace kdl_msgs
{
#ifndef BOOST_NO_CXX11_TEMPLATE_ALIASES
// using C++11 syntax ::KDL::Wrench and kdl_msgs::Wrench_ are exactly the same type
template <typename ContainerAllocator> using Wrench_ = ::KDL::Wrench;
#else
template <class ContainerAllocator>
struct Wrench_ : public ::KDL::Wrench
{
  typedef Wrench_<ContainerAllocator> Type;

  Wrench_()
  {}
  Wrench_(const ContainerAllocator&)
  {}
  Wrench_(const ::KDL::Vector& force, const ::KDL::Vector& torque)
    : ::KDL::Wrench(force, torque)
  {}
  Wrench_(const ::KDL::Wrench& other)
    : ::KDL::Wrench(other)
  {}

  // assignment operator
  Type& operator=(const Type& rhs)
  {
    static_cast< ::KDL::Wrench&>(*this) = rhs;
    return *this;
  }
  Type& operator=(const ::KDL::Wrench& rhs)
  {
    static_cast< ::KDL::Wrench&>(*this) = rhs;
    return *this;
  }

  typedef  ::kdl_msgs::Vector_<ContainerAllocator>  _force_type;
  typedef  ::kdl_msgs::Vector_<ContainerAllocator>  _torque_type;

  typedef boost::shared_ptr< ::kdl_msgs::Wrench_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kdl_msgs::Wrench_<ContainerAllocator> const> ConstPtr;

}; // struct Wrench_
#endif

typedef ::kdl_msgs::Wrench_<std::allocator<void> > Wrench;

typedef boost::shared_ptr< ::kdl_msgs::Wrench > WrenchPtr;
typedef boost::shared_ptr< ::kdl_msgs::Wrench const> WrenchConstPtr;

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kdl_msgs::Wrench_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kdl_msgs::Wrench_<ContainerAllocator> >::stream(s, "", v);
return s;
}
#endif

} // namespace kdl_msgs

namespace ros
{
namespace message_traits
{

template <>
struct IsFixedSize< ::KDL::Wrench >
  : TrueType
  { };

template <>
struct IsFixedSize< ::KDL::Wrench const>
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Wrench >
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Wrench const>
  : TrueType
  { };

template <>
struct HasHeader< ::KDL::Wrench >
  : FalseType
  { };

template <>
struct HasHeader< ::KDL::Wrench const>
  : FalseType
  { };


template<>
struct MD5Sum< ::KDL::Wrench >
{
  static const char* value()
  {
    return "4f539cf138b23283b520fd271b567936";
  }

  static const char* value(const ::KDL::Wrench&) { return value(); }
  static const uint64_t static_value1 = 0x4f539cf138b23283ULL;
  static const uint64_t static_value2 = 0xb520fd271b567936ULL;
};

template<>
struct DataType< ::KDL::Wrench >
{
  static const char* value()
  {
    return "kdl_msgs/Wrench";
  }

  static const char* value(const ::KDL::Wrench&) { return value(); }
};

template<>
struct Definition< ::KDL::Wrench >
{
  static const char* value()
  {
    return "# Represents a KDL::Wrench instance.\n\
# This message is compatible to geometry_msgs/Wrench.\n\
\n\
Vector force\n\
Vector torque\n\
\n\
================================================================================\n\
MSG: kdl_msgs/Vector\n\
# Represents a KDL::Vector instance.\n\
# This message is compatible to geometry_msgs/Vector3.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::KDL::Wrench&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<> struct Serializer< ::KDL::Wrench >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.force);
      stream.next(m.torque);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Wrench_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<>
struct Printer< ::KDL::Wrench >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::KDL::Wrench& v)
  {
    s << indent << "force: ";
    s << std::endl;
    Printer< ::KDL::Vector >::stream(s, indent + "  ", v.force);
    s << indent << "torque: ";
    s << std::endl;
    Printer< ::KDL::Vector >::stream(s, indent + "  ", v.torque);
  }
};

} // namespace message_operations
} // namespace ros

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
FORWARD_ROS_MESSAGE_TRAITS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Wrench_<ContainerAllocator>, ::KDL::Wrench)
FORWARD_ROS_SERIALIZER_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Wrench_<ContainerAllocator>, ::KDL::Wrench)
FORWARD_ROS_MESSAGE_OPERATIONS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Wrench_<ContainerAllocator>, ::KDL::Wrench)
#endif

#endif // KDL_MSGS_MESSAGE_WRENCH_H
