//
// Created by Enzo Renard on 24/10/2024.
//
#include "FileManager.hpp"
#include <fstream>
#include <stdexcept>

void FileManager::saveResultsToFile(const std::vector<GameResult>& results, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary | std::ios::out | std::ios::trunc);

    if (!file.is_open()) {
        throw std::runtime_error("Error: Failed to open file for writing.");
    }

    size_t size = results.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (const auto& result : results) {
        file.write(reinterpret_cast<const char*>(&result), sizeof(GameResult));
    }

    file.close();
}

std::vector<GameResult> FileManager::loadResultsFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);

    if (!file.is_open()) {
        throw std::runtime_error("Error: Failed to open file for reading.");
    }

    size_t size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));

    std::vector<GameResult> results;
    results.reserve(size);

    GameResult result;
    for (size_t i = 0; i < size; ++i) {
        file.read(reinterpret_cast<char*>(&result), sizeof(GameResult));
        results.emplace_back(result);
    }

    file.close();
    return results;
}