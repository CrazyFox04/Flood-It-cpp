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
                                                  settings(settings), status(), observers(),
                                                  results() {
    results.loadFromFile("leaderboard.dat");
    recursive_mark(0, 0);
}

void Game::recursive_mark(int x, int y) {
    if (board.get_color(0, 0) == board.get_color(x, y)) {
        board.markAt(x, y);
        for (auto direction: Direction::directions) {
            int pos_x = x + direction.first;
            int pos_y = y + direction.second;
            if (pos_x >= 0 && pos_y >= 0 && pos_x < settings.board_height && pos_y < settings.board_width && !board.
                is_marked(pos_x, pos_y)) {
                recursive_mark(pos_x, pos_y);
            }
        }
    }
}

Game::Game(Player player) : Game(
    GameSettings(Board::DEFAULT_HEIGHT, Board::DEFAULT_WIDTH, Board::DEFAULT_HEIGHT * Board::DEFAULT_WIDTH), player) {
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
    board.change_color(color);
    board.reset_mark();
    recursive_mark(0, 0);
    ++status.play_count;
    if (isFinished()) {
        results.add_result({settings, status});
        results.saveToFile("leaderboard.dat");
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

int Game::get_play_count() const {
    return status.play_count;
}

bool Game::are_game_settings_valid(const GameSettings&settings) {
    return Board::is_board_size_valid(settings.board_height, settings.board_width) &&
           is_number_of_color_valid(settings.number_color);
}

bool Game::is_number_of_color_valid(const int number_of_color) {
    return number_of_color >= MIN_NUMBER_OF_COLOR && number_of_color <= MAX_NUMBER_OF_COLOR;
}

std::vector<GameResult> Game::get_best_result(int max_result) const {
    return results.get_results_by_settings(settings, max_result);
}

