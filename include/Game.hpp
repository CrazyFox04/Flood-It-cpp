//
// Created by Enzo Renard on 20/09/2024.
//

#ifndef GAME_HPP
#define GAME_HPP
#include <GameController.hpp>
#include <GameResults.hpp>

#include "GameStatus.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "GameSettings.hpp"

class Game : public GameController {
    Board board;
    GameSettings settings;
    GameStatus status;
    std::vector<Observer *> observers;
    GameResults results;

    void recursive_mark(int x, int y);

public :
    static constexpr int MIN_NUMBER_OF_COLOR = 2;
    static constexpr int MAX_NUMBER_OF_COLOR = 20;

    Game();

    Game(Player player);

    Game(GameSettings settings, Player player);

    const Board& getBoard() const override;

    void play_at(int x, int y);

    bool can_play_at(int x, int y) const;

    bool isFinished() const;

    const int getMaxColor() const override;

    void addObserver(Observer* observer) override;

    void removeObserver(Observer* observer) override;

    void notifyObservers() override;

    int get_play_count() const;

    static bool are_game_settings_valid(const GameSettings&settings);

    static bool is_number_of_color_valid(int number_of_color);

    std::vector<GameResult> get_best_result(int max_result) const override;
};

#endif //GAME_HPP
