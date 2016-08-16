#ifndef KDL_MSGS_BOOST_SERIALIZATION_VECTORSTAMPED_H
#define KDL_MSGS_BOOST_SERIALIZATION_VECTORSTAMPED_H

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <kdl_msgs/VectorStamped.h>
#include <std_msgs/boost/Header.h>
#include <kdl_msgs/boost/Vector.h>

namespace boost
{
namespace serialization
{

template<class Archive, class ContainerAllocator>
void serialize(Archive& a,  ::kdl_msgs::VectorStamped_<ContainerAllocator>  & m, unsigned int)
{
    a & make_nvp("header", m.header);
    a & make_nvp("vector", static_cast< ::KDL::Vector& >(m.vector));
}

} // namespace serialization
} // namespace boost

#endif // KDL_MSGS_BOOST_SERIALIZATION_VECTORSTAMPED_H

