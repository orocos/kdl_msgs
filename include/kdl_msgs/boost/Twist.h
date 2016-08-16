#ifndef KDL_MSGS_BOOST_SERIALIZATION_TWIST_H
#define KDL_MSGS_BOOST_SERIALIZATION_TWIST_H

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <kdl_msgs/Twist.h>
#include <kdl_msgs/boost/Vector.h>
#include <kdl_msgs/boost/Vector.h>

namespace boost
{
namespace serialization
{

template<class Archive, class ContainerAllocator>
void serialize(Archive& a,  ::kdl_msgs::Twist_<ContainerAllocator>  & m, unsigned int)
{
    a & make_nvp("linear", static_cast< ::KDL::Vector& >(m.linear));
    a & make_nvp("angular", static_cast< ::KDL::Vector& >(m.angular));
}

} // namespace serialization
} // namespace boost

#endif // KDL_MSGS_BOOST_SERIALIZATION_TWIST_H

