#ifndef KDL_MSGS_MESSAGE_FRAME_H
#define KDL_MSGS_MESSAGE_FRAME_H

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <kdl/frames.hpp>

#include <kdl_msgs/Vector.h>
#include <kdl_msgs/Rotation.h>
#include <kdl_msgs/util/forward_traits.h>

namespace kdl_msgs
{
// using C++11 syntax ::KDL::Frame and kdl_msgs::Frame_ are exactly the same type
template <typename ContainerAllocator> using Frame_ = ::KDL::Frame;

typedef ::kdl_msgs::Frame_<std::allocator<void> > Frame;

typedef boost::shared_ptr< ::kdl_msgs::Frame > FramePtr;
typedef boost::shared_ptr< ::kdl_msgs::Frame const> FrameConstPtr;


} // namespace kdl_msgs

namespace ros
{
namespace message_traits
{

template <>
struct IsFixedSize< ::KDL::Frame >
  : TrueType
  { };

template <>
struct IsFixedSize< ::KDL::Frame const>
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Frame >
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Frame const>
  : TrueType
  { };

template <>
struct HasHeader< ::KDL::Frame >
  : FalseType
  { };

template <>
struct HasHeader< ::KDL::Frame const>
  : FalseType
  { };


template<>
struct MD5Sum< ::KDL::Frame >
{
  static const char* value()
  {
    return "8fafbf9f5543db8a3b54001d19dc815d";
  }

  static const char* value(const ::KDL::Frame&) { return value(); }
  static const uint64_t static_value1 = 0x8fafbf9f5543db8aULL;
  static const uint64_t static_value2 = 0x3b54001d19dc815dULL;
};

template<>
struct DataType< ::KDL::Frame >
{
  static const char* value()
  {
    return "kdl_msgs/Frame";
  }

  static const char* value(const ::KDL::Frame&) { return value(); }
};

template<>
struct Definition< ::KDL::Frame >
{
  static const char* value()
  {
    return "# Represents a KDL::Frame.\n\
\n\
Vector p\n\
Rotation M\n\
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
MSG: kdl_msgs/Rotation\n\
# Represents a KDL::Rotation instance.\n\
\n\
float64[9] data\n\
";
  }

  static const char* value(const ::KDL::Frame&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<> struct Serializer< ::KDL::Frame >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.p);
      stream.next(m.M);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Frame_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<>
struct Printer< ::KDL::Frame >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::KDL::Frame& v)
  {
    s << indent << "p: ";
    s << std::endl;
    Printer< ::kdl_msgs::Vector >::stream(s, indent + "  ", v.p);
    s << indent << "M: ";
    s << std::endl;
    Printer< ::kdl_msgs::Rotation >::stream(s, indent + "  ", v.M);
  }
};

} // namespace message_operations
} // namespace ros

#endif // KDL_MSGS_MESSAGE_FRAME_H
