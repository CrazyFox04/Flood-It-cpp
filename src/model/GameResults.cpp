//
// Created by Enzo Renard on 18/10/2024.
//
#include <fstream>
#include <iostream>
#include "GameResults.hpp"

std::vector<GameResult> GameResults::get_results_by_settings(const GameSettings& settings, int max_result) const {
    std::vector<GameResult> results;
    int count = 0;

    for (const auto& result : GameResults::sort(this->results)) {
        if (result.settings.board_height == settings.board_height &&
            result.settings.board_width == settings.board_width) {
            results.push_back(result);
            count++;
            }

        if (count >= max_result) {
            break;
        }
    }

    return results;
}

std::vector<GameResult> GameResults::sort(std::vector<GameResult> results) {
    std::ranges::sort(std::ranges::begin(results), std::ranges::end(results),
                      [](const GameResult&a, const GameResult&b) {
                          return a < b;
                      });
    return results;
}


void GameResults::add_result(const GameResult&result) {
    this->results.emplace_back(result);
}

void GameResults::serialize(const std::string &filename) {
    std::ofstream file(filename, std::ios::binary | std::ios::out | std::ios::trunc);

    if (!file.is_open()) {
        std::cerr << "Error: Failed to open file for writing." << std::endl;
        return;
    }

    // Sérialiser la taille du vecteur `results`
    size_t size = results.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));

    // Sérialiser chaque élément du vecteur
    for (const auto& result : results) {
        file.write(reinterpret_cast<const char*>(&result), sizeof(GameResult));
    }

    file.close();
    std::cout << "Object serialized successfully." << std::endl;
}

GameResults GameResults::deserialize(const std::string &filename) {
    GameResults results_obj{};
    std::ifstream file(filename, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error: Failed to open file for reading." << std::endl;
        return results_obj;
    }

    // Désérialiser la taille du vecteur
    size_t size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));

    // Vider et réserver de l'espace pour le vecteur `results`
    results_obj.results.clear();
    results_obj.results.reserve(size);

    // Désérialiser chaque élément du vecteur `results`
    GameResult result;
    for (size_t i = 0; i < size; ++i) {
        file.read(reinterpret_cast<char*>(&result), sizeof(GameResult));
        results_obj.results.emplace_back(result);
    }

    file.close();
    std::cout << "Object deserialized successfully." << std::endl;

    return results_obj;
}
