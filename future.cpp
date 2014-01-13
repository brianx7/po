#include <iostream>
#include <string>
#include <thread>
#include <algorithm>
#include <future>
#include <stdexcept>

void thFun(std::promise<std::string> && prms)
{
  try {
    std::string str("Hello from future!");
    std::string strexcept = "Exception from future!";
    throw(std::runtime_error(strexcept));
    prms.set_value(str);
  } 
  catch (...) {
    prms.set_exception(std::current_exception());
  }
}

int main()
{
  std::promise<std::string> prms;
  std::future<std::string> ftr=prms.get_future();
  std::thread th(thFun, std::move(prms));
  std::cout << "Hello from main!\n";
  try {
    std::string str = ftr.get();
    std::cout << str << std::endl;
  }
  catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  th.join();
  return 0;
}
