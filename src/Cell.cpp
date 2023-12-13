
#include "../include/Cell.hpp"

Cell& Cell::operator=(const Cell& other) {
  showed = other.showed;
  flag = other.flag;
  if (this != &other) {
    delete this->object;
    this->object = other.object->clone();
  }
  return *this;
}

void Cell::setObject(Object* object) {
  if (this->object != nullptr) {
    delete this->object;
  }
  this->object = object;
}

bool Cell::isMine() const {
  if (object == nullptr) {
    std::cout << "NULLPTR\n";
    return false;
  }
  return object->isMine();
}