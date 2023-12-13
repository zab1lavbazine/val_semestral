#include "../include/Builder.hpp"

void Builder::build(Pole* pole, int size, int mines) {
  pole->setSize(size);
  setMines(pole, mines);
  setNumbers(pole);
}

void Builder::setMines(Pole* pole, int mines) {
  for (int i = 0; i < mines; ++i) {
    size_t x = rand() % pole->getSize();
    size_t y = rand() % pole->getSize();
    pole->setObject(x, y, new Mine());
  }
}

void Builder::setNumbers(Pole* pole) {
  for (size_t i = 0; i < pole->getSize(); ++i) {
    for (size_t j = 0; j < pole->getSize(); ++j) {
      Cell* curr_cell = pole->getCell(i, j);
      if (!curr_cell->isMine()) {
        int mineCount = countAdjacentMines(pole, i, j);
        if (mineCount > 0) {
          pole->setObject(i, j, new Number(mineCount));
        }
      }
    }
  }
}

int Builder::countAdjacentMines(Pole* pole, size_t x, size_t y) const {
  int mineCount = 0;
  for (int dx = -1; dx <= 1; ++dx) {
    for (int dy = -1; dy <= 1; ++dy) {
      size_t nx = x + dx;
      size_t ny = y + dy;
      // check if in the pole
      if (nx < 0 || ny < 0 || nx >= pole->getSize() || ny >= pole->getSize()) {
        continue;
      }
      Cell* curr_cell = pole->getCell(nx, ny);
      if (nx < pole->getSize() && ny < pole->getSize() && curr_cell->isMine()) {
        ++mineCount;
      }
    }
  }
  return mineCount;
}