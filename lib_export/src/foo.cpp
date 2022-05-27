#include "foo.h"
#include "dep.h"

int foo() {
  return 22 + dep();
}

int foo1() {
  return 33;
}

