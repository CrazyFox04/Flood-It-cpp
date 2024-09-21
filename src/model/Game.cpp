//
// Created by Enzo Renard on 20/09/2024.
//
#include "Game.hpp"

#include <Direction.hpp>

#include "Player.hpp"
#include "GameSettings.hpp"

Game::Game(GameSettings settings, Player player): board(settings.board_height, settings.board_width,
                                                        settings.number_color),
                                                  settings(settings), player(player) {
}

Game::Game(Player player) : Game(
    GameSettings(DEFAULT_BOARD_HEIGHT, DEFAULT_BOARD_WIDTH, DEFAULT_BOARD_HEIGHT * DEFAULT_BOARD_WIDTH), player) {
}

Game::Game() : Game(Player()) {
}

bool Game::isFinished() const {
    for (int i = 0; i < settings.board_height; ++i) {
        for (int j = 0; j < settings.board_width; ++j) {
            if (!board.is_marked(i,j)) {
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

    if (!board.is_marked(x, y)) {
        throw std::out_of_range("You can't play at " + std::to_string(x) + " " + std::to_string(y));
    }

    // todo : for each with direction
}



