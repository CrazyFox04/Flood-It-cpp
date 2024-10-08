//
// Created by Enzo Renard on 20/09/2024.
//

#ifndef GAME_HPP
#define GAME_HPP
#include <GameController.hpp>

#include "Board.hpp"
#include "Player.hpp"
#include "GameSettings.hpp"

class Game : public GameController {
    Board board;
    GameSettings settings;
    Player player;
    std::vector<Observer*> observers;

public :
    static constexpr int DEFAULT_BOARD_WIDTH = 10;
    static constexpr int DEFAULT_BOARD_HEIGHT = 10;

    Game();

    Game(Player player);

    Game(GameSettings settings, Player player);

    const Board& getBoard() const override;

    void play_at(int x, int y);

    bool isFinished() const;

    const int getMaxColor() const override;

    void addObserver(Observer* observer) override;

    void removeObserver(Observer* observer) override;

    void notifyObservers() override;
};

#endif //GAME_HPP
