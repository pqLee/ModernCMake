#include "bar.h"
#include "dep.h"
#include <iostream>

int main() {
  std::cout << "From foo(): " << foo() << std::endl;
  std::cout << "From bar(): " << bar() << std::endl;
  std::cout << "From bar(): " << dep() << std::endl;
  return 0;
}

