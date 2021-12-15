#ifndef ICE_H
#define ICE_H

#include "print_container.h"

std::ostream &operator<<(std::ostream &os, print_Container &obj);

class Ice final : public print_Container {
public:
  using value_Type = int;
  constexpr static std::size_t default_Cap{10};
  constexpr static std::size_t add_Cap{5};
  virtual void print(std::ostream &out) override;
  void add_Items(value_Type *values, std::size_t val_Size) noexcept;
  void remove(std::size_t index) noexcept;
  void removeS(std::size_t size, value_Type *values) noexcept;

public:
  explicit Ice(const Ice &obj) noexcept;
  explicit Ice(Ice &&obj) noexcept;
  Ice(std::size_t size, value_Type items[] = {}, std::size_t cap = default_Cap);
  virtual ~Ice();

  [[maybe_unused]] std::size_t get_Size() const noexcept;
  [[maybe_unused]] std::size_t get_Capacity() const noexcept;

private:
  value_Type *items;
  std::size_t _size;
  std::size_t _capacity;
  void expand(std::size_t new_Cap = add_Cap);
};

#endif // ICE_H
