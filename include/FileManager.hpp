//
// Created by Enzo Renard on 24/10/2024.
//

#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <vector>
#include <string>
#include "GameResult.hpp"

/**
 * @class FileManager
 * @brief Manages saving and loading game results to and from files.
 *
 * This class provides static methods to save a list of game results to a file and to load game results from a file.
 */
class FileManager {
public:
    /**
     * @brief Saves the game results to a file.
     * @param results A vector of GameResult objects to be saved.
     * @param filename The name of the file where the results will be saved.
     */
    static void saveResultsToFile(const std::vector<GameResult>& results, const std::string& filename);

    /**
     * @brief Loads the game results from a file.
     * @param filename The name of the file from which the results will be loaded.
     * @return A vector of GameResult objects loaded from the file.
     */
    static std::vector<GameResult> loadResultsFromFile(const std::string& filename);
};

#endif //FILEMANAGER_HPP