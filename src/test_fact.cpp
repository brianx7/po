#include <iostream>
#include <gtest/gtest.h>

int fact(int n)
{
    if (n==0)
        return 1;
    return n*fact(n-1);
}

TEST(fact_test, five_test)
{
    EXPECT_EQ(fact(5),120);
}
