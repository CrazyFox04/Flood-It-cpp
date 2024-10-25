//
// Created by Enzo Renard on 20/09/2024.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

/**
 * @class Player
 * @brief Represents a player in the game.
 *
 * This class holds the player's name and score.
 */
class Player {
    std::string name; ///< The name of the player.
    int score; ///< The score of the player.

public:
    /**
     * @brief Default constructor for Player.
     *
     * Initializes a new player with default values.
     */
    Player();

    /**
     * @brief Parameterized constructor for Player.
     * @param name The name of the player.
     *
     * Initializes a new player with the given name.
     */
    Player(std::string name);
};

#endif //PLAYER_HPP