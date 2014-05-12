#include <iostream>
#include <cstdlib>
#include <gtest/gtest.h>
#include <chrono>
#include <thread>
#include <future>
#include <mutex>

std::mutex g_display_mutex;

int a;
int b;
int c;
void delay()
{
    int random_integer = (std::rand() % 3) + 1;
    std::chrono::seconds dura( random_integer );
    std::this_thread::sleep_for( dura );
}
int calculateA()
{
    delay();
    return a+a*b; 
}
int calculateB()
{
    delay();
    return a*(a+a*(a+1));
}
int calculateC()
{
    delay();
    return b*(b+1)-b;
}
int calculate()
{
    a = 1;
    b = 2;
    c = calculateA()*(calculateB() + calculateC());
    return c;
}
int calculate2()
{
    a = 1;
    b = 2;
    std::future<int> f1 = std::async(calculateB);
    std::future<int> f2 = std::async(calculateC);
    c = calculateA()*(f1.get() + f2.get());
    //    c = calculateA()*(calculateB() + calculateC());
    return c;
}

auto multiple_finder = [] (int n)
{
    std::thread::id this_id = std::this_thread::get_id();
    for (int i = 0; i < 100000; i++)
    {
        if ( i%n == 0)
        {
            g_display_mutex.lock();
            std::cout << "[" << this_id << "]: " << i << " is a multiple of " << n << std::endl;
            g_display_mutex.unlock();
        }
    }
};

TEST(async_test, sync_test)
{
    EXPECT_EQ( 21, calculate());
}
TEST(async_test2, sync_test)
{
    EXPECT_EQ( 21, calculate2());
}

TEST(async_test3, sync_test)
{
    std::thread th(multiple_finder, 23456);
    multiple_finder(34567);
    th.join();
}
