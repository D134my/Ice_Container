#include "ice.h"

Ice::Ice(std::size_t size, value_Type items[], std::size_t cap)
    : _size(size), _capacity(cap) {
  this->items = new value_Type[_capacity];
  for (std::size_t i{}; i < _size; ++i)
    this->items[i] = items[i];
}

Ice::Ice(const Ice &obj) noexcept {
  this->_size = obj._size;
  this->_capacity = obj._capacity;
  this->items = new value_Type[obj._capacity];
  for (std::size_t i{}; i < obj._size; ++i)
    this->items[i] = obj.items[i];
}

Ice::Ice(Ice &&obj) noexcept {
  this->_size = std::move(obj._size);
  this->_capacity = std::move(obj._capacity);
  this->items = new value_Type[obj._capacity];
  for (std::size_t i{}; i < obj._size; ++i)
    this->items[i] = std::move(obj.items[i]);
  obj.items = nullptr;
}

Ice::~Ice() {
  delete[] items;
  items = nullptr;
}

std::size_t Ice::get_Size() const noexcept { return _size; }
std::size_t Ice::get_Capacity() const noexcept { return _capacity; }

void Ice::print(std::ostream &out) {
  for (std::size_t index{}; index < _size; ++index)
    out << *(items + index) << " ,";
  out << '\n';
}

void Ice::expand(std::size_t new_Cap) {
  if (_capacity >= new_Cap)
    return;

  _capacity += new_Cap;
  value_Type *new_Items = new value_Type[_capacity];
  for (std::size_t i{}; i < _size; ++i)
    new_Items[i] = items[i];

  delete[] items; // delete previous memory
  items = nullptr;

  items = new_Items;
}

void Ice::add_Items(value_Type *values, std::size_t val_Size) noexcept {
  if (auto cap{_size + val_Size}; cap >= _capacity) {
    expand(cap);
  }

  std::size_t counter = _size;
  _size += val_Size;
  for (std::size_t index{}; index < val_Size; ++index) {
    items[counter] = values[index];
    counter += 1;
  }
}

void Ice::remove(std::size_t index) noexcept {
  std::size_t last_Element{_size - 1};
  items[index] = std::move(items[last_Element]);
  items[last_Element] = 0;
  _size -= 1;
}

void Ice::removeS(std::size_t size, value_Type *values) noexcept {
  std::size_t last_Element{_size - 1};
  for (std::size_t i{}; i < size; ++i) {
    items[values[i]] = std::move(items[last_Element] - i);
    items[last_Element - i] = 0;
    _size -= 1;
  }
}
