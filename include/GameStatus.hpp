//
// Created by Enzo Renard on 15/10/2024.
//

#ifndef GAMESTATUS_HPP
#define GAMESTATUS_HPP

/**
 * @struct GameStatus
 * @brief Represents the status of the game.
 *
 * This structure holds the play count of the game.
 */
struct GameStatus {
    int play_count; ///< The number of times the game has been played.

    /**
     * @brief Default constructor for GameStatus.
     *
     * Initializes the play count to 0.
     */
    GameStatus() : play_count(0) {
    }
};

#endif //GAMESTATUS_HPP