//
// Created by Enzo Renard on 08/10/2024.
//

#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP
#include "Observer.hpp"

/**
 * @class Observable
 * @brief Interface for observable objects in the observer pattern.
 *
 * This class provides an interface for objects that can be observed by observers.
 * It declares methods to add, remove, and notify observers.
 */
class Observable {
public:
    /**
     * @brief Virtual destructor for Observable.
     */
    virtual ~Observable() = default;

    /**
     * @brief Adds an observer to the observable object.
     * @param observer Pointer to the observer to be added.
     */
    virtual void addObserver(Observer* observer) = 0;

    /**
     * @brief Removes an observer from the observable object.
     * @param observer Pointer to the observer to be removed.
     */
    virtual void removeObserver(Observer* observer) = 0;

    /**
     * @brief Notifies all observers about an event.
     */
    virtual void notifyObservers() = 0;
};

#endif //OBSERVABLE_HPP