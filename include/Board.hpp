//
// Created by Enzo Renard on 17/09/2024.
//

#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

/**
 * @class Board
 * @brief Represents the game board.
 *
 * This class handles the game board's state, including the colors of the cells and marking cells.
 */
class Board {
    std::vector<std::vector<int>> board; ///< 2D vector representing the board's colors.
    std::vector<std::vector<bool>> mark; ///< 2D vector representing marked cells.
    int height; ///< Height of the board.
    int width; ///< Width of the board.

    /**
     * @brief Plays at the specified position with the given color.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @param color The color to play.
     */
    void play_at(int x, int y, int color);

    /**
     * @brief Checks if the cell at the specified position is marked.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @return True if the cell is marked, false otherwise.
     */
    bool is_marked(int x, int y) const;

    /**
     * @brief Marks the cell at the specified position.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    void markAt(int x, int y);

public:
    static constexpr int DEFAULT_HEIGHT = 10; ///< Default height of the board.
    static constexpr int MIN_HEIGHT = 5; ///< Minimum height of the board.
    static constexpr int MAX_HEIGHT = 20; ///< Maximum height of the board.
    static constexpr int DEFAULT_WIDTH = 10; ///< Default width of the board.
    static constexpr int MIN_WIDTH = 5; ///< Minimum width of the board.
    static constexpr int MAX_WIDTH = 20; ///< Maximum width of the board.

    /**
     * @brief Constructs a Board object with the specified dimensions and number of colors.
     * @param height The height of the board.
     * @param width The width of the board.
     * @param number_color The number of colors.
     */
    Board(int height, int width, int number_color);

    /**
     * @brief Gets the height of the board.
     * @return The height of the board.
     */
    int getHeight() const;

    /**
     * @brief Gets the width of the board.
     * @return The width of the board.
     */
    int getWidth() const;

    /**
     * @brief Gets the color of the cell at the specified position.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @return The color of the cell.
     */
    int get_color(int x, int y) const;

    /**
     * @brief Changes the color of the board.
     * @param color The new color.
     */
    void change_color(int color);

    /**
     * @brief Resets all marks on the board.
     */
    void reset_mark();

    /**
     * @brief Checks if the specified board size is valid.
     * @param height The height of the board.
     * @param width The width of the board.
     * @return True if the board size is valid, false otherwise.
     */
    static bool is_board_size_valid(int height, int width);

    friend class Game; ///< Declares Game as a friend class.
};

#endif //BOARD_HPP