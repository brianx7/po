#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <queue>
using namespace std;

condition_variable cond_var;
mutex m;

int main() {
    int c = 0;
    bool done = false;
    queue<int> goods;
    bool notified = false;

    thread producer([&]() {
        for (int i = 0; i < 500; ++i) {
	  {
	    unique_lock<mutex> lock(m);
	    goods.push(i);
	    c++;
	  }
	  cond_var.notify_one();
        }
        done = true;
      });

    thread consumer([&]() {
	unique_lock<mutex> lock(m);
        while (!done) {
	  cond_var.wait(lock);
	  while (!goods.empty()) {
	    goods.pop();
	    //	    cout << "c: " << c << endl;
	    c--;
	  }
	}
	cout << "goods.size(): " << goods.size() << endl;
	while (!goods.empty()) {
	  goods.pop();
	  //	    cout << "c: " << c << endl;
	  c--;
	}
      });

    producer.join();
    consumer.join();
    cout << "Net: " << c << endl;
}
