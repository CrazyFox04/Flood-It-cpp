//
// Created by Enzo Renard on 20/09/2024.
//

#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include <utility>

using Direction2D = std::pair<int, int>;

struct Direction {
    static const Direction2D UP;
    static const Direction2D DOWN;
    static const Direction2D LEFT;
    static const Direction2D RIGHT;
    static const Direction2D directions[4];
};
#endif //DIRECTION_HPP
