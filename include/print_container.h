#ifndef PRINT_CONTAINER_H
#define PRINT_CONTAINER_H

#include <ostream>
class print_Container {
public:
  virtual ~print_Container() = default;
  print_Container() = default;

private:
  friend std::ostream &operator<<(std::ostream &os, const print_Container &obj);

public:
  virtual void print(std::ostream &out) = 0;
};

#endif // PRINT_CONTAINER_H
