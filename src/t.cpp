#include <vector>
#include <cstring>
#include <iostream>
#include <boost/assign.hpp>

struct A
{
    A()
    { std::memset(this,0, sizeof(struct A)); }
    double x;
    double y;
    std::vector<double> vec;
};

int main (int argc, char* argv[])
{
    std::vector<double> v;
    v = boost::assign::list_of(1.0)(0.95);
    std::cout << v.size() << std::endl;
    return 0;
}
