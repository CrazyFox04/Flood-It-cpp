//
// Created by Enzo Renard on 17/09/2024.
//

#ifndef BOARD_HPP
#define BOARD_HPP
#include "Square.hpp"
#include <vector>

class Board {
  std::vector<std::vector<Square>> board;
  int height;
  int width;
  public:
    Board(int height, int width);
};
#endif //BOARD_HPP
