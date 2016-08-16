#ifndef KDL_MSGS_BOOST_SERIALIZATION_FRAME_H
#define KDL_MSGS_BOOST_SERIALIZATION_FRAME_H

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <kdl_msgs/Frame.h>
#include <kdl_msgs/boost/Vector.h>
#include <kdl_msgs/boost/Rotation.h>

namespace boost
{
namespace serialization
{

template<class Archive, class ContainerAllocator>
void serialize(Archive& a,  ::kdl_msgs::Frame_<ContainerAllocator>  & m, unsigned int)
{
    a & make_nvp("p", static_cast< ::KDL::Vector& >(m.p));
    a & make_nvp("M", static_cast< ::KDL::Rotation& >(m.M));
}

} // namespace serialization
} // namespace boost

#endif // KDL_MSGS_BOOST_SERIALIZATION_FRAME_H

