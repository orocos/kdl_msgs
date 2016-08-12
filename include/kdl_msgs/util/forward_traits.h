#ifndef KDL_MSGS_FORWARD_TRAITS_H
#define KDL_MSGS_FORWARD_TRAITS_H

#include <ros/message_operations.h>
#include <ros/message_traits.h>
#include <ros/serialization.h>


#define FORWARD_ROS_MESSAGE_TRAITS_TEMPLATE(_template_args, _type, _wrapped_type) \
  namespace ros { \
  namespace message_traits { \
  \
  template < _template_args > \
  struct IsFixedSize< _type > \
    : IsFixedSize< _wrapped_type > \
    { }; \
  \
  template < _template_args > \
  struct IsFixedSize< _type const> \
    : IsFixedSize< _wrapped_type const> \
    { }; \
  \
  template < _template_args > \
  struct IsMessage< _type > \
    : IsMessage< _wrapped_type > \
    { }; \
  \
  template < _template_args > \
  struct IsMessage< _type const> \
    : IsMessage< _wrapped_type const> \
    { }; \
  \
  template < _template_args > \
  struct HasHeader< _type > \
    : HasHeader< _wrapped_type > \
    { }; \
  \
  template < _template_args > \
  struct HasHeader< _type const> \
    : HasHeader< _wrapped_type const> \
    { }; \
  \
  template< _template_args > \
  struct MD5Sum< _type > \
    : MD5Sum< _wrapped_type > \
  {}; \
  \
  template< _template_args > \
  struct DataType< _type > \
    : DataType< _wrapped_type > \
  {}; \
  \
  template< _template_args > \
  struct Definition< _type > \
    : Definition< _wrapped_type > \
  {}; \
  \
  } /* namespace message_traits */ \
  } /* namespace ros */

#define FORWARD_ROS_MESSAGE_TRAITS(_type, _wrapped_type) \
  namespace ros { \
  namespace message_traits { \
  \
  struct IsSimple< _type > \
    : IsSimple< _wrapped_type > \
    { }; \
  \
  struct IsSimple< _type const> \
    : IsSimple< _wrapped_type const> \
    { }; \
  \
  struct IsFixedSize< _type > \
    : IsFixedSize< _wrapped_type > \
    { }; \
  \
  struct IsFixedSize< _type const> \
    : IsFixedSize< _wrapped_type const> \
    { }; \
  \
  struct IsMessage< _type > \
    : IsMessage< _wrapped_type > \
    { }; \
  \
  struct IsMessage< _type const> \
    : IsMessage< _wrapped_type const> \
    { }; \
  \
  struct HasHeader< _type > \
    : HasHeader< _wrapped_type > \
    { }; \
  \
  struct HasHeader< _type const> \
    : HasHeader< _wrapped_type const> \
    { }; \
  \
  struct MD5Sum< _type > \
    : MD5Sum< _wrapped_type > \
  {}; \
  \
  struct DataType< _type > \
    : DataType< _wrapped_type > \
  {}; \
  \
  struct Definition< _type > \
    : Definition< _wrapped_type > \
  {}; \
  \
  } /* namespace message_traits */ \
  } /* namespace ros */

#define FORWARD_ROS_SERIALIZER_TEMPLATE(_template_args, _type, _wrapped_type) \
  namespace ros { \
  namespace serialization { \
    template< _template_args > struct Serializer< _type > \
      : Serializer< _wrapped_type > \
    {}; \
  } /* namespace serialization */ \
  } /* namespace ros */

#define FORWARD_ROS_SERIALIZER(_type, _wrapped_type) \
  namespace ros { \
  namespace serialization { \
    struct Serializer< _type > \
      : Serializer< _wrapped_type > \
    {}; \
  } /* namespace serialization */ \
  } /* namespace ros */

#define FORWARD_ROS_MESSAGE_OPERATIONS_TEMPLATE(_template_args, _type, _wrapped_type) \
  namespace ros { \
  namespace message_operations { \
  \
  template< _template_args > \
  struct Printer< _type > \
    : Printer< _wrapped_type > \
  {}; \
  \
  } /* namespace message_operations */ \
  } /* namespace ros */

#define FORWARD_ROS_MESSAGE_OPERATIONS(_type, _wrapped_type) \
  namespace ros { \
  namespace message_operations { \
  \
  struct Printer< _type > \
    : Printer< _wrapped_type > \
  {}; \
  \
  } /* namespace message_operations */ \
  } /* namespace ros */

#endif // KDL_MSGS_FORWARD_TRAITS_H
