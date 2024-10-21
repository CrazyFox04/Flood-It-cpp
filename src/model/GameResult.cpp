//
// Created by Enzo Renard on 18/10/2024.
//
#include "GameResult.hpp"

bool operator <(GameResult const&gr1, GameResult const&gr2) {
    return gr1.status.play_count < gr2.status.play_count;
}

bool operator>(GameResult const&gr1, GameResult const&gr2) {
    return gr1.status.play_count >= gr2.status.play_count;
}
