#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

#include <gtest/gtest.h>
namespace {

  struct Address {
    std::string street;
    std::string city;
    std::string state;
  };

  typedef std::vector<Address> AddressVector;

  class AddressBook
  {
  public:
    AddressBook(AddressVector const& addresses)
      : _addresses(addresses)
    {}
    AddressVector findMatchingAddresses(std::function<bool (const Address&)> func)
    {
      AddressVector results;
      std::copy_if(_addresses.begin(),
		    _addresses.end(),std::back_inserter(results),
		    [func](Address const& address)
		    {
		      if (func( address ))
		      {
			return true;
		      }
		      return false;
		    });
      return results;
    }
  private:
    AddressVector _addresses;
  };

  std::function<int (int)> multiply_by_2()
  {
    std::function<int (int)> func;
    func = [](int x) -> int { return 2*x; };
    return func;
  }
}
TEST(po_test, lambda_test)
{
  AddressVector addresses{{"1600 Pennsylvania Avenue", "Washingtion DC", ""},
    {"440 S LaSalle", "Chicago", "Il"},
    {"400 S LaSalle", "Chicago", "Il"},
    {"2057 Plainfield Dr", "Des Plaines", "Il"}};

  AddressBook ab(addresses);
  std::vector<Address> results;

  results = ab.findMatchingAddresses([] (Address const& addr) { return addr.city.find("Chicago") != std::string::npos; });
  EXPECT_EQ(results.size(), 2);
  results.clear();
  results = ab.findMatchingAddresses([] (Address const& addr) { return addr.state.find("Il") != std::string::npos; });
  EXPECT_EQ(results.size(), 3);
  results.clear();
  results = ab.findMatchingAddresses([] (Address const& addr) { return addr.street.find("S LaSalle") != std::string::npos; });
  EXPECT_EQ(results.size(), 2)
    << "results = " << ::testing::PrintToString(results);
  EXPECT_EQ(results[0].street, "440 S LaSalle");
  EXPECT_EQ(results[1].street, "400 S LaSalle");
  results = ab.findMatchingAddresses([] (Address const& addr) { return addr.street.find("1313 Mockingbird Ln") != std::string::npos; });
  EXPECT_EQ(results.size(), 0)
    << "results = " << ::testing::PrintToString(results);
 }

TEST(po_test,lambda_test2)
{
  std::function<int (int)> func = multiply_by_2();
  int n = func(4);
  EXPECT_EQ(8, n)
    << "results = " << ::testing::PrintToString(n);
  EXPECT_EQ(1024, func(512))
    << "results = " << ::testing::PrintToString(func(512));
  EXPECT_EQ(1024, multiply_by_2()(512))
    << "results = " << ::testing::PrintToString(multiply_by_2()(512));
  
}

