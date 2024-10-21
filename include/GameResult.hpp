//
// Created by Enzo Renard on 18/10/2024.
//

#ifndef GAMERESULT_HPP
#define GAMERESULT_HPP
#include <GameSettings.hpp>
#include <GameStatus.hpp>

#include "string"

struct GameResult {
    GameSettings settings;
    GameStatus status;
};

bool operator <(GameResult const&gr1, GameResult const&gr2);

bool operator >(GameResult const&gr1, GameResult const&gr2);
#endif //GAMERESULT_HPP
