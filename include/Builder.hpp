#include <iostream>
#include <string>

#pragma once

#include "Pole.hpp"

class Builder {
 public:
  Builder() = default;
  ~Builder() = default;

  void build(Pole* pole, int size, int mines);

 private:
  void setNumbers(Pole* pole);

  void setMines(Pole* pole, int mines);

  int countAdjacentMines(Pole* pole, size_t x, size_t y) const;
};