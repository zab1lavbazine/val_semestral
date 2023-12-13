#pragma once
#include "Object.hpp"

class Empty : public Object {
 public:
  Empty() = default;
  ~Empty() = default;

  std::string toString() override { return "E"; }
  bool isMine() const override { return false; }

  Marks getMark() const override { return Marks::Empty; }

  Object* clone() override { return new Empty(*this); }

 private:
  Marks mark = Marks::Empty;
};