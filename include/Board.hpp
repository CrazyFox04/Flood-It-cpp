//
// Created by Enzo Renard on 17/09/2024.
//

#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>


class Board {
    std::vector<std::vector<int>> board;
    std::vector<std::vector<bool>> mark;
    int height;
    int width;

    void set_color(int x, int y);

    int get_color(int x, int y) const;

    void play_at(int x, int y) const;

    bool is_marked(int x, int y) const;

public:
    Board(int height, int width, int number_color);

    friend class Game;
};
#endif //BOARD_HPP
