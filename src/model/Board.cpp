//
// Created by Enzo Renard on 17/09/2024.
//
#include "Board.hpp"

#include <iostream>
#include <ostream>

Board::Board(int height, int width, int number_color) : board(height, std::vector<int>(width)),
                                                        mark(height, std::vector<bool>(width)),
                                                        height(height),
                                                        width(width) {
    // todo : add generate board based on color number
}

int Board::get_color(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height)
        throw std::out_of_range("Position is out of range");
    return board.at(x).at(y);
}

void Board::play_at(const int x, const int y, const int color) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw std::out_of_range("Position is out of range");
    }    board.at(x).at(y) = color;
    mark.at(x).at(y) = true;
}

bool Board::is_marked(const int x, const int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw std::out_of_range("Position is out of range");
    }
    return mark.at(x).at(y);
}
