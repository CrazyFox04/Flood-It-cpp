#include "GameResults.hpp"
#include <algorithm>
#include <unordered_map>

#include "FileManager.hpp"

std::vector<GameResult> GameResults::get_results_by_settings(GameSettings settings, int max_results) const {
    std::vector<GameResult> best_results = get_results_by_settings(settings);
    if (best_results.size() > max_results) {
        best_results.resize(max_results);
    }
    return best_results;
}

std::vector<GameResult> GameResults::get_results_by_settings(GameSettings settings) const {
    std::unordered_map<std::string, GameResult> best_results_by_user;
    for (const auto&result: this->results) {
        if (result.settings.board_height == settings.board_height &&
            result.settings.board_width == settings.board_width) {
            if (best_results_by_user.find(result.settings.player_name) == best_results_by_user.end() ||
                result.status.play_count > best_results_by_user[result.settings.player_name].status.play_count) {
                best_results_by_user[result.settings.player_name] = result;
            }
        }
    }
    std::vector<GameResult> best_results;
    best_results.reserve(best_results_by_user.size());
    for (const auto&[username, best_result]: best_results_by_user) {
        best_results.push_back(best_result);
    }
    return GameResults::sort(best_results);
}

std::vector<GameResult> GameResults::sort(std::vector<GameResult>& results) {
    std::ranges::sort(results, [](const GameResult&a, const GameResult&b) {
        return a < b;
    });
    return results;
}

void GameResults::add_result(const GameResult&result) {
    this->results.emplace_back(result);
}

void GameResults::saveToFile(const std::string&filename) const {
    FileManager::saveResultsToFile(results, filename);
}

void GameResults::loadFromFile(const std::string&filename) {
    results = FileManager::loadResultsFromFile(filename);
}
