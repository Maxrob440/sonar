#include <randomdistancereader.h>
#include <gtest/gtest.h>

TEST(randomdistancereader, TestGetDistance){
  RandomDistanceReader distanceReader = RandomDistanceReader(0,10);
  double distance = distanceReader.getDistance();
  ASSERT_LE(distance,10);
  ASSERT_GE(distance,0);
}
TEST(randomdistancereader,TestNegativeGetDistance){
  RandomDistanceReader distanceReader = RandomDistanceReader(-10,0);
  double distance = distanceReader.getDistance();
  ASSERT_LE(distance,0);
  ASSERT_GE(distance,-10);
}

int main(int argc, char** argv){
  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
