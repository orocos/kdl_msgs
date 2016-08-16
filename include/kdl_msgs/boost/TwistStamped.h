#ifndef KDL_MSGS_BOOST_SERIALIZATION_TWISTSTAMPED_H
#define KDL_MSGS_BOOST_SERIALIZATION_TWISTSTAMPED_H

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <kdl_msgs/TwistStamped.h>
#include <std_msgs/boost/Header.h>
#include <kdl_msgs/boost/Twist.h>

namespace boost
{
namespace serialization
{

template<class Archive, class ContainerAllocator>
void serialize(Archive& a,  ::kdl_msgs::TwistStamped_<ContainerAllocator>  & m, unsigned int)
{
    a & make_nvp("header", m.header);
    a & make_nvp("twist", static_cast< ::KDL::Twist& >(m.twist));
}

} // namespace serialization
} // namespace boost

#endif // KDL_MSGS_BOOST_SERIALIZATION_TWISTSTAMPED_H

