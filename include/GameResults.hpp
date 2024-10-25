//
// Created by Enzo Renard on 18/10/2024.
//

#ifndef GAMERESULTS_HPP
#define GAMERESULTS_HPP
#include <vector>
#include "GameResult.hpp"
#include "GameSettings.hpp"

/**
 * @class GameResults
 * @brief Manages a collection of game results.
 *
 * This class provides methods to add, retrieve, sort, save, and load game results.
 */
class GameResults {
    std::vector<GameResult> results; ///< Vector holding the game results.

    /**
     * @brief Sorts a vector of game results.
     * @param results The vector of game results to be sorted.
     * @return A sorted vector of game results.
     */
    static std::vector<GameResult> sort(std::vector<GameResult>& results);
public:
    /**
     * @brief Retrieves game results filtered by settings and limited by a maximum number of results.
     * @param settings The game settings to filter by.
     * @param max_results The maximum number of results to return.
     * @return A vector of game results matching the settings.
     */
    std::vector<GameResult> get_results_by_settings(GameSettings settings, int max_results) const;

    /**
     * @brief Retrieves game results filtered by settings.
     * @param settings The game settings to filter by.
     * @return A vector of game results matching the settings.
     */
    std::vector<GameResult> get_results_by_settings(GameSettings settings) const;

    /**
     * @brief Adds a game result to the collection.
     * @param result The game result to add.
     */
    void add_result(const GameResult& result);

    /**
     * @brief Saves the game results to a file.
     * @param filename The name of the file to save to.
     */
    void saveToFile(const std::string& filename) const;

    /**
     * @brief Loads game results from a file.
     * @param filename The name of the file to load from.
     */
    void loadFromFile(const std::string& filename);
};

#endif //GAMERESULTS_HPP