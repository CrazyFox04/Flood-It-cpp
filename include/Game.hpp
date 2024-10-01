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

public :
    static constexpr int DEFAULT_BOARD_WIDTH = 10;
    static constexpr int DEFAULT_BOARD_HEIGHT = 10;

    Game();

    Game(Player player);

    Game(GameSettings settings, Player player);

    void play_at(int x, int y);

    bool isFinished() const;
};

#endif //GAME_HPP
