#ifndef KDL_MSGS_BOOST_SERIALIZATION_ROTATIONSTAMPED_H
#define KDL_MSGS_BOOST_SERIALIZATION_ROTATIONSTAMPED_H

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <kdl_msgs/RotationStamped.h>
#include <std_msgs/boost/Header.h>
#include <kdl_msgs/boost/Rotation.h>

namespace boost
{
namespace serialization
{

template<class Archive, class ContainerAllocator>
void serialize(Archive& a,  ::kdl_msgs::RotationStamped_<ContainerAllocator>  & m, unsigned int)
{
    a & make_nvp("header", m.header);
    a & make_nvp("rotation", static_cast< ::KDL::Rotation& >(m.rotation));
}

} // namespace serialization
} // namespace boost

#endif // KDL_MSGS_BOOST_SERIALIZATION_ROTATIONSTAMPED_H

