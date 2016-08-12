//#include <kdl_msgs/Chain.h>
#include <kdl_msgs/Frame.h>
#include <kdl_msgs/FrameStamped.h>
//#include <kdl_msgs/Jacobian.h>
#include <kdl_msgs/JntArray.h>
#include <kdl_msgs/JntArrayStamped.h>
//#include <kdl_msgs/Joint.h>
//#include <kdl_msgs/RigidBodyInertia.h>
#include <kdl_msgs/Rotation.h>
#include <kdl_msgs/RotationStamped.h>
//#include <kdl_msgs/RotationalInertia.h>
//#include <kdl_msgs/Segment.h>
#include <kdl_msgs/Twist.h>
#include <kdl_msgs/TwistStamped.h>
#include <kdl_msgs/Vector.h>
#include <kdl_msgs/VectorStamped.h>
#include <kdl_msgs/Wrench.h>
#include <kdl_msgs/WrenchStamped.h>

#include <gtest/gtest.h>
#include <boost/type_traits/is_base_of.hpp>

#define EXPECT_ROS_MESSAGE_TRAITS_TRUE(_trait) \
  { \
    typedef boost::is_base_of< ros::message_traits::TrueType, _trait > IsBaseOf; \
    GTEST_TEST_BOOLEAN_(IsBaseOf::value, #_trait, false, true, \
                        GTEST_NONFATAL_FAILURE_); \
  }

#define EXPECT_ROS_MESSAGE_TRAITS_FALSE(_trait) \
  { \
    typedef boost::is_base_of< ros::message_traits::FalseType, _trait > IsBaseOf; \
    GTEST_TEST_BOOLEAN_(IsBaseOf::value, #_trait, true, false, \
                        GTEST_NONFATAL_FAILURE_); \
  }

