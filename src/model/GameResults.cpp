#include "GameResults.hpp"
#include "FileManager.hpp"

std::vector<GameResult> GameResults::get_results_by_settings(const GameSettings& settings, int max_result) const {
    std::vector<GameResult> filtered_results;
    int count = 0;

    for (const auto& result : sort(this->results)) {
        if (result.settings.board_height == settings.board_height &&
            result.settings.board_width == settings.board_width) {
            filtered_results.push_back(result);
            count++;
            }

        if (count >= max_result) {
            break;
        }
    }

    return filtered_results;
}

std::vector<GameResult> GameResults::sort(std::vector<GameResult> results) {
    std::ranges::sort(results, [](const GameResult& a, const GameResult& b) {
        return a < b;
    });
    return results;
}

void GameResults::add_result(const GameResult& result) {
    this->results.emplace_back(result);
}

void GameResults::saveToFile(const std::string& filename) const {
    FileManager::saveResultsToFile(results, filename);
}

void GameResults::loadFromFile(const std::string& filename) {
    results = FileManager::loadResultsFromFile(filename);
}