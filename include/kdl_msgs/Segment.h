#ifndef KDL_MSGS_MESSAGE_SEGMENT_H
#define KDL_MSGS_MESSAGE_SEGMENT_H

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <kdl/segment.hpp>

#include <kdl_msgs/Joint.h>
#include <kdl_msgs/Frame.h>
#include <kdl_msgs/RigidBodyInertia.h>
#include <kdl_msgs/util/forward_traits.h>

namespace kdl_msgs
{
#ifndef BOOST_NO_CXX11_TEMPLATE_ALIASES
// using C++11 syntax ::KDL::Segment and kdl_msgs::Segment_ are exactly the same type
template <typename ContainerAllocator> using Segment_ = ::KDL::Segment;
#else
template <class ContainerAllocator>
struct Segment_ : public ::KDL::Segment
{
  typedef Segment_<ContainerAllocator> Type;

//  Segment_()
//  {}
  Segment_(const ContainerAllocator&)
  {}
  Segment_(const std::string& name, const ::KDL::Joint& joint = ::KDL::Joint(::KDL::Joint::None),
           const ::KDL::Frame& f_tip = ::KDL::Frame::Identity(),
           const ::KDL::RigidBodyInertia& I = ::KDL::RigidBodyInertia::Zero())
    : ::KDL::Segment(name, joint, f_tip, I)
  {}
  Segment_(const ::KDL::Joint& joint = ::KDL::Joint(::KDL::Joint::None),
           const ::KDL::Frame& f_tip = ::KDL::Frame::Identity(),
           const ::KDL::RigidBodyInertia& I = ::KDL::RigidBodyInertia::Zero())
    : ::KDL::Segment(joint, f_tip, I)
  {}
  Segment_(const ::KDL::Segment& other)
    : ::KDL::Segment(other)
  {}

  // assignment operator
  Type& operator=(const Type& rhs)
  {
    static_cast< ::KDL::Segment&>(*this) = rhs;
    return *this;
  }
  Type& operator=(const ::KDL::Segment& rhs)
  {
    static_cast< ::KDL::Segment&>(*this) = rhs;
    return *this;
  }

  typedef std::string  _name_type;
  typedef  ::kdl_msgs::Joint_<ContainerAllocator>  _joint_type;
  typedef  ::kdl_msgs::Frame_<ContainerAllocator>  _f_tip_type;
  typedef  ::kdl_msgs::RigidBodyInertia_<ContainerAllocator>  _I_type;

  typedef boost::shared_ptr< ::kdl_msgs::Segment_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kdl_msgs::Segment_<ContainerAllocator> const> ConstPtr;

}; // struct Segment_
#endif

typedef ::kdl_msgs::Segment_<std::allocator<void> > Segment;

typedef boost::shared_ptr< ::kdl_msgs::Segment > SegmentPtr;
typedef boost::shared_ptr< ::kdl_msgs::Segment const> SegmentConstPtr;

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kdl_msgs::Segment_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kdl_msgs::Segment_<ContainerAllocator> >::stream(s, "", v);
return s;
}
#endif

} // namespace kdl_msgs

namespace ros
{
namespace message_traits
{

template <>
struct IsFixedSize< ::KDL::Segment >
  : FalseType
  { };

template <>
struct IsFixedSize< ::KDL::Segment const>
  : FalseType
  { };

template <>
struct IsMessage< ::KDL::Segment >
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Segment const>
  : TrueType
  { };

template <>
struct HasHeader< ::KDL::Segment >
  : FalseType
  { };

template <>
struct HasHeader< ::KDL::Segment const>
  : FalseType
  { };


template<>
struct MD5Sum< ::KDL::Segment >
{
  static const char* value()
  {
    return "ea2f787ad0b4c61e6da4d0592adf35fd";
  }

  static const char* value(const ::KDL::Segment&) { return value(); }
  static const uint64_t static_value1 = 0xea2f787ad0b4c61eULL;
  static const uint64_t static_value2 = 0x6da4d0592adf35fdULL;
};

template<>
struct DataType< ::KDL::Segment >
{
  static const char* value()
  {
    return "kdl_msgs/Segment";
  }

