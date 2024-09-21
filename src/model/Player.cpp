//
// Created by Enzo Renard on 20/09/2024.
//
#include "Player.hpp"

#include <string>

Player::Player(std::string name) : name(name), score(0) {
}

Player::Player(): Player("Guest") {
}
