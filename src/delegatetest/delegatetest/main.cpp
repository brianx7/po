//
//  main.cpp
//  delegatetest
//
//  Created by Brian McAndrews on 3/11/14.
//  Copyright (c) 2014 Brian McAndrews. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

#include <chrono>
#include "delegate.h"

class A
{
    int z;
public:
    A() : z(2) {}
    int foo(int x)
    {
        return x * x * z;
    }
    int bar(int x, int y, char a)
    {
        return x*y * z;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> v;
    v.resize(6);
    std::vector<int> v2 = {1,2,3,4,5,6};
    std::cout << v.size() << std::endl;
    std::transform(v.begin(),v.end(), [&v2](std::vector<int>::iterator it) { *it =
    A a;
    typedef std::chrono::duration<int,std::milli> millisec_t;
    if (argc == 2)
    {
        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
        auto d = DELEGATE(&A::foo,&a);
        long long k = 0;
        for (int i = 0; i < 10000000; ++i)
        {
            k += d(i);
        }
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << k << std::endl;
        millisec_t duration( std::chrono::duration_cast<millisec_t>(end-start));
        std::cout << duration.count() << " milliseconds.\n";
        std::cout << "Delegate with return value: d(5)=" <<  d(5) << std::endl;
    }
//    auto d = Delegate<int, int>::from_function<A, &A::foo>(&a);
    else
    {
        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
        std::function<int(int)> d2 = std::bind(&A::foo, a, std::placeholders::_1);
        long long k = 0;
        for (int i = 0; i < 10000000; ++i)
        {
            k += d2(i);
        }
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << k << std::endl;
        millisec_t duration( std::chrono::duration_cast<millisec_t>(end-start));
        std::cout << duration.count() << " milliseconds.\n";
        std::cout << "std::function with return value: d2(4)=" << d2(4) << std::endl;
    }
//    auto d2 = DELEGATE(&A::bar,&a);
//    auto d2 = Delegate<int, int, int, char>::from_function<A, &A::bar>(&a);
//    std::cout << "for d2: d2(42, 2, 'a')=" << d2(42, 2, 'a') << std::endl;
    return 0;
}