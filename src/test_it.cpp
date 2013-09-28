#include <iostream>
#include <vector>
#include <string>
#include <gtest/gtest.h>

void foo( int* values)
{
    for (int i = 0; i < 3; ++i)
    {
        *(values+i) *= 2;
    }
}

TEST(double_test, vect_begin)
{
    std::vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    // foo(v.begin());  will not compile, can't convert iterator to int*
    foo(&(v[0]));
    EXPECT_EQ(v[0], 2);
    EXPECT_EQ(v[1], 4);
    EXPECT_EQ(v[2], 6);
}
