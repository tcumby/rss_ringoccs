/*  Header file where the prototypes for these functions are defined.         */
#include <rss_ringoccs/include/rss_ringoccs_math.h>
#include <limits>

#include "gtest/gtest.h"

namespace {

TEST(AbsTests, FloatTest) {
  EXPECT_NEAR(rssringoccs_Float_Abs(-1.0f), 1.0f, std::numeric_limits<float>::epsilon())
}

}
