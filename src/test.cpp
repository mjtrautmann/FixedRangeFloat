#include <gtest/gtest.h>
#include "FixedRangeFloat.h"


TEST(FixedRangeFloatTest, ClassSize) {
  ASSERT_EQ(sizeof(FixedRangeFloat<0.,1.>), 1);
}

TEST(FixedRangeFloatTest, ZeroToOne) {
  FixedRangeFloat<0.,1.> f;
  f = 0.5;
  float v = f;
  EXPECT_FLOAT_EQ(0.5, v);
  f = 0;
  v = f;
  EXPECT_FLOAT_EQ(0, v);
  f = 0.25;
  v = f;
  EXPECT_FLOAT_EQ(0.25, v);
  f = 1;
  v = f;
  EXPECT_FLOAT_EQ(1, v);
  f = 2;
  v = f;
  EXPECT_FLOAT_EQ(1, v);
  f = 0.77;
  v = f;
  EXPECT_NEAR(0.77, v, f.error());
}

TEST(FixedRangeFloatTest, ThousandsRange) {
  FixedRangeFloat<1000.,5000.> f;
  for(int i = 10000; i < 50000; i++)
  {
    f = i/10;;
    float v = f;
    EXPECT_NEAR(i/10, v, f.error());
  }
}

