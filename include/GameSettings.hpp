//
// Created by Enzo Renard on 20/09/2024.
//

#ifndef GAMESETTINGS_HPP
#define GAMESETTINGS_HPP
#include <string>

/**
 * @struct GameSettings
 * @brief Represents the settings for the FloodIt game.
 *
 * This structure holds the configuration settings for the game, including the board dimensions,
 * number of colors, and the player's name.
 */
struct GameSettings {
    int board_height; ///< The height of the game board.
    int board_width; ///< The width of the game board.
    int number_color; ///< The number of colors used in the game.
    std::string player_name; ///< The name of the player.
};

#endif //GAMESETTINGS_HPP