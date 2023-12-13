#pragma once

#include "Object.hpp"

class Number : public Object {
 public:
  Number() = default;
  Number(int value) : value(value) {}
  ~Number() = default;

  bool isMine() const override { return false; }
  std::string toString() override { return std::to_string(value); }

  Marks getMark() const override { return Marks::Number; }

  Object* clone() override { return new Number(*this); }

 private:
  int value;
};