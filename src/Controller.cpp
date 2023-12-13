

#include "../include/Controller.hpp"

void Controller::startGame() {
  std::cout << "Welcome to Minesweeper!" << std::endl;
  std::cout << "Please enter the size of the board: ";
  int size;
  std::cin >> size;
  std::cout << "Please enter the number of mines: ";
  int mines;
  std::cin >> mines;

  builder.build(&pole, size, mines);
}

void Controller::start() {
  startGame();
  bool game = true;
  Object* obj = nullptr;

  while (game) {
    printHiddenPole();
    std::cout << "Enter command: ";
    std::string command;
    std::cin >> command;
    if (command == "open") {
      size_t x, y;
      std::cin >> x >> y;
      obj = openCell(x, y);
    } else if (command == "flag") {
      size_t x, y;
      std::cin >> x >> y;
      flagCell(x, y);
    } else if (command == "exit") {
      game = false;
    } else {
      std::cout << "Invalid command!" << std::endl;
    }

    bool check = checkObject(obj);
    obj = nullptr;
    if (check == false) {
      game = false;
      break;
    }
    bool gameCheck = checkGame();
    if (gameCheck) return;
  }
}

bool Controller::checkObject(Object* obj) {
  if (obj == nullptr) {
    return true;
  } else if (obj->getMark() == Marks::Mine) {
    std::cout << "You lose!" << std::endl;
    return false;
  } else if (obj->getMark() == Marks::Number) {
    return true;
  } else if (obj->getMark() == Marks::Empty) {
    return true;
  }
  return true;
}

bool Controller::checkGame() {
  for (size_t i = 0; i < pole.getSize(); ++i) {
    for (size_t j = 0; j < pole.getSize(); ++j) {
      Cell* current_cell = pole.getCell(i, j);
      Object* current_obj = current_cell->getObject();

      if (current_obj->getMark() == Marks::Mine &&
          current_cell->isFlag() == false) {
        return false;
      }
    }
  }
  std::cout << "You win!" << std::endl;
  return true;
}