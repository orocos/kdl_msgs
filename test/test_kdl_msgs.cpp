#include <kdl_msgs/Frame.h>
#include <kdl_msgs/Rotation.h>
#include <kdl_msgs/Vector.h>

#include <gtest/gtest.h>
#include <boost/type_traits/is_base_of.hpp>

#define TEST_MESSAGE(_type, _base_class, _md5sum) \
  typedef boost::is_base_of<_base_class, kdl_msgs::_type> IsBaseOfKDLType; \
  EXPECT_TRUE(IsBaseOfKDLType::value); \
  \
  EXPECT_FALSE(ros::message_traits::IsSimple<kdl_msgs::_type>::value); \
  EXPECT_TRUE(ros::message_traits::IsFixedSize<kdl_msgs::_type>::value); \
  EXPECT_FALSE(ros::message_traits::HasHeader<kdl_msgs::_type>::value); \
  EXPECT_TRUE(ros::message_traits::IsMessage<kdl_msgs::_type>::value); \
  \
  EXPECT_STREQ(ros::message_traits::MD5Sum<kdl_msgs::_type>::value(), _md5sum); \
  EXPECT_STREQ(ros::message_traits::DataType<kdl_msgs::_type>::value(), "kdl_msgs/" # _type); \
  EXPECT_TRUE(ros::message_traits::Definition<kdl_msgs::_type>::value()); \

TEST(TestKdlMsgs, Vector)
{
  KDL::Vector sample(0.0, 1.0, 2.0);
  kdl_msgs::Vector msg(sample);
  EXPECT_EQ(sample, msg);

  TEST_MESSAGE(Vector, KDL::Vector, "4a842b65f413084dc2b10fb484ea7f17");

  // constructors
  kdl_msgs::Vector c1();
  kdl_msgs::Vector c2(0.0, 1.0, 2.0);
}

TEST(TestKdlMsgs, Rotation)
{
  KDL::Rotation sample(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
  kdl_msgs::Rotation msg(sample);
  EXPECT_EQ(sample, msg);

  TEST_MESSAGE(Rotation, KDL::Rotation, "ca66b32e4ad9de837a30ea9fe5ade752");

  // constructors
  kdl_msgs::Rotation c1();
  kdl_msgs::Rotation c2(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
  kdl_msgs::Rotation c3(KDL::Vector(), KDL::Vector(), KDL::Vector());
}

TEST(TestKdlMsgs, Frame)
{
  KDL::Frame sample(
        KDL::Rotation(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0),
        KDL::Vector(0.0, 1.0, 2.0));
  kdl_msgs::Frame msg(sample);
  EXPECT_EQ(sample, msg);

  TEST_MESSAGE(Frame, KDL::Frame, "8fafbf9f5543db8a3b54001d19dc815d");

  // constructors
  kdl_msgs::Frame c1();
  kdl_msgs::Frame c2(KDL::Rotation(), KDL::Vector());
  kdl_msgs::Frame c3(KDL::Rotation());
  kdl_msgs::Frame c4(KDL::Vector());
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
