#ifndef KDL_MSGS_MESSAGE_JOINT_H
#define KDL_MSGS_MESSAGE_JOINT_H

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <kdl/joint.hpp>

#include <kdl_msgs/Vector.h>
#include <kdl_msgs/util/forward_traits.h>

namespace kdl_msgs
{
#ifndef BOOST_NO_CXX11_TEMPLATE_ALIASES
// using C++11 syntax ::KDL::Joint and kdl_msgs::Joint_ are exactly the same type
template <typename ContainerAllocator> using Joint_ = ::KDL::Joint;
#else
template <class ContainerAllocator>
struct Joint_ : public ::KDL::Joint
{
  typedef Joint_<ContainerAllocator> Type;

//  Joint_()
//  {}
  Joint_(const ContainerAllocator&)
  {}
  Joint_(const std::string& name, const JointType& type=None,const double& scale=1,const double& offset=0,
        const double& inertia=0,const double& damping=0,const double& stiffness=0)
    : ::KDL::Joint(name, type, scale, offset, inertia, damping, stiffness)
  {}
  Joint_(const JointType& type=None,const double& scale=1,const double& offset=0,
         const double& inertia=0,const double& damping=0,const double& stiffness=0)
    : ::KDL::Joint(type, scale, offset, inertia, damping, stiffness)
  {}
  Joint_(const std::string& name, const ::KDL::Vector& origin, const ::KDL::Vector& axis, const JointType& type, const double& scale=1, const double& offset=0,
  const double& inertia=0, const double& damping=0, const double& stiffness=0)
    : ::KDL::Joint(name, origin, axis, type, scale, offset, inertia, damping, stiffness)
  {}
  Joint_(const ::KDL::Vector& origin, const ::KDL::Vector& axis, const JointType& type, const double& scale=1, const double& offset=0,
  const double& inertia=0, const double& damping=0, const double& stiffness=0)
    : ::KDL::Joint(origin, axis, type, scale, offset, inertia, damping, stiffness)
  {}
  Joint_(const ::KDL::Joint& other)
    : ::KDL::Joint(other)
  {}

  // assignment operator
  Type& operator=(const Type& rhs)
  {
    static_cast< ::KDL::Joint&>(*this) = rhs;
    return *this;
  }
  Type& operator=(const ::KDL::Joint& rhs)
  {
    static_cast< ::KDL::Joint&>(*this) = rhs;
    return *this;
  }

  typedef std::string _name_type;
  typedef ::KDL::Joint::JointType _type_type;
  typedef double _scale_type;
  typedef double _offset_type;
  typedef double _inertia_type;
  typedef double _damping_type;
  typedef double _stiffness_type;
  typedef  ::kdl_msgs::Vector_<ContainerAllocator>  _origin_type;
  typedef  ::kdl_msgs::Vector_<ContainerAllocator>  _axis_type;

  typedef boost::shared_ptr< ::kdl_msgs::Joint_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kdl_msgs::Joint_<ContainerAllocator> const> ConstPtr;

}; // struct Joint_
#endif

typedef ::kdl_msgs::Joint_<std::allocator<void> > Joint;

typedef boost::shared_ptr< ::kdl_msgs::Joint > JointPtr;
typedef boost::shared_ptr< ::kdl_msgs::Joint const> JointConstPtr;

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kdl_msgs::Joint_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kdl_msgs::Joint_<ContainerAllocator> >::stream(s, "", v);
return s;
}
#endif

} // namespace kdl_msgs

namespace ros
{
namespace message_traits
{

template <>
struct IsFixedSize< ::KDL::Joint >
  : FalseType
  { };

template <>
struct IsFixedSize< ::KDL::Joint const>
  : FalseType
  { };

template <>
struct IsMessage< ::KDL::Joint >
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Joint const>
  : TrueType
  { };

template <>
struct HasHeader< ::KDL::Joint >
  : FalseType
  { };

template <>
struct HasHeader< ::KDL::Joint const>
  : FalseType
  { };


template<>
struct MD5Sum< ::KDL::Joint >
{
  static const char* value()
  {
    return "4f8448d28309edc7c24ce443bb15110a";
  }

  static const char* value(const ::KDL::Joint&) { return value(); }
  static const uint64_t static_value1 = 0x4f8448d28309edc7ULL;
  static const uint64_t static_value2 = 0xc24ce443bb15110aULL;
};

template<>
struct DataType< ::KDL::Joint >
{
  static const char* value()
  {
    return "kdl_msgs/Joint";
  }

