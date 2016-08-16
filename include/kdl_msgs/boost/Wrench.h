#ifndef KDL_MSGS_BOOST_SERIALIZATION_WRENCH_H
#define KDL_MSGS_BOOST_SERIALIZATION_WRENCH_H

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <kdl_msgs/Wrench.h>
#include <kdl_msgs/boost/Vector.h>
#include <kdl_msgs/boost/Vector.h>

namespace boost
{
namespace serialization
{

template<class Archive, class ContainerAllocator>
void serialize(Archive& a,  ::kdl_msgs::Wrench_<ContainerAllocator>  & m, unsigned int)
{
    a & make_nvp("force", static_cast< ::KDL::Vector& >(m.force));
    a & make_nvp("torque", static_cast< ::KDL::Vector& >(m.torque));
}

} // namespace serialization
} // namespace boost

#endif // KDL_MSGS_BOOST_SERIALIZATION_WRENCH_H