  static const char* value(const ::KDL::Segment&) { return value(); }
};

template<>
struct Definition< ::KDL::Segment >
{
  static const char* value()
  {
    return "# Represents a KDL::Segment instance.\n\
#\n\
# This class encapsulates a simple segment, that is a \"rigid body\"\n\
# (i.e., a frame and a rigid body inertia) with a joint and with \"handles\",\n\
# root and tip to connect to other segments.\n\
#\n\
\n\
string name                   # name of the segment\n\
Joint joint                   # joint of the segment, default: Joint(Joint::None)\n\
Frame f_tip                   # frame from the end of the joint to the tip of\n\
                              #   the segment, default: Frame::Identity()\n\
RigidBodyInertia I            # rigid body inertia of the segment, default: Inertia::Zero()\n\
\n\
================================================================================\n\
MSG: kdl_msgs/Joint\n\
# Represents a KDL::Joint instance.\n\
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
uint8 None      = 8\n\
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
\n\
================================================================================\n\
MSG: kdl_msgs/Frame\n\
# Represents a KDL::Frame instance.\n\
\n\
Vector p\n\
Rotation M\n\
\n\
================================================================================\n\
MSG: kdl_msgs/Rotation\n\
# Represents a KDL::Rotation instance.\n\
\n\
float64[9] data\n\
\n\
================================================================================\n\
MSG: kdl_msgs/RigidBodyInertia\n\
# Represents a KDL::RigidBodyInertia instance.\n\
#\n\
# 6D Inertia of a rigid body\n\
#\n\
\n\
float64 m\n\
Vector cog\n\
RotationalInertia I\n\
\n\
================================================================================\n\
MSG: kdl_msgs/RotationalInertia\n\
# Represents a KDL::RotationalInertia instance.\n\
\n\
float64[9] data\n\
";
  }

  static const char* value(const ::KDL::Segment&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<> struct Serializer< ::KDL::Segment >
  {
    template<typename Stream, typename T>
    inline static void write(Stream& stream, const T& m)
    {
      stream.next(m.getName());
      stream.next(m.getJoint());
      stream.next(m.getFrameToTip());
      stream.next(m.getInertia());
    }

    template<typename Stream, typename T>
    inline static void read(Stream& stream, T& m)
    {
      ::kdl_msgs::Segment::_name_type _name;
      stream.next(_name);
      ::kdl_msgs::Segment::_joint_type _joint;
      stream.next(_joint);
      ::kdl_msgs::Segment::_f_tip_type _f_tip;
      stream.next(_f_tip);
      ::kdl_msgs::Segment::_I_type _I;
      stream.next(_I);
      m = T(_name, _joint, _f_tip, _I);
    }

    template<typename T>
    inline static uint32_t serializedLength(const T& m)
    {
      LStream stream;
      stream.next(m.getName());
      stream.next(m.getJoint());
      stream.next(m.getFrameToTip());
      stream.next(m.getInertia());
      return stream.getLength();
    }
  }; // struct Segment_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<>
struct Printer< ::KDL::Segment >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::KDL::Segment& v)
  {
    s << indent << "name: ";
    Printer<std::string>::stream(s, indent + "  ", v.getName());
    s << indent << "joint: ";
    s << std::endl;
    Printer< ::KDL::Joint >::stream(s, indent + "  ", v.getJoint());
    s << indent << "f_tip: ";
    s << std::endl;
    Printer< ::KDL::Frame >::stream(s, indent + "  ", v.getFrameToTip());
    s << indent << "I: ";
    s << std::endl;
    Printer< ::KDL::RigidBodyInertia >::stream(s, indent + "  ", v.getInertia());
  }
};

} // namespace message_operations
} // namespace ros

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
FORWARD_ROS_MESSAGE_TRAITS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Segment_<ContainerAllocator>, ::KDL::Segment)
FORWARD_ROS_SERIALIZER_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Segment_<ContainerAllocator>, ::KDL::Segment)
FORWARD_ROS_MESSAGE_OPERATIONS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Segment_<ContainerAllocator>, ::KDL::Segment)
#endif

#endif // KDL_MSGS_MESSAGE_SEGMENT_H
