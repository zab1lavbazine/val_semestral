#include <iostream>
#include <string>

#include "Marks.hpp"
#pragma once

class Object {
 public:
  Object() {}
  virtual ~Object() {}

  virtual bool isMine() const { return false; }

  virtual Marks getMark() const { return Marks::Empty; }

  virtual Object* clone() = 0;

  virtual std::string toString() = 0;
};