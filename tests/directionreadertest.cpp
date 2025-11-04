#include <directionreader.h>
#include <gtest/gtest.h>


TEST(directionreader, testGetDirection){
  DirectionReader directionReader = DirectionReader(-65); // No GPIO
  double direction = directionReader.getDirection();
  ASSERT_LE(direction,90);
  ASSERT_GE(direction,-90);
}

TEST(directionreader, testGetDirectionRadians){
  DirectionReader directionReader = DirectionReader(-65);
  double direction = directionReader.getDirection();
  double directionRadians = directionReader.getRadiansDirection();

  ASSERT_NEAR(direction,directionRadians*57.296,1);
}

TEST(directionreader, testMoveDirection){
  DirectionReader directionReader = DirectionReader(-65);
  double direction = directionReader.getDirection();
  directionReader.moveDirection(10);
  double newDirection = directionReader.getDirection();
  ASSERT_GT(newDirection,direction);
}

TEST(directionreader, testBounce){
  DirectionReader directionReader = DirectionReader(-65);
  while (directionReader.getDirection()<89){
    directionReader.moveDirection(10);
  }
  double direction = directionReader.getDirection();
  directionReader.moveDirection(15);
  double newdirection = directionReader.getDirection();
  ASSERT_LT(newdirection,direction);
}

int main(int argc,char** argv){
  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
