#ifndef KDL_MSGS_MESSAGE_FRAME_H
#define KDL_MSGS_MESSAGE_FRAME_H

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <kdl_msgs/Vector.h>
#include <kdl_msgs/Rotation.h>

namespace kdl_msgs
{
template <class ContainerAllocator>
struct Frame_ : public ::KDL::Frame
{
  typedef Frame_<ContainerAllocator> Type;

  Frame_()
  {}
  Frame_(const ContainerAllocator&)
  {}
  Frame_(const ::KDL::Rotation& R)
    : ::KDL::Frame(R)
  {}
  Frame_(const ::KDL::Vector& V)
    : ::KDL::Frame(V)
  {}
  Frame_(const ::KDL::Rotation& R, const ::KDL::Vector& V)
    : ::KDL::Frame(R, V)
  {}
  Frame_(const ::KDL::Frame& other)
    : ::KDL::Frame(other)
  {}

  // assignment operator
  Frame_& operator=(const ::KDL::Frame& rhs)
  {
    static_cast< ::KDL::Frame&>(*this) = rhs;
    return *this;
  }

  typedef  ::kdl_msgs::Vector_<ContainerAllocator>  _p_type;
  typedef  ::kdl_msgs::Rotation_<ContainerAllocator>  _M_type;

  typedef boost::shared_ptr< ::kdl_msgs::Frame_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kdl_msgs::Frame_<ContainerAllocator> const> ConstPtr;

}; // struct Frame_

typedef ::kdl_msgs::Frame_<std::allocator<void> > Frame;

typedef boost::shared_ptr< ::kdl_msgs::Frame > FramePtr;
typedef boost::shared_ptr< ::kdl_msgs::Frame const> FrameConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kdl_msgs::Frame_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kdl_msgs::Frame_<ContainerAllocator> >::stream(s, "", v);
return s;
}

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

template <class ContainerAllocator>
struct IsFixedSize< ::kdl_msgs::Frame_<ContainerAllocator> >
  : IsFixedSize< ::KDL::Frame >
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::kdl_msgs::Frame_<ContainerAllocator> const>
  : IsFixedSize< ::KDL::Frame const>
  { };

template <>
struct IsMessage< ::KDL::Frame >
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Frame const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kdl_msgs::Frame_<ContainerAllocator> >
  : IsMessage< ::KDL::Frame >
  { };

template <class ContainerAllocator>
struct IsMessage< ::kdl_msgs::Frame_<ContainerAllocator> const>
  : IsMessage< ::KDL::Frame const>
  { };

template <>
struct HasHeader< ::KDL::Frame >
  : FalseType
  { };

template <>
struct HasHeader< ::KDL::Frame const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kdl_msgs::Frame_<ContainerAllocator> >
  : HasHeader< ::KDL::Frame >
  { };

template <class ContainerAllocator>
struct HasHeader< ::kdl_msgs::Frame_<ContainerAllocator> const>
  : HasHeader< ::KDL::Frame const>
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

template<class ContainerAllocator>
struct MD5Sum< ::kdl_msgs::Frame_<ContainerAllocator> >
  : MD5Sum< ::KDL::Frame >
{};

template<>
struct DataType< ::KDL::Frame >
{
  static const char* value()
  {
    return "kdl_msgs/Frame";
  }

  static const char* value(const ::KDL::Frame&) { return value(); }
};

template<class ContainerAllocator>
struct DataType< ::kdl_msgs::Frame_<ContainerAllocator> >
  : DataType< ::KDL::Frame >
{};

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
# Represents a KDL::Vector.\n\
# This message is compatible to geometry_msgs/Vector3.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: kdl_msgs/Rotation\n\
# Represents a KDL::Rotation.\n\
\n\
float64[9] data\n\
";
  }

  static const char* value(const ::KDL::Frame&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::kdl_msgs::Frame_<ContainerAllocator> >
  : Definition< ::KDL::Frame >
{};

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

  template<class ContainerAllocator> struct Serializer< ::kdl_msgs::Frame_<ContainerAllocator> >
    : Serializer< ::KDL::Frame >
  {};

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

template<class ContainerAllocator>
struct Printer< ::kdl_msgs::Frame_<ContainerAllocator> >
  : Printer< ::KDL::Frame >
{};

} // namespace message_operations
} // namespace ros

#endif // KDL_MSGS_MESSAGE_FRAME_H
