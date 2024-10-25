//
// Created by Enzo Renard on 21/09/2024.
//

#ifndef GAMEGUI_HPP
#define GAMEGUI_HPP

#include "GameController.hpp"
#include <memory>
#include "Player.hpp"
#include "GameSettings.hpp"

class FloodItConfiguration;
class FloodItView;
class FloodItGameOver;

/**
 * @class GameGui
 * @brief Manages the graphical user interface for the FloodIt game.
 *
 * This class handles the initialization and management of the different GUI components
 * such as the configuration screen, main game view, and game over screen.
 */
class GameGui {
    bool wantToExit; ///< Flag indicating if the user wants to exit.
    GameSettings settings; ///< The game settings.
    Player player; ///< The player of the game.
    std::shared_ptr<GameController> controller; ///< Shared pointer to the game controller.
    FloodItConfiguration* flood_it_configuration; ///< Pointer to the FloodIt configuration screen.
    FloodItView* flood_it_view; ///< Pointer to the FloodIt main game view.
    FloodItGameOver* flood_it_game_over; ///< Pointer to the FloodIt game over screen.

    /**
     * @brief Configures the end of the configuration screen.
     */
    void configureEndOfConfiguration();

    /**
     * @brief Configures the end of the main game view.
     */
    void configureEndOfView();

    /**
     * @brief Configures the end of the game over screen.
     */
    void configureEndOfGameOver();

public:
    /**
     * @brief Default constructor for GameGui.
     */
    GameGui();

    /**
     * @brief Runs the game GUI.
     * @param argc Argument count.
     * @param argv Argument vector.
     */
    void run(int argc, char** argv);
};

#endif //GAMEGUI_HPP