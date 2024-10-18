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
    if (x < 0 || x >= height || y < 0 || y >= width)
        throw std::out_of_range("Position is out of range");
    return board.at(x).at(y);
}

void Board::play_at(const int x, const int y, const int color) {
    if (x < 0 || x >= height || y < 0 || y >= width) {
        throw std::out_of_range("Position is out of range");
    }
    board.at(x).at(y) = color;
    mark.at(x).at(y) = true;
}

bool Board::is_marked(const int x, const int y) const {
    if (x < 0 || x >= height || y < 0 || y >= width) {
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
    if (x < 0 || x >= height || y < 0 || y >= width) {
        throw std::out_of_range("Position is out of range");
    }
    mark.at(x).at(y) = true;
}

void Board::change_color(int color) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (is_marked(i, j)) {
                board[i][j] = color;
            }
        }
    }
}

void Board::reset_mark() {
    for (auto&markList: mark) {
        std::fill(markList.begin(), markList.end(), false);
    }
}

bool Board::is_board_size_valid(int height, int width) {
    return height >= MIN_HEIGHT && height <= MAX_HEIGHT && width >= MIN_WIDTH && width <= MAX_WIDTH;
}
