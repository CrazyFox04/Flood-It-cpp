//
// Created by Enzo Renard on 18/10/2024.
//

#ifndef GAMERESULTS_HPP
#define GAMERESULTS_HPP
#include <vector>
#include "GameResult.hpp"
#include "GameSettings.hpp"

class GameResults {
public:
    std::vector<GameResult> get_results_by_settings(const GameSettings&settings, int max_result) const;

    void add_result(const GameResult&result);

    void saveToFile(const std::string&filename) const;

    void loadFromFile(const std::string&filename);

private:
    std::vector<GameResult> results;

    static std::vector<GameResult> sort(std::vector<GameResult> results);
};
#endif //GAMERESULTS_HPP
