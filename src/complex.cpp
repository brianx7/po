#include <thread>
#include <mutex>
#include <iostream>
#include <vector>

struct Complex {
    std::mutex mutex;
    int i

    Complex() : i(0) {}
    void mul(int x) {
	std::lock_guard<std::mutex> lock(mutex);
	i *= x;
    }
    void div(int x) {
	std::lock_guard<std::mutex> lock(mutex);
	i /= x;
    }
    void both(int x, int y) {
	std::lock_guard<std::mutex> lock(mutex);
	mul(x);
	div(y);
    }
};
int main(int argc, char* argv[])
{
    Counter counter;
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
      threads.push_back(std::thread([&counter]() {
	    for (int i = 0; i < 100; ++i) {
		counter.increment();
	    }
	  }));
    }

    for (auto& thread : threads) {
	thread.join();
    }
    std::cout << counter.value << std::endl;
    return 0;
}
