#ifndef KDL_MSGS_BOOST_SERIALIZATION_JNTARRAYSTAMPED_H
#define KDL_MSGS_BOOST_SERIALIZATION_JNTARRAYSTAMPED_H

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <kdl_msgs/JntArrayStamped.h>
#include <std_msgs/boost/Header.h>
#include <kdl_msgs/boost/JntArray.h>

namespace boost
{
namespace serialization
{

template<class Archive, class ContainerAllocator>
void serialize(Archive& a,  ::kdl_msgs::JntArrayStamped_<ContainerAllocator>  & m, unsigned int)
{
    a & make_nvp("header", m.header);
    a & make_nvp("joints", static_cast< ::KDL::JntArray& >(m.joints);
}

} // namespace serialization
} // namespace boost

#endif // KDL_MSGS_BOOST_SERIALIZATION_JNTARRAYSTAMPED_H

