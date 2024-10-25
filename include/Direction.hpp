//
// Created by Enzo Renard on 20/09/2024.
//

#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include <utility>

using Direction2D = std::pair<int, int>;

/**
 * @struct Direction
 * @brief Represents the possible directions in a 2D space.
 *
 * This struct defines constants for the four primary directions (UP, DOWN, LEFT, RIGHT)
 * and an array containing all these directions.
 */
struct Direction {
    static const Direction2D UP; ///< Constant for the UP direction.
    static const Direction2D DOWN; ///< Constant for the DOWN direction.
    static const Direction2D LEFT; ///< Constant for the LEFT direction.
    static const Direction2D RIGHT; ///< Constant for the RIGHT direction.
    static const Direction2D directions[4]; ///< Array containing all four directions.
};

#endif //DIRECTION_HPP