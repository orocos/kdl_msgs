#ifndef KDL_MSGS_MESSAGE_RIGIDBODYINERTIA_H
#define KDL_MSGS_MESSAGE_RIGIDBODYINERTIA_H

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <kdl/rigidbodyinertia.hpp>

#include <kdl_msgs/Vector.h>
#include <kdl_msgs/RotationalInertia.h>
#include <kdl_msgs/util/forward_traits.h>

namespace kdl_msgs
{
#ifndef BOOST_NO_CXX11_TEMPLATE_ALIASES
// using C++11 syntax ::KDL::RigidBodyInertia and kdl_msgs::RigidBodyInertia_ are exactly the same type
template <typename ContainerAllocator> using RigidBodyInertia_ = ::KDL::RigidBodyInertia;
#else
template <class ContainerAllocator>
struct RigidBodyInertia_ : public ::KDL::RigidBodyInertia
{
  typedef RigidBodyInertia_<ContainerAllocator> Type;

//  RigidBodyInertia_()
//  {}
  RigidBodyInertia_(const ContainerAllocator&)
  {}
  RigidBodyInertia_(double m=0, const ::KDL::Vector& cog = ::KDL::Vector::Zero(),
                    const ::KDL::RotationalInertia& Ic = ::KDL::RotationalInertia::Zero())
    : ::KDL::RigidBodyInertia(m, cog, Ic)
  {}
  RigidBodyInertia_(const ::KDL::RigidBodyInertia& other)
    : ::KDL::RigidBodyInertia(other)
  {}

  // assignment operator
  Type& operator=(const Type& rhs)
  {
    static_cast< ::KDL::RigidBodyInertia&>(*this) = rhs;
    return *this;
  }
  Type& operator=(const ::KDL::RigidBodyInertia& rhs)
  {
    static_cast< ::KDL::RigidBodyInertia&>(*this) = rhs;
    return *this;
  }

  typedef double _m_type;
  typedef  ::kdl_msgs::Vector_<ContainerAllocator>  _cog_type;
  typedef  ::kdl_msgs::RotationalInertia_<ContainerAllocator>  _I_type;

  typedef boost::shared_ptr< ::kdl_msgs::RigidBodyInertia_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kdl_msgs::RigidBodyInertia_<ContainerAllocator> const> ConstPtr;

}; // struct RigidBodyInertia_
#endif

typedef ::kdl_msgs::RigidBodyInertia_<std::allocator<void> > RigidBodyInertia;

typedef boost::shared_ptr< ::kdl_msgs::RigidBodyInertia > RigidBodyInertiaPtr;
typedef boost::shared_ptr< ::kdl_msgs::RigidBodyInertia const> RigidBodyInertiaConstPtr;

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kdl_msgs::RigidBodyInertia_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kdl_msgs::RigidBodyInertia_<ContainerAllocator> >::stream(s, "", v);
return s;
}
#endif

} // namespace kdl_msgs

namespace ros
{
namespace message_traits
{

template <>
struct IsFixedSize< ::KDL::RigidBodyInertia >
  : TrueType
  { };

template <>
struct IsFixedSize< ::KDL::RigidBodyInertia const>
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::RigidBodyInertia >
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::RigidBodyInertia const>
  : TrueType
  { };

template <>
struct HasHeader< ::KDL::RigidBodyInertia >
  : FalseType
  { };

template <>
struct HasHeader< ::KDL::RigidBodyInertia const>
  : FalseType
  { };


template<>
struct MD5Sum< ::KDL::RigidBodyInertia >
{
  static const char* value()
  {
    return "33096aa337b8b33a05f701d90acdd33b";
  }

  static const char* value(const ::KDL::RigidBodyInertia&) { return value(); }
  static const uint64_t static_value1 = 0x33096aa337b8b33aULL;
  static const uint64_t static_value2 = 0x05f701d90acdd33bULL;
};

template<>
struct DataType< ::KDL::RigidBodyInertia >
{
  static const char* value()
  {
    return "kdl_msgs/RigidBodyInertia";
  }

  static const char* value(const ::KDL::RigidBodyInertia&) { return value(); }
};

template<>
struct Definition< ::KDL::RigidBodyInertia >
{
  static const char* value()
  {
    return "# Represents a KDL::RigidBodyInertia instance.\n\
#\n\
# 6D Inertia of a rigid body\n\
#\n\
\n\
float64 m\n\
Vector cog\n\
RotationalInertia I\n\
\n\
================================================================================\n\
MSG: kdl_msgs/Vector\n\
# Represents a KDL::Vector instance.\n\
# This message is compatible to geometry_msgs/Vector3.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: kdl_msgs/RotationalInertia\n\
# Represents a KDL::RotationalInertia instance.\n\
\n\
float64[9] data\n\
";
  }

  static const char* value(const ::KDL::RigidBodyInertia&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<> struct Serializer< ::KDL::RigidBodyInertia >
  {
    template<typename Stream, typename T>
    inline static void write(Stream& stream, const T& m)
    {
      stream.next(m.getMass());
      stream.next(m.getCOG());
      stream.next(m.getRotationalInertia());
    }

    template<typename Stream, typename T>
    inline static void read(Stream& stream, T& m)
    {
      typename T::_m_type _m;
      stream.next(_m);
      typename T::_cog_type _cog;
      stream.next(_cog);
      typename T::_I_type _I;
      stream.next(_I);
      m = T(_m, _cog, _I);
    }

    template<typename T>
    inline static uint32_t serializedLength(const T& m)
    {
      return (uint32_t)(sizeof(double) + 3 * sizeof(double) + 9 * sizeof(double));
    }
  }; // struct RigidBodyInertia_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<>
struct Printer< ::KDL::RigidBodyInertia >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::KDL::RigidBodyInertia& v)
  {
    s << indent << "m: ";
    Printer<double>::stream(s, indent + "  ", v.getMass());
    s << indent << "cog: ";
    s << std::endl;
    Printer< ::KDL::Vector >::stream(s, indent + "  ", v.getCOG());
    s << indent << "I: ";
    s << std::endl;
    Printer< ::KDL::RotationalInertia >::stream(s, indent + "  ", v.getRotationalInertia());
  }
};

} // namespace message_operations
} // namespace ros

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
FORWARD_ROS_MESSAGE_TRAITS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::RigidBodyInertia_<ContainerAllocator>, ::KDL::RigidBodyInertia)
FORWARD_ROS_SERIALIZER_TEMPLATE(class ContainerAllocator, ::kdl_msgs::RigidBodyInertia_<ContainerAllocator>, ::KDL::RigidBodyInertia)
FORWARD_ROS_MESSAGE_OPERATIONS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::RigidBodyInertia_<ContainerAllocator>, ::KDL::RigidBodyInertia)
#endif

#endif // KDL_MSGS_MESSAGE_RIGIDBODYINERTIA_H
