//
// Created by Enzo Renard on 08/10/2024.
//

#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP
#include "Observer.hpp"

class Observable {
public:
    virtual ~Observable() = default;

    virtual void addObserver(Observer* observer) = 0;

    virtual void removeObserver(Observer* observer) = 0;

    virtual void notifyObservers() = 0;
};
#endif //OBSERVABLE_HPP
