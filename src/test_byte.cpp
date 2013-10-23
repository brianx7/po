#include <gtest/gtest.h>

struct RawBytes {
    long number_of_bytes_;
    char* bytes_;
    void copy_values(char* value) const
    {
        memcpy(value, bytes_, number_of_bytes_);
    }
};

void InitializeRawBytes(RawBytes& input)
{
    input.number_of_bytes_ = 0;
}
void PopulateRawBytes(std::string const& str, RawBytes& rb)
{
    rb.number_of_bytes_ = str.size();
    rb.bytes_ = new char[rb.number_of_bytes_];
    memcpy(rb.bytes_, str.c_str(), rb.number_of_bytes_);
}
void getrawbytes(char* rawbytes, RawBytes const& rb)
{
    rb.copy_values(rawbytes);
}
TEST(byte_test, simple_test)
{
    char mstr[6];
    mstr[0] = 'h';
    mstr[1] = 'e';
    mstr[2] = 'l';
    mstr[3] = 'l';
    mstr[4] = 'o';
    mstr[5] = 0;
    ASSERT_STREQ(mstr, "hello");
    RawBytes rb;
    InitializeRawBytes(rb);
    std::string hello("Hello");
    PopulateRawBytes(hello, rb);
    ASSERT_STREQ( hello.c_str(), rb.bytes_);
    char* rawbytes = new char[rb.number_of_bytes_];
    getrawbytes(rawbytes, rb);
    ASSERT_STREQ(rawbytes, rb.bytes_);
}
