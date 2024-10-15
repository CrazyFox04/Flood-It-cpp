//
// Created by Enzo Renard on 21/09/2024.
//

#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP
#include <Board.hpp>
#include "Observable.hpp"

class GameController : public Observable {
public:
    virtual ~GameController() = default;

    virtual const Board& getBoard() const = 0;

    virtual const int getMaxColor() const = 0;

    virtual void play_at(int x, int y) = 0;

    virtual void addObserver(Observer* observer) = 0;

    virtual void removeObserver(Observer* observer) = 0;

    virtual bool isFinished() const = 0;

    virtual bool can_play_at(int x, int y) const = 0;

    virtual int get_play_count() const = 0;
};
#endif //GAMECONTROLLER_HPP
