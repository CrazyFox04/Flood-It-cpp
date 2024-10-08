//
// Created by Enzo Renard on 17/09/2024.
//
#include "Board.hpp"

#include <iostream>
#include <ostream>
#include <random>

Board::Board(int height, int width, int number_color) : board(height, std::vector<int>(width)),
                                                        mark(height, std::vector<bool>(width)),
                                                        height(height),
                                                        width(width) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, number_color);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            board[i][j] = dis(gen);
            mark[i][j] = false;
        }
    }
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
        return false;
    }
    return mark.at(x).at(y);
}

int Board::getHeight() const {
    return height;
}

int Board::getWidth() const {
    return width;
}

void Board::markAt(int x, int y) {
    mark.at(x).at(y) = true;
}
