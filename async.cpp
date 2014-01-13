#include <iostream>
#include <string>
#include <thread>
#include <algorithm>
#include <future>
#include <stdexcept>

std::string fun()
{
    std::string str("Hello from future!");
    throw "Exception from task!";
    return str;
}

int main()
{
  auto ftr = std::async(&fun);
  std::cout << "Hello from main!\n";
  try {
    std::string str = ftr.get();
    std::cout << str << std::endl;
  }
  catch (char const * e) {
    std::cout << e << std::endl;
  }
  return 0;
}
