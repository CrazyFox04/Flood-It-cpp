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

    void play_at(int x, int y, int color);

    bool is_marked(int x, int y) const;

    void markAt(int x, int y);

public:
    static constexpr int DEFAULT_HEIGHT = 10;
    static constexpr int MIN_HEIGHT = 5;
    static constexpr int MAX_HEIGHT = 20;
    static constexpr int DEFAULT_WIDTH = 10;
    static constexpr int MIN_WIDTH = 5;
    static constexpr int MAX_WIDTH = 20;

    Board(int height, int width, int number_color);

    int getHeight() const;

    int getWidth() const;

    int get_color(int x, int y) const;

    void change_color(int color);

    void reset_mark();

    static bool is_board_size_valid(int height, int width);

    friend class Game;
};
#endif //BOARD_HPP
