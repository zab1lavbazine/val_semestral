
#pragma once
#include <iostream>
#include <string>

#include "Builder.hpp"
#include "Pole.hpp"

class Controller {
 public:
  Controller() {
    builder = Builder();
    pole = Pole();
  }
  ~Controller() {}

  void startGame();

  Object* openCell(size_t x, size_t y) { return pole.openCell(x, y); }

  Object* flagCell(size_t x, size_t y) { return pole.flagCell(x, y); }

  void printPole() { pole.print(); }

  void printHiddenPole() { pole.printHidden(); }

  void start();

 private:
  Pole pole;
  Builder builder;

  bool checkObject(Object* obj);
  bool checkGame();
};