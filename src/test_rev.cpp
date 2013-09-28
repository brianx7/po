#include <gtest/gtest.h>

void my_reverse( char* str )
{
    if (0 == str)
    {
        return;
    }
    unsigned int len(0);
    char* end = str;
    while (*end++ != 0) ++len;
    end -= 2; // back up end pointer by 2
    while (str < end)
    {
        char temp = *str;
        *str = *end;
        *end = temp;
        ++str;
        --end;
    }
}

TEST(rev_test, simple_test)
{
    char mstr[6];
    mstr[0] = 'h';
    mstr[1] = 'e';
    mstr[2] = 'l';
    mstr[3] = 'l';
    mstr[4] = 'o';
    mstr[5] = 0;
    ASSERT_STREQ(mstr, "hello");
    my_reverse(mstr);
    ASSERT_STREQ( mstr, "olleh");
}
