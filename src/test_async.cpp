#include <iostream>
#include <gtest/gtest.h>


int a;
int b;
int c;
int calculateA()
{
    return a+a*b;
}
int calculateB()
{
    return a*(a+a*(a+1));
}
int calculateC()
{
    return b*(b+1)-b;
}
int calculate()
{
    a = 1;
    b = 2;
    c = calculateA()*(calculateB() + calculateC());
    return c;
}

TEST(async_test, sync_test)
{
    EXPECT_EQ( 21, calculate());
}
