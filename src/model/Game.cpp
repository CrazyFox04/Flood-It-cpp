//
// Created by Enzo Renard on 20/09/2024.
//
#include "Game.hpp"
#include "Observable.hpp"
#include "Observer.hpp"

#include <Direction.hpp>
#include <iostream>
#include <ostream>

#include "Player.hpp"
#include "GameSettings.hpp"

Game::Game(GameSettings settings, Player player): board(settings.board_height, settings.board_width,
                                                        settings.number_color),
                                                  settings(settings), player(player), observers() {
    recursive_mark(0, 0);
}

void Game::recursive_mark(int x, int y) {
    if (board.get_color(0, 0) == board.get_color(x, y)) {
        board.markAt(x, y);
        for (auto direction : Direction::directions) {
            int pos_x = x + direction.first;
            int pos_y = y + direction.second;
            if (pos_x >= 0 && pos_y >= 0 && pos_x < settings.board_width && pos_y < settings.board_height && !board.is_marked(pos_x, pos_y)) {
                recursive_mark(pos_x, pos_y);
            }
        }
    }
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

    auto color = board.get_color(x, y);
    for (int i = 0; i < settings.board_height; ++i) {
        for (int j = 0; j < settings.board_width; ++j) {
            if (board.is_marked(i, j)) {
                board.play_at(i, j, color);
            }
            else {
                if (board.get_color(i, j) == color) {
                    board.markAt(i, j);
                }
            }
        }
    }
    notifyObservers();
}

bool Game::can_play_at(int x, int y) const {
    return !board.is_marked(x, y);
}

const Board& Game::getBoard() const {
    return board;
}

const int Game::getMaxColor() const {
    return settings.number_color;
}

void Game::notifyObservers() {
    for (auto observer: observers) {
        observer->update();
    }
}

void Game::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void Game::removeObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}
