#ifndef KDL_MSGS_MESSAGE_CHAIN_H
#define KDL_MSGS_MESSAGE_CHAIN_H

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <kdl/chain.hpp>

#include <kdl_msgs/Segment.h>
#include <kdl_msgs/util/forward_traits.h>

namespace kdl_msgs
{
#ifndef BOOST_NO_CXX11_TEMPLATE_ALIASES
// using C++11 syntax ::KDL::Chain and kdl_msgs::Chain_ are exactly the same type
template <typename ContainerAllocator> using Chain_ = ::KDL::Chain;
#else
template <class ContainerAllocator>
struct Chain_ : public ::KDL::Chain
{
  typedef Chain_<ContainerAllocator> Type;

  Chain_()
  {}
  Chain_(const ContainerAllocator&)
  {}
  Chain_(const ::KDL::Chain& other)
    : ::KDL::Chain(other)
  {}

  // assignment operator
  Type& operator=(const Type& rhs)
  {
    static_cast< ::KDL::Chain&>(*this) = rhs;
    return *this;
  }
  Type& operator=(const ::KDL::Chain& rhs)
  {
    static_cast< ::KDL::Chain&>(*this) = rhs;
    return *this;
  }


  typedef std::vector< ::kdl_msgs::Segment_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::kdl_msgs::Segment_<ContainerAllocator> >::other >  _segments_type;

  typedef boost::shared_ptr< ::kdl_msgs::Chain_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kdl_msgs::Chain_<ContainerAllocator> const> ConstPtr;

}; // struct Chain_
#endif

typedef ::kdl_msgs::Chain_<std::allocator<void> > Chain;

typedef boost::shared_ptr< ::kdl_msgs::Chain > ChainPtr;
typedef boost::shared_ptr< ::kdl_msgs::Chain const> ChainConstPtr;

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kdl_msgs::Chain_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kdl_msgs::Chain_<ContainerAllocator> >::stream(s, "", v);
return s;
}
#endif

} // namespace kdl_msgs

namespace ros
{
namespace message_traits
{

template <>
struct IsFixedSize< ::KDL::Chain >
  : FalseType
  { };

template <>
struct IsFixedSize< ::KDL::Chain const>
  : FalseType
  { };

template <>
struct IsMessage< ::KDL::Chain >
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Chain const>
  : TrueType
  { };

template <>
struct HasHeader< ::KDL::Chain >
  : FalseType
  { };

template <>
struct HasHeader< ::KDL::Chain const>
  : FalseType
  { };


template<>
struct MD5Sum< ::KDL::Chain >
{
  static const char* value()
  {
    return "0ff773f05fc4dbf531922f1a3d7bdaec";
  }

  static const char* value(const ::KDL::Chain&) { return value(); }
  static const uint64_t static_value1 = 0x0ff773f05fc4dbf5ULL;
  static const uint64_t static_value2 = 0x31922f1a3d7bdaecULL;
};

template<>
struct DataType< ::KDL::Chain >
{
  static const char* value()
  {
    return "kdl_msgs/Chain";
  }

  static const char* value(const ::KDL::Chain&) { return value(); }
};

template<>
struct Definition< ::KDL::Chain >
{
  static const char* value()
  {
    return "# Represents a KDL::Chain instance.\n\
#\n\
# This class encapsulates a serial kinematic interconnection structure.\n\
# It is build out of segments.\n\
#\n\
\n\
Segment[] segments\n\
\n\
================================================================================\n\
MSG: kdl_msgs/Segment\n\
# Represents a KDL::Segment instance.\n\
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

  static const char* value(const ::KDL::Chain&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<> struct Serializer< ::KDL::Chain >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.segments);
      // TODO: Make sure that private nrOfJoints and nrOfSegments member matches after deserialization!
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Chain_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<>
struct Printer< ::KDL::Chain >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::KDL::Chain& v)
  {
    s << indent << "segments[]" << std::endl;
    for (size_t i = 0; i < v.segments.size(); ++i)
    {
      s << indent << "  segments[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::KDL::Segment >::stream(s, indent + "    ", v.segments[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
FORWARD_ROS_MESSAGE_TRAITS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Chain_<ContainerAllocator>, ::KDL::Chain)
FORWARD_ROS_SERIALIZER_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Chain_<ContainerAllocator>, ::KDL::Chain)
FORWARD_ROS_MESSAGE_OPERATIONS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::Chain_<ContainerAllocator>, ::KDL::Chain)
#endif

#endif // KDL_MSGS_MESSAGE_CHAIN_H
