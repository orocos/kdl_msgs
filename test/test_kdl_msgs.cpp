#include <kdl_msgs/Frame.h>
#include <kdl_msgs/Rotation.h>
#include <kdl_msgs/Vector.h>

#include <gtest/gtest.h>
#include <boost/type_traits/is_base_of.hpp>

#define TEST_MESSAGE(_type, _base_class, _md5sum) \
  typedef boost::is_base_of<_base_class, kdl_msgs::_type> IsBaseOfKDLType; \
  EXPECT_TRUE(IsBaseOfKDLType::value); \
  \
  /* constructors and assignment */ \
  { \
    kdl_msgs::_type c1; \
    kdl_msgs::_type c2(_base_class()); \
    c1 = _base_class(); \
  } \
  \
  EXPECT_FALSE(ros::message_traits::IsSimple<kdl_msgs::_type>::value); \
  EXPECT_TRUE(ros::message_traits::IsFixedSize<kdl_msgs::_type>::value); \
  EXPECT_FALSE(ros::message_traits::HasHeader<kdl_msgs::_type>::value); \
  EXPECT_TRUE(ros::message_traits::IsMessage<kdl_msgs::_type>::value); \
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

  TEST_MESSAGE(Vector, KDL::Vector, "4a842b65f413084dc2b10fb484ea7f17");

  // non-default constructors
  kdl_msgs::Vector c2(0.0, 1.0, 2.0);
}

TEST(TestKdlMsgs, Rotation)
{
  KDL::Rotation sample(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
  kdl_msgs::Rotation msg(sample);
  EXPECT_EQ(sample, msg);

  TEST_MESSAGE(Rotation, KDL::Rotation, "ca66b32e4ad9de837a30ea9fe5ade752");

  // non-default constructors
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

  // non-default constructors
  kdl_msgs::Frame c2(KDL::Rotation(), KDL::Vector());
  kdl_msgs::Frame c3(KDL::Rotation());
  kdl_msgs::Frame c4(KDL::Vector());
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
