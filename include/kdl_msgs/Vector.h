#ifndef KDL_MSGS_MESSAGE_VECTOR_H
#define KDL_MSGS_MESSAGE_VECTOR_H

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <kdl/frames.hpp>

#include <kdl_msgs/util/serialization.h>

namespace kdl_msgs
{
template <class ContainerAllocator>
struct Vector_ : public ::KDL::Vector
{
  typedef Vector_<ContainerAllocator> Type;
  typedef double value_type;

  Vector_()
  {}
  Vector_(const ContainerAllocator&)
  {}
  Vector_(value_type x, value_type y, value_type z)
    : ::KDL::Vector(x, y, z)
  {}
  Vector_(const value_type (&array)[3])
    : ::KDL::Vector(array[0], array[1], array[2])
  {}
  Vector_(const ::KDL::Vector& other)
    : ::KDL::Vector(other)
  {}

  // assignment operator
  Vector_& operator=(const ::KDL::Vector& rhs)
  {
    static_cast< ::KDL::Vector&>(*this) = rhs;
    return *this;
  }

  typedef value_type _data_type[3];
  typedef value_type _x_type;
  typedef value_type _y_type;
  typedef value_type _z_type;

  typedef boost::shared_ptr< ::kdl_msgs::Vector_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kdl_msgs::Vector_<ContainerAllocator> const> ConstPtr;

}; // struct Vector_

typedef ::kdl_msgs::Vector_<std::allocator<void> > Vector;

typedef boost::shared_ptr< ::kdl_msgs::Vector > VectorPtr;
typedef boost::shared_ptr< ::kdl_msgs::Vector const> VectorConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kdl_msgs::Vector_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kdl_msgs::Vector_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace kdl_msgs

namespace ros
{
namespace message_traits
{

template <>
struct IsFixedSize< ::KDL::Vector >
  : TrueType
  { };

template <>
struct IsFixedSize< ::KDL::Vector const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::kdl_msgs::Vector_<ContainerAllocator> >
  : IsFixedSize< ::KDL::Vector >
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::kdl_msgs::Vector_<ContainerAllocator> const>
  : IsFixedSize< ::KDL::Vector const>
  { };

template <>
struct IsMessage< ::KDL::Vector >
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::Vector const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kdl_msgs::Vector_<ContainerAllocator> >
  : IsMessage< ::KDL::Vector >
  { };

template <class ContainerAllocator>
struct IsMessage< ::kdl_msgs::Vector_<ContainerAllocator> const>
  : IsMessage< ::KDL::Vector const>
  { };

template <>
struct HasHeader< ::KDL::Vector >
  : FalseType
  { };

template <>
struct HasHeader< ::KDL::Vector const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kdl_msgs::Vector_<ContainerAllocator> >
  : HasHeader< ::KDL::Vector >
  { };

template <class ContainerAllocator>
struct HasHeader< ::kdl_msgs::Vector_<ContainerAllocator> const>
  : HasHeader< ::KDL::Vector const>
  { };


template<>
struct MD5Sum< ::KDL::Vector >
{
  static const char* value()
  {
    return "4a842b65f413084dc2b10fb484ea7f17";
  }

  static const char* value(const ::KDL::Vector&) { return value(); }
  static const uint64_t static_value1 = 0x4a842b65f413084dULL;
  static const uint64_t static_value2 = 0xc2b10fb484ea7f17ULL;
};

template<class ContainerAllocator>
struct MD5Sum< ::kdl_msgs::Vector_<ContainerAllocator> >
  : MD5Sum< ::KDL::Vector >
{};

template<>
struct DataType< ::KDL::Vector >
{
  static const char* value()
  {
    return "kdl_msgs/Vector";
  }

  static const char* value(const ::KDL::Vector&) { return value(); }
};

template<class ContainerAllocator>
struct DataType< ::kdl_msgs::Vector_<ContainerAllocator> >
  : DataType< ::KDL::Vector >
{};

template<>
struct Definition< ::KDL::Vector >
{
  static const char* value()
  {
    return "# Represents a KDL::Vector.\n\
# This message is compatible to geometry_msgs/Vector3.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::KDL::Vector&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::kdl_msgs::Vector_<ContainerAllocator> >
  : Definition< ::KDL::Vector >
{};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{
  template<> struct Serializer< ::KDL::Vector >
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
  }; // struct Vector_

  template<class ContainerAllocator> struct Serializer< ::kdl_msgs::Vector_<ContainerAllocator> >
    : Serializer< ::KDL::Vector >
  {};

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<>
struct Printer< ::KDL::Vector >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::KDL::Vector& v)
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.data[0]);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.data[1]);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.data[2]);
  }
};

template<class ContainerAllocator>
struct Printer< ::kdl_msgs::Vector_<ContainerAllocator> >
  : Printer< ::KDL::Vector >
{};

} // namespace message_operations
} // namespace ros

#endif // KDL_MSGS_MESSAGE_VECTOR_H
