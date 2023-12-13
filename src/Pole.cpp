

#include "../include/Pole.hpp"

Pole::Pole(size_t size) : size(size) {
  pole.resize(size, std::vector<Cell*>(size, nullptr));

  for (size_t i = 0; i < size; ++i) {
    for (size_t j = 0; j < size; ++j) {
      pole[i][j] = new Cell();
    }
  }
}

void Pole::setSize(size_t size) {
  clear();
  this->size = size;
  pole.resize(size, std::vector<Cell*>(size, nullptr));
  for (size_t i = 0; i < size; ++i) {
    for (size_t j = 0; j < size; ++j) {
      pole[i][j] = new Cell();
    }
  }
}

void Pole::setObject(size_t x, size_t y, Object* object) {
  pole[x][y]->setObject(object);
}

void Pole::print() const {
  std::cout << "  ";
  for (size_t i = 0; i < size; ++i) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  for (size_t i = 0; i < size; ++i) {
    std::cout << i << " ";
    for (size_t j = 0; j < size; ++j) {
      std::cout << pole[i][j]->toString() << " ";
    }
    std::cout << std::endl;
  }
}

void Pole::clear() {
  for (size_t i = 0; i < size; ++i) {
    for (size_t j = 0; j < size; ++j) {
      delete pole[i][j];
    }
  }
  pole.clear();
}

Object* Pole::openCell(size_t x, size_t y) {
  // Check if the cell is already showed
  if (pole[x][y]->isShowed()) {
    return nullptr;
  }

  // Set the current cell as showed
  pole[x][y]->setShowed(true);

  // Get the object in the current cell
  Object* currentObject = pole[x][y]->getObject();

  // If the object is a number (not a mine), stop opening cells
  if (currentObject->getMark() == Marks::Number) {
    return currentObject;
  }

  // Open neighboring cells recursively
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      // Skip the current cell
      if (i == 0 && j == 0) {
        continue;
      }

      // Calculate neighboring cell coordinates
      size_t newX = x + i;
      size_t newY = y + j;

      // Check if the neighboring cell is within bounds
      if (newX >= 0 && newX < size && newY >= 0 && newY < size) {
        openCell(newX, newY);
      }
    }
  }

  // Return the object in the current cell
  return currentObject;
}

Object* Pole::flagCell(size_t x, size_t y) {
  if (pole[x][y]->isShowed()) {
    return nullptr;
  }
  pole[x][y]->setFlag(!pole[x][y]->isFlag());
  return pole[x][y]->getObject();
}

void Pole::printHidden() const {
  std::cout << "  ";
  for (size_t i = 0; i < size; ++i) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  for (size_t i = 0; i < size; ++i) {
    std::cout << i << " ";
    for (size_t j = 0; j < size; ++j) {
      if (pole[i][j]->isFlag()) {
        std::cout << "F ";
      } else if (pole[i][j]->isShowed()) {
        std::cout << pole[i][j]->toString() << " ";
      } else {
        std::cout << "X ";
      }
    }
    std::cout << std::endl;
  }
}