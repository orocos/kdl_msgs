#ifndef KDL_MSGS_MESSAGE_TWIST_H
#define KDL_MSGS_MESSAGE_TWIST_H

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <kdl_msgs/Vector.h>

#include <kdl_msgs/util/forward_traits.h>

namespace kdl_msgs
{
#ifndef BOOST_NO_CXX11_TEMPLATE_ALIASES
// using C++11 syntax ::KDL::Twist and kdl_msgs::Twist_ are exactly the same type
template <typename ContainerAllocator> using Twist_ = ::KDL::Twist;
#else
template <class ContainerAllocator>
struct Twist_ : public ::KDL::Twist
{
  typedef Twist_<ContainerAllocator> Type;

  Twist_()
    : linear(::KDL::Twist::vel), angular(::KDL::Twist::rot)
  {}
  Twist_(const ContainerAllocator&)
    : linear(::KDL::Twist::vel), angular(::KDL::Twist::rot)
  {}
  Twist_(const ::KDL::Vector& vel, const ::KDL::Vector& rot)
    : ::KDL::Twist(vel, rot)
    , linear(::KDL::Twist::vel), angular(::KDL::Twist::rot)
  {}
  Twist_(const ::KDL::Twist& other)
    : ::KDL::Twist(other)
    , linear(::KDL::Twist::vel), angular(::KDL::Twist::rot)
  {}

  // assignment operator
  Type& operator=(const Type& rhs)
  {
    static_cast< ::KDL::Twist&>(*this) = rhs;
    return *this;
  }
  Type& operator=(const ::KDL::Twist& rhs)
  {
    static_cast< ::KDL::Twist&>(*this) = rhs;
    return *this;
  }

  typedef  ::kdl_msgs::Vector_<ContainerAllocator>  _linear_type;
  ::KDL::Vector& linear; // reference to ::KDL::Twist::vel
  typedef  ::kdl_msgs::Vector_<ContainerAllocator>  _angular_type;
  ::KDL::Vector& angular; // reference to ::KDL::Twist::rot

  typedef boost::shared_ptr< ::kdl_msgs::Twist_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kdl_msgs::Twist_<ContainerAllocator> const> ConstPtr;

}; // struct Twist_
#endif

typedef ::kdl_msgs::Twist_<std::allocator<void> > Twist;

typedef boost::shared_ptr< ::kdl_msgs::Twist > TwistPtr;
typedef boost::shared_ptr< ::kdl_msgs::Twist const> TwistConstPtr;

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kdl_msgs::Twist_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kdl_msgs::Twist_<ContainerAllocator> >::stream(s, "", v);
return s;
}
#endif

} // namespace kdl_msgs

namespace ros
{
namespace message_traits
{

template <>
struct IsFixedSize< ::KDL::Twist >
  : TrueType
  { };

template <>
struct IsFixedSize< ::KDL::Twist const>
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Twist >
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Twist const>
  : TrueType
  { };

template <>
struct HasHeader< ::KDL::Twist >
  : FalseType
  { };

template <>
struct HasHeader< ::KDL::Twist const>
  : FalseType
  { };


template<>
struct MD5Sum< ::KDL::Twist >
{
  static const char* value()
  {
    return "9f195f881246fdfa2798d1d3eebca84a";
  }

  static const char* value(const ::KDL::Twist&) { return value(); }
  static const uint64_t static_value1 = 0x9f195f881246fdfaULL;
  static const uint64_t static_value2 = 0x2798d1d3eebca84aULL;
};

template<>
struct DataType< ::KDL::Twist >
{
  static const char* value()
  {
    return "kdl_msgs/Twist";
  }

  static const char* value(const ::KDL::Twist&) { return value(); }
};

template<>
struct Definition< ::KDL::Twist >
{
  static const char* value()
  {
    return "# Represents a KDL::Twist instance.\n\
# This message is compatible to geometry_msgs/Twist.\n\
\n\
Vector linear\n\
Vector angular\n\
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

  static const char* value(const ::KDL::Twist&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<> struct Serializer< ::KDL::Twist >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.vel);
      stream.next(m.rot);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Twist_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<>
struct Printer< ::KDL::Twist >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::KDL::Twist& v)
  {
    s << indent << "linear: ";
    s << std::endl;
    Printer< ::KDL::Vector >::stream(s, indent + "  ", v.vel);
    s << indent << "angular: ";
    s << std::endl;
    Printer< ::KDL::Vector >::stream(s, indent + "  ", v.rot);
  }
};

} // namespace message_operations
} // namespace ros

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
FORWARD_ROS_MESSAGE_TRAITS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Twist_<ContainerAllocator>, ::KDL::Twist)
FORWARD_ROS_SERIALIZER_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Twist_<ContainerAllocator>, ::KDL::Twist)
FORWARD_ROS_MESSAGE_OPERATIONS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Twist_<ContainerAllocator>, ::KDL::Twist)
#endif

#endif // KDL_MSGS_MESSAGE_TWIST_H
