#include <iostream>

#include "cord_utilities.hpp"
#include "cord.hpp"

int main() {
  SharedPointer<int> a = new int(22);
  SharedPointer<int> a_copy;
  a = a_copy;
  // SharedPointer<Cord> a = new Cord("CS_");
  // SharedPointer<Cord> copy_a = a;
  // auto copy_a_str = copy_a->ToString();
  // std::cout << copy_a_str.Get() << std::endl;
  // SharedPointer<Cord> b = new Cord("128_");
  // SharedPointer<Cord> c = ConcatCords(a, b);

  // auto c_str = c->ToString();
  // std::cout << c_str.Get() << std::endl;

  // auto res = SubString(c, 0, 3);
  // auto res_str = res->ToString();
  // std::cout << res_str.Get() << std::endl;
}
