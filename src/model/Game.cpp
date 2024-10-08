//
// Created by Enzo Renard on 20/09/2024.
//
#include "Game.hpp"

#include <Direction.hpp>
#include <iostream>
#include <ostream>

#include "Player.hpp"
#include "GameSettings.hpp"

Game::Game(GameSettings settings, Player player): board(settings.board_height, settings.board_width,
                                                        settings.number_color),
                                                  settings(settings), player(player) {
    board.markAt(0, 0);
}

Game::Game(Player player) : Game(
    GameSettings(DEFAULT_BOARD_HEIGHT, DEFAULT_BOARD_WIDTH, DEFAULT_BOARD_HEIGHT * DEFAULT_BOARD_WIDTH), player) {
}

Game::Game() : Game(Player()) {
}

bool Game::isFinished() const {
    for (int i = 0; i < settings.board_height; ++i) {
        for (int j = 0; j < settings.board_width; ++j) {
            if (!board.is_marked(i, j)) {
                return false;
            }
        }
    }
    return true;
}

void Game::play_at(int x, int y) {
    if (isFinished()) {
        throw std::invalid_argument("Game is finished, you can't play anymore");
    }

    if (board.is_marked(x, y)) {
        throw std::invalid_argument(
            "You can't play at " + std::to_string(x) + " " + std::to_string(y) + " : already marked pos");
    }

    if (!board.is_marked(x - 1, y) && !board.is_marked(x + 1, y) && !board.is_marked(x, y - 1) && !board.
        is_marked(x, y + 1)) {
        throw std::invalid_argument(
            "You can't play at " + std::to_string(x) + " " + std::to_string(y) + " : not near a marked pos");
    }

    std::cout << "successfully played at " << x << ", " << y << std::endl;
    // todo : for each with direction
}

const Board& Game::getBoard() const {
    return board;
}

const int Game::getMaxColor() const {
    return settings.number_color;
}
