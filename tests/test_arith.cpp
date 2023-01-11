#include "arith.hpp"
#include "gtest/gtest.h"

TEST(arith, add) { EXPECT_EQ(3, arith::add(1, 2)); }
