//
// Created by Enzo Renard on 21/09/2024.
//

#ifndef GAMEGUI_HPP
#define GAMEGUI_HPP

#include <GameController.hpp>
#include <memory>
#include <Player.hpp>

#include "GameSettings.hpp"

class FloodItConfiguration;
class FloodItView;
class FloodItGameOver;

class GameGui {
    bool wantToExit;
    GameSettings settings;
    Player player;
    std::shared_ptr<GameController> controller;
    FloodItConfiguration* flood_it_configuration;
    FloodItView* flood_it_view;
    FloodItGameOver* flood_it_game_over;

    void configureEndOfConfiguration();

    void configureEndOfView();

    void configureEndOfGameOver();

public:
    GameGui();

    void run(int argc, char** argv);
};
#endif //GAMEGUI_HPP
