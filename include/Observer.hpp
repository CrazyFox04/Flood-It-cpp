//
// Created by Enzo Renard on 08/10/2024.
//

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

/**
 * @class Observer
 * @brief Interface for observer objects in the observer pattern.
 *
 * This class provides an interface for objects that observe changes in observable objects.
 * It declares a method to update the observer.
 */
class Observer {
public:
    /**
     * @brief Virtual destructor for Observer.
     */
    virtual ~Observer() = default;

    /**
     * @brief Updates the observer.
     *
     * This method is called to notify the observer of changes in the observable object.
     */
    virtual void update() = 0;
};
#endif //OBSERVER_HPP