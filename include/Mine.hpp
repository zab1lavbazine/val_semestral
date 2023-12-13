#include "Object.hpp"
#pragma once

class Mine : public Object {
 public:
  Mine() = default;
  ~Mine() = default;

  std::string toString() override { return "M"; }
  bool isMine() const override { return true; }

  Marks getMark() const override { return Marks::Mine; }

  Object* clone() override { return new Mine(*this); }

 private:
  Marks mark = Marks::Mine;
};
