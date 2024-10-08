//
// Created by Enzo Renard on 08/10/2024.
//

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update() = 0;
};
#endif //OBSERVER_HPP
