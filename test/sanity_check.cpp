#include "gtest/gtest.h"

TEST(SanityCheck, CheckIntrinsics) {
    /* we hope that true is true */
    ASSERT_TRUE(true);

    /* these values should be equal */
    ASSERT_EQ(2, 1+1);

    int x[] = { 1, 2, 3 };
    int y[] = { 1, 2, 3 };
    for (int i = 0; i < 3; ++i) {
        EXPECT_EQ(x[i], y[i]);
    }    

    double a = 1.51;
    double b = 1.52;
    ASSERT_NE(a, b);
}
