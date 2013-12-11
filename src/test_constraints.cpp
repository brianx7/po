#include <gtest/gtest.h>

template<class T, class B> struct Derived_from {
  static void constraints(T* p) { B* pb = p; }
  Derived_from() { 
    void (*p)(T*) = constraints; 
  }
};

struct B { };
struct D : B { };
struct DD : D { };
struct X { };
TEST(Derived_test, d_test)
{
  Derived_from<D,B>();
}
