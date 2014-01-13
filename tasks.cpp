#include <iostream>
#include <future>
#include <chrono>
#include <vector>

using namespace std;

int square(int x)
{
  this_thread::sleep_for(chrono::milliseconds(1000));
  cout << this_thread::get_id() << endl;
  cout << x << endl;
  return x*x;
}

int main(int argc, char* argv[])
{
  cout << "main thread: " <<  this_thread::get_id() << endl;

  vector<future<int>> futures;
  for (int i = 1; i <= 20; ++i)
  {
    futures.push_back(async(&square, i));
  }
  int accum(0);
  for (auto& f : futures)
  {
    accum += f.get();
  }
  cout << "Sum of squares from 1 to 20: " << accum << endl;
  return 0;
}
