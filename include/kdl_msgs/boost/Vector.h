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
    a & make_nvp("x", m.data[0]);
    a & make_nvp("y", m.data[1]);
    a & make_nvp("z", m.data[2]);
}

} // namespace serialization
} // namespace boost

#endif // KDL_MSGS_BOOST_SERIALIZATION_VECTOR_H

