//
// Created by Enzo Renard on 21/09/2024.
//

#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP
#include <Board.hpp>

class GameController {
public:
    virtual ~GameController() = default;

    virtual const Board& getBoard() const = 0;

    virtual const int getMaxColor() const = 0;

    virtual void play_at(int x, int y) = 0;
};
#endif //GAMECONTROLLER_HPP