  static const char* value(const ::KDL::Joint&) { return value(); }
};

template<>
struct Definition< ::KDL::Joint >
{
  static const char* value()
  {
    return "# Represents a KDL::Joint instance.\n\
\n\
string name                   # name of the joint\n\
\n\
uint8 type                    # type of the joint, default: Joint::None. One of...\n\
uint8 RotAxis   = 0\n\
uint8 RotX      = 1\n\
uint8 RotY      = 2\n\
uint8 RotZ      = 3\n\
uint8 TransAxis = 4\n\
uint8 TransX    = 5\n\
uint8 TransY    = 6\n\
uint8 TransZ    = 7\n\
uint8 None_     = 8           # None is a reserved name in Python\n\
\n\
float64 scale                 # scale between joint input and actual geometric\n\
                              #   movement, default: 1\n\
float64 offset                # offset between joint input and actual\n\
                              #   geometric input, default: 0\n\
float64 inertia               # 1D inertia along the joint axis, default: 0\n\
float64 damping               # 1D damping along the joint axis, default: 0\n\
float64 stiffness             # 1D stiffness along the joint axis, default: 0\n\
\n\
Vector origin                 # the origin of the joint\n\
Vector axis                   # the axis of the joint\n\
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

  static const char* value(const ::KDL::Joint&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<> struct Serializer< ::KDL::Joint >
  {
    template<typename Stream, typename T>
    inline static void write(Stream& stream, const T& m)
    {
      stream.next(m.getName());
      stream.next((uint8_t)m.getType());
      stream.next(double());   // TODO: no API to get scale
      stream.next(double());   // TODO: no API to get offset
      stream.next(double());   // TODO: no API to get inertia
      stream.next(double());   // TODO: no API to get damping
      stream.next(double());   // TODO: no API to get stiffness
      stream.next(m.JointOrigin());
      stream.next(m.JointAxis());
    }

    template<typename Stream, typename T>
    inline static void read(Stream& stream, T& m)
    {
      typename T::_name_type _name;
      stream.next(_name);
      uint8_t _type;
      stream.next(_type);
      typename T::_scale_type _scale;
      stream.next(_scale);
      typename T::_offset_type _offset;
      stream.next(_offset);
      typename T::_inertia_type _inertia;
      stream.next(_inertia);
      typename T::_damping_type _damping;
      stream.next(_damping);
      typename T::_stiffness_type _stiffness;
      stream.next(_stiffness);
      typename T::_origin_type _origin;
      stream.next(_origin);
      typename T::_axis_type _axis;
      stream.next(_axis);
      if (_type != ::KDL::Joint::RotAxis && _type != ::KDL::Joint::TransAxis) {
        m = T(_name, (::KDL::Joint::JointType) _type,
              _scale, _offset, _inertia, _damping, _stiffness);
      } else {
        m = T(_name, _origin, _axis, (::KDL::Joint::JointType) _type,
              _scale, _offset, _inertia, _damping, _stiffness);
      }
    }

    template<typename T>
    inline static uint32_t serializedLength(const T& m)
    {
      LStream stream;
      stream.next(m.getName());
      stream.next((uint8_t)m.getType());
      stream.next(double());   // TODO: no API to get scale
      stream.next(double());   // TODO: no API to get offset
      stream.next(double());   // TODO: no API to get inertia
      stream.next(double());   // TODO: no API to get damping
      stream.next(double());   // TODO: no API to get stiffness
      stream.next(m.JointOrigin());
      stream.next(m.JointAxis());
      return stream.getLength();
    }
  }; // struct Joint_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<>
struct Printer< ::KDL::Joint >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::KDL::Joint& v)
  {
    s << indent << "name: ";
    Printer<std::string>::stream(s, indent + "  ", v.getName());
    s << indent << "type: ";
    Printer<std::string>::stream(s, indent + "  ", v.getTypeName());
    s << indent << "scale: ???\n";
    s << indent << "offset: ???\n";
    s << indent << "inertia: ???\n";
    s << indent << "damping: ???\n";
    s << indent << "stiffness: ???\n";
    s << indent << "origin: ";
    s << std::endl;
    Printer< ::KDL::Vector >::stream(s, indent + "  ", v.JointOrigin());
    s << indent << "axis: ";
    s << std::endl;
    Printer< ::KDL::Vector >::stream(s, indent + "  ", v.JointAxis());
  }
};

} // namespace message_operations
} // namespace ros

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
FORWARD_ROS_MESSAGE_TRAITS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Joint_<ContainerAllocator>, ::KDL::Joint)
FORWARD_ROS_SERIALIZER_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Joint_<ContainerAllocator>, ::KDL::Joint)
FORWARD_ROS_MESSAGE_OPERATIONS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Joint_<ContainerAllocator>, ::KDL::Joint)
#endif

#endif // KDL_MSGS_MESSAGE_JOINT_H
