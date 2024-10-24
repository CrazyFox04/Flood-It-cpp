//
// Created by Enzo Renard on 24/10/2024.
//

#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP
#include <vector>
#include <string>
#include "GameResult.hpp"

class FileManager {
public:
    static void saveResultsToFile(const std::vector<GameResult>&results, const std::string&filename);

    static std::vector<GameResult> loadResultsFromFile(const std::string&filename);
};
#endif //FILEMANAGER_HPP
