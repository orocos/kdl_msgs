#ifndef KDL_MSGS_BOOST_SERIALIZATION_JNTARRAY_H
#define KDL_MSGS_BOOST_SERIALIZATION_JNTARRAY_H

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <kdl_msgs/JntArray.h>

namespace boost
{
namespace serialization
{

template<class Archive, class ContainerAllocator>
void serialize(Archive& a,  ::kdl_msgs::JntArray_<ContainerAllocator>  & m, unsigned int)
{
    a & make_nvp("data", m.data);
}

} // namespace serialization
} // namespace boost

#endif // KDL_MSGS_BOOST_SERIALIZATION_JNTARRAY_H

