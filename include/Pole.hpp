#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "Cell.hpp"

class Pole {
 public:
  Pole() : size(0) {}

  Pole(size_t size);

  ~Pole() { clear(); }

  void setSize(size_t size);

  size_t getSize() const { return size; }

  void setObject(size_t x, size_t y, Object* object);

  Cell* getCell(size_t x, size_t y) const { return pole[x][y]; }

  Object* openCell(size_t x, size_t y);

  Object* flagCell(size_t x, size_t y);

  void print() const;

  void printHidden() const;

 private:
  size_t size;
  std::vector<std::vector<Cell*>> pole;

  void clear();

  // support functions
};