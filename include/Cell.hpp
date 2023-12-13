#pragma once

#include "Empty.hpp"
#include "Mine.hpp"
#include "Number.hpp"

class Cell {
 public:
  Cell() : object(new Empty()), showed(false), flag(false) {}

  Cell(Object* object) : object(object), showed(false), flag(false) {}

  ~Cell() { delete object; }

  Cell(const Cell& other)
      : object(other.object->clone()), showed(false), flag(false) {}

  Cell& operator=(const Cell& other);

  std::string toString() { return object->toString(); }

  void setObject(Object* object);

  Object* getObject() const { return object; }

  bool isMine() const;

  bool isShowed() const { return showed; }

  void setShowed(bool showed) { this->showed = showed; }

  void setFlag(bool flag) { this->flag = flag; }

  bool isFlag() const { return flag; }

 private:
  Object* object;
  bool showed;
  bool flag;
};