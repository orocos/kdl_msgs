#ifndef KDL_MSGS_BOOST_SERIALIZATION_VECTOR_H
#define KDL_MSGS_BOOST_SERIALIZATION_VECTOR_H

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <kdl_msgs/Vector.h>

namespace boost
{
namespace serialization
{

template<class Archive, class ContainerAllocator>
void serialize(Archive& a,  ::kdl_msgs::Vector_<ContainerAllocator>  & m, unsigned int)
{
    a & make_nvp("x", m.x);
    a & make_nvp("y", m.y);
    a & make_nvp("z", m.z);
}

} // namespace serialization
} // namespace boost

#endif // KDL_MSGS_BOOST_SERIALIZATION_VECTOR_H

