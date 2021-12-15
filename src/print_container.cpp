#include "print_container.h"

std::ostream &operator<<(std::ostream &os, print_Container &obj) {
  obj.print(os);
  return os;
}
