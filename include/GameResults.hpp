//
// Created by Enzo Renard on 18/10/2024.
//

#ifndef GAMERESULTS_HPP
#define GAMERESULTS_HPP
#include <GameResult.hpp>
#include <vector>

class GameResults {
    std::vector<GameResult> results;

public:
    std::vector<GameResult> get_results_by_settings(const GameSettings&settings, int max_result) const;

    void add_result(const GameResult&result);

    void serialize(const std::string&filename);

    static std::vector<GameResult> sort(std::vector<GameResult>);

    static GameResults deserialize(const std::string&filename);
};
#endif //GAMERESULTS_HPP