#define TEST_MESSAGE(_type, _base_class, _md5sum, _is_fixed_size) \
  typedef boost::is_base_of<_base_class, kdl_msgs::_type> IsBaseOfKDLType; \
  EXPECT_TRUE(IsBaseOfKDLType::value); \
  \
  /* constructors and assignment */ \
  { \
    kdl_msgs::_type c1; \
    kdl_msgs::_type c2(_base_class()); \
    c1 = sample; \
    EXPECT_EQ(sample, c1); \
  } \
  \
  EXPECT_ROS_MESSAGE_TRAITS_FALSE(ros::message_traits::IsSimple<kdl_msgs::_type>); \
  if (_is_fixed_size) { \
    EXPECT_ROS_MESSAGE_TRAITS_TRUE(ros::message_traits::IsFixedSize<kdl_msgs::_type>); \
  } else { \
    EXPECT_ROS_MESSAGE_TRAITS_FALSE(ros::message_traits::IsFixedSize<kdl_msgs::_type>); \
  } \
  EXPECT_ROS_MESSAGE_TRAITS_FALSE(ros::message_traits::HasHeader<kdl_msgs::_type>); \
  EXPECT_ROS_MESSAGE_TRAITS_TRUE(ros::message_traits::IsMessage<kdl_msgs::_type>); \
  \
  EXPECT_STREQ(_md5sum, ros::message_traits::MD5Sum<kdl_msgs::_type>::value()); \
  EXPECT_STREQ("kdl_msgs/" # _type, ros::message_traits::DataType<kdl_msgs::_type>::value()); \
  EXPECT_TRUE(ros::message_traits::Definition<kdl_msgs::_type>::value()); \
  \
  /* serialization */ \
  { \
    using namespace ros::serialization; \
    uint32_t length = serializationLength(sample); \
    boost::shared_array<uint8_t> buf(new uint8_t[length]); \
    OStream os(buf.get(), length); \
    ros::serialization::serialize(os, sample); \
    EXPECT_EQ(0, os.getLength()); \
    IStream is(buf.get(), length); \
    kdl_msgs::_type copy; \
    ros::serialization::deserialize(is, copy); \
    EXPECT_EQ(0, is.getLength()); \
    EXPECT_EQ(sample, copy); \
  }

TEST(TestKdlMsgs, Vector)
{
  KDL::Vector sample(0.0, 1.0, 2.0);
  kdl_msgs::Vector msg(sample);
  EXPECT_EQ(sample, msg);

  TEST_MESSAGE(Vector, KDL::Vector, "4a842b65f413084dc2b10fb484ea7f17", true);

  // non-default constructors
  kdl_msgs::Vector c2(0.0, 1.0, 2.0);

  // operators
  kdl_msgs::Vector sum = msg + sample;
  kdl_msgs::Vector diff = msg - sample;
  kdl_msgs::Vector mul1 = msg * 2.0;
  kdl_msgs::Vector mul2 = 2.0 * msg;
  kdl_msgs::Vector div1 = msg / 2.0;
  kdl_msgs::Vector cross = msg * msg;
}

TEST(TestKdlMsgs, Rotation)
{
  KDL::Rotation sample(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
  kdl_msgs::Rotation msg(sample);
  EXPECT_EQ(sample, msg);

  TEST_MESSAGE(Rotation, KDL::Rotation, "ca66b32e4ad9de837a30ea9fe5ade752", true);

  // non-default constructors
  kdl_msgs::Rotation c2(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
  kdl_msgs::Rotation c3(KDL::Vector(), KDL::Vector(), KDL::Vector());

  // operators
}

TEST(TestKdlMsgs, Frame)
{
  KDL::Frame sample(
        KDL::Rotation(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0),
        KDL::Vector(0.0, 1.0, 2.0));
  kdl_msgs::Frame msg(sample);
  EXPECT_EQ(sample, msg);

  TEST_MESSAGE(Frame, KDL::Frame, "8fafbf9f5543db8a3b54001d19dc815d", true);

  // non-default constructors
  kdl_msgs::Frame c2(KDL::Rotation(), KDL::Vector());
  kdl_msgs::Frame c3(KDL::Rotation());
  kdl_msgs::Frame c4(KDL::Vector());

  // operators
}

TEST(TestKdlMsgs, Twist)
{
  KDL::Twist sample(
        KDL::Vector(0.0, 1.0, 2.0),
        KDL::Vector(3.0, 4.0, 5.0));
  kdl_msgs::Twist msg(sample);
  EXPECT_EQ(sample, msg);

  TEST_MESSAGE(Twist, KDL::Twist, "9f195f881246fdfa2798d1d3eebca84a", true);

  // non-default constructors
  kdl_msgs::Twist c2(KDL::Vector(), KDL::Vector());

  // operators
}

TEST(TestKdlMsgs, Wrench)
{
  KDL::Wrench sample(
        KDL::Vector(0.0, 1.0, 2.0),
        KDL::Vector(3.0, 4.0, 5.0));
  kdl_msgs::Wrench msg(sample);
  EXPECT_EQ(sample, msg);

  TEST_MESSAGE(Wrench, KDL::Wrench, "4f539cf138b23283b520fd271b567936", true);

  // non-default constructors
  kdl_msgs::Wrench c2(KDL::Vector(), KDL::Vector());

  // operators
}

//namespace KDL {
//  static bool operator==(const ::KDL::Chain& lhs, const ::KDL::Chain& rhs)
//  {
//    return // (lhs.getNrOfJoints() == rhs.getNrOfJoints()) &&
//           // (lhs.getNrOfSegments() == rhs.getNrOfSegments()) &&
//           (lhs.segments.size() == rhs.segments.size()) &&
//           std::equal(lhs.segments.begin(), lhs.segments.end(), rhs.segments.begin());
//  }

//  std::ostream& operator<<(std::ostream& os, const ::KDL::Chain& value)
//  {
//    ros::message_operations::Printer< ::KDL::Chain >::stream(os, "", value);
//    return os;
//  }
//}

//TEST(TestKdlMsgs, Chain)
//{
//  KDL::Chain sample;
//  sample.addSegment(KDL::Segment());
//  kdl_msgs::Chain msg(sample);
//  EXPECT_EQ(sample, msg);

//  TEST_MESSAGE(Chain, KDL::Chain, "0ff773f05fc4dbf531922f1a3d7bdaec", false);

//  // non-default constructors

//  // operators
//}

TEST(TestKdlMsgs, JntArray)
{
  KDL::JntArray sample(6);
  kdl_msgs::JntArray msg(sample);
  EXPECT_EQ(sample, msg);

  TEST_MESSAGE(JntArray, KDL::JntArray, "788898178a3da2c3718461eecda8f714", false);

  // non-default constructors
  kdl_msgs::JntArray c2(6);

  // operators
}

//TEST(TestKdlMsgs, Jacobian)
//{
//  KDL::Jacobian sample(3);
//  kdl_msgs::Jacobian msg(sample);
//  EXPECT_EQ(sample, msg);

//  TEST_MESSAGE(Jacobian, KDL::Jacobian, "788898178a3da2c3718461eecda8f714", false);

//  // non-default constructors
//  kdl_msgs::Jacobian c2(3);

//  // operators
//}

//namespace KDL {
//  static bool operator==(const ::KDL::Joint& lhs, const ::KDL::Joint& rhs)
//  {
//    return (lhs.getName() == rhs.getName()) &&
//           (lhs.getType() == rhs.getType()) &&
////           (lhs.scale == rhs.scale) &&
////           (lhs.offset == rhs.offset) &&
////           (lhs.inertia == rhs.inertia) &&
////           (lhs.damping == rhs.damping) &&
////           (lhs.stiffness == rhs.stiffness) &&
//           (lhs.JointOrigin() == rhs.JointOrigin()) &&
//           (lhs.JointAxis() == rhs.JointAxis());
//  }

//  std::ostream& operator<<(std::ostream& os, const ::KDL::Joint& value)
//  {
//    ros::message_operations::Printer< ::KDL::Joint >::stream(os, "", value);
//    return os;
//  }
//}

//TEST(TestKdlMsgs, Joint)
//{
//  KDL::Joint sample("foo", KDL::Vector(0.0, 1.0, 2.0), KDL::Vector(3.0, 4.0, 5.0),
//                    KDL::Joint::RotAxis, 6.0, 7.0, 8.0, 9.0, 10.0);
//  kdl_msgs::Joint msg(sample);
//  EXPECT_EQ(sample, msg);

//  TEST_MESSAGE(Joint, KDL::Joint, "4f8448d28309edc7c24ce443bb15110a", false);

//  // non-default constructors
//  kdl_msgs::Joint c2(KDL::Vector(0.0, 1.0, 2.0), KDL::Vector(3.0, 4.0, 5.0),
//                     KDL::Joint::RotAxis, 6.0, 7.0, 8.0, 9.0, 10.0);
//  kdl_msgs::Joint c3("bar", KDL::Joint::RotX, 6.0, 7.0, 8.0, 9.0, 10.0);
//  kdl_msgs::Joint c4(KDL::Joint::RotX, 6.0, 7.0, 8.0, 9.0, 10.0);

//  // operators
//}

//namespace KDL {
//  static bool operator==(const ::KDL::RotationalInertia& lhs, const ::KDL::RotationalInertia& rhs)
//  {
//    return std::equal(lhs.data, lhs.data + 9, rhs.data);
//  }

//  static bool operator==(const ::KDL::RigidBodyInertia& lhs, const ::KDL::RigidBodyInertia& rhs)
//  {
//    return (lhs.getMass() == rhs.getMass()) &&
//           (lhs.getCOG() == rhs.getCOG()) &&
//           (lhs.getRotationalInertia() == rhs.getRotationalInertia());
//  }

//  std::ostream& operator<<(std::ostream& os, const ::KDL::RotationalInertia& value)
//  {
//    ros::message_operations::Printer< ::KDL::RotationalInertia >::stream(os, "", value);
//    return os;
//  }

//  std::ostream& operator<<(std::ostream& os, const ::KDL::RigidBodyInertia& value)
//  {
//    ros::message_operations::Printer< ::KDL::RigidBodyInertia >::stream(os, "", value);
//    return os;
//  }
//}

//TEST(TestKdlMsgs, RigidBodyInertia)
//{
//  KDL::RigidBodyInertia sample(6);
//  kdl_msgs::RigidBodyInertia msg(sample);
//  EXPECT_EQ(sample, msg);

//  TEST_MESSAGE(RigidBodyInertia, KDL::RigidBodyInertia, "33096aa337b8b33a05f701d90acdd33b", true);

//  // non-default constructors
//  kdl_msgs::RigidBodyInertia c2(6);

//  // operators
//}

//TEST(TestKdlMsgs, RotationalInertia)
//{
//  KDL::RotationalInertia sample(6);
//  kdl_msgs::RotationalInertia msg(sample);
//  EXPECT_EQ(sample, msg);

//  TEST_MESSAGE(RotationalInertia, KDL::RotationalInertia, "ca66b32e4ad9de837a30ea9fe5ade752", true);

//  // non-default constructors
//  kdl_msgs::RotationalInertia c2(6);

//  // operators
//}

//namespace KDL {
//  static bool operator==(const ::KDL::Segment& lhs, const ::KDL::Segment& rhs)
//  {
//    return (lhs.getName() == rhs.getName()) &&
//           (lhs.getJoint() == rhs.getJoint()) &&
//           (lhs.getFrameToTip() == rhs.getFrameToTip()) &&
//           (lhs.getInertia() == rhs.getInertia());
//  }

//  std::ostream& operator<<(std::ostream& os, const ::KDL::Segment& value)
//  {
//    ros::message_operations::Printer< ::KDL::Segment >::stream(os, "", value);
//    return os;
//  }
//}

//TEST(TestKdlMsgs, Segment)
//{
//  KDL::Segment sample("foo",
//                      ::KDL::Joint("foo", KDL::Vector(0.0, 1.0, 2.0), KDL::Vector(3.0, 4.0, 5.0),
//                                   KDL::Joint::RotAxis, 6.0, 7.0, 8.0, 9.0, 10.0),
//                      ::KDL::Frame::Identity(), ::KDL::RigidBodyInertia::Zero());
//  kdl_msgs::Segment msg(sample);
//  EXPECT_EQ(sample, msg);

//  TEST_MESSAGE(Segment, KDL::Segment, "ea2f787ad0b4c61e6da4d0592adf35fd", false);

//  // non-default constructors
//  kdl_msgs::Segment c2("bar",
//                       ::KDL::Joint("bar", KDL::Vector(0.0, 1.0, 2.0), KDL::Vector(3.0, 4.0, 5.0),
//                                    KDL::Joint::RotAxis, 6.0, 7.0, 8.0, 9.0, 10.0),
//                       ::KDL::Frame::Identity(), ::KDL::RigidBodyInertia::Zero());
//  kdl_msgs::Segment c3(::KDL::Joint(KDL::Vector(0.0, 1.0, 2.0), KDL::Vector(3.0, 4.0, 5.0),
//                                    KDL::Joint::RotAxis, 6.0, 7.0, 8.0, 9.0, 10.0),
//                       ::KDL::Frame::Identity(), ::KDL::RigidBodyInertia::Zero());

//  // operators
//}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
