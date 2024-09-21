//
// Created by Enzo Renard on 20/09/2024.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {
    std::string name;
    int score;

public:
    Player();
    Player(std::string name);
};
#endif //PLAYER_HPP
