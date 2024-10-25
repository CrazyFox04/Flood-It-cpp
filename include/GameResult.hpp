//
// Created by Enzo Renard on 18/10/2024.
//

#ifndef GAMERESULT_HPP
#define GAMERESULT_HPP
#include "GameSettings.hpp"
#include "GameStatus.hpp"

#include <string>

/**
 * @struct GameResult
 * @brief Represents the result of a game.
 *
 * This structure holds the settings and status of a game result.
 */
struct GameResult {
    GameSettings settings; ///< The settings used in the game.
    GameStatus status; ///< The status of the game.
};

/**
 * @brief Less-than operator for comparing two GameResult objects.
 * @param gr1 The first GameResult object.
 * @param gr2 The second GameResult object.
 * @return True if gr1 is less than gr2, false otherwise.
 */
bool operator <(GameResult const& gr1, GameResult const& gr2);

/**
 * @brief Greater-than operator for comparing two GameResult objects.
 * @param gr1 The first GameResult object.
 * @param gr2 The second GameResult object.
 * @return True if gr1 is greater than gr2, false otherwise.
 */
bool operator >(GameResult const& gr1, GameResult const& gr2);

#endif //GAMERESULT_HPP