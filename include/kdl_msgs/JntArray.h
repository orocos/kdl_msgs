#ifndef KDL_MSGS_MESSAGE_JNTARRAY_H
#define KDL_MSGS_MESSAGE_JNTARRAY_H

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <kdl/jntarray.hpp>

#include <kdl_msgs/util/forward_traits.h>
#include <kdl_msgs/util/serialization.h>

namespace kdl_msgs
{
#ifndef BOOST_NO_CXX11_TEMPLATE_ALIASES
// using C++11 syntax ::KDL::JntArray and kdl_msgs::JntArray_ are exactly the same type
template <typename ContainerAllocator> using JntArray_ = ::KDL::JntArray;
#else
template <class ContainerAllocator>
struct JntArray_ : public ::KDL::JntArray
{
  typedef JntArray_<ContainerAllocator> Type;
  typedef Eigen::VectorXd::Scalar value_type;

  JntArray_()
  {}
  JntArray_(const ContainerAllocator&)
  {}
  JntArray_(unsigned int size)
    : ::KDL::JntArray(size)
  {}
  JntArray_(const std::vector<value_type>& _data)
  {
    data = _data;
  }
  JntArray_(const ::KDL::JntArray& other)
    : ::KDL::JntArray(other)
  {}

  // assignment operator
  Type& operator=(const Type& rhs)
  {
    static_cast< ::KDL::JntArray&>(*this) = rhs;
    return *this;
  }
  Type& operator=(const ::KDL::JntArray& rhs)
  {
    static_cast< ::KDL::JntArray&>(*this) = rhs;
    return *this;
  }

  typedef Eigen::VectorXd _data_type;

  typedef boost::shared_ptr< ::kdl_msgs::JntArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kdl_msgs::JntArray_<ContainerAllocator> const> ConstPtr;

}; // struct JntArray_
#endif

typedef ::kdl_msgs::JntArray_<std::allocator<void> > JntArray;

typedef boost::shared_ptr< ::kdl_msgs::JntArray > JntArrayPtr;
typedef boost::shared_ptr< ::kdl_msgs::JntArray const> JntArrayConstPtr;

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kdl_msgs::JntArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kdl_msgs::JntArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}
#endif

} // namespace kdl_msgs

namespace ros
{
namespace message_traits
{

template <>
struct IsFixedSize< ::KDL::JntArray >
  : FalseType
  { };

template <>
struct IsFixedSize< ::KDL::JntArray const>
  : FalseType
  { };

template <>
struct IsMessage< ::KDL::JntArray >
  : TrueType
  { };

template <>
struct IsMessage< ::KDL::JntArray const>
  : TrueType
  { };

template <>
struct HasHeader< ::KDL::JntArray >
  : FalseType
  { };

template <>
struct HasHeader< ::KDL::JntArray const>
  : FalseType
  { };


template<>
struct MD5Sum< ::KDL::JntArray >
{
  static const char* value()
  {
    return "788898178a3da2c3718461eecda8f714";
  }

  static const char* value(const ::KDL::JntArray&) { return value(); }
  static const uint64_t static_value1 = 0x788898178a3da2c3ULL;
  static const uint64_t static_value2 = 0x718461eecda8f714ULL;
};

template<>
struct DataType< ::KDL::JntArray >
{
  static const char* value()
  {
    return "kdl_msgs/JntArray";
  }

  static const char* value(const ::KDL::JntArray&) { return value(); }
};

template<>
struct Definition< ::KDL::JntArray >
{
  static const char* value()
  {
    return "# Represents a KDL::JntArray instance.\n\
\n\
float64[] data\n\
";
  }

  static const char* value(const ::KDL::JntArray&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<> struct Serializer< ::KDL::JntArray >
  {
    template<typename Stream, typename T>
    inline static void write(Stream& stream, const T& m)
    {
      serialize(stream, m.data.data(), m.data.rows());
    }

    template<typename Stream, typename T>
    inline static void read(Stream& stream, T& m)
    {
      std::size_t size = stream.getLength() / sizeof(Eigen::VectorXd::Scalar);
      m.resize(size);
      deserialize(stream, m.data.data(), m.data.rows());
    }

    template<typename T>
    inline static uint32_t serializedLength(const T& m)
    {
      return serializationLength(m.data.data(), m.data.rows());
    }
  }; // struct JntArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<>
struct Printer< ::KDL::JntArray >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::KDL::JntArray& v)
  {
    s << indent << "data[]" << std::endl;
    for (size_t i = 0; i < v.rows(); ++i)
    {
      s << indent << "  data[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v(i));
    }
  }
};

} // namespace message_operations
} // namespace ros

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES
FORWARD_ROS_MESSAGE_TRAITS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::JntArray_<ContainerAllocator>, ::KDL::JntArray)
FORWARD_ROS_SERIALIZER_TEMPLATE(class ContainerAllocator, ::kdl_msgs::JntArray_<ContainerAllocator>, ::KDL::JntArray)
FORWARD_ROS_MESSAGE_OPERATIONS_TEMPLATE(class ContainerAllocator, ::kdl_msgs::JntArray_<ContainerAllocator>, ::KDL::JntArray)
#endif

#endif // KDL_MSGS_MESSAGE_JNTARRAY_H
