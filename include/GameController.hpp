//
// Created by Enzo Renard on 21/09/2024.
//

#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP
#include "Board.hpp"
#include "GameResult.hpp"
#include "Observable.hpp"

/**
 * @class GameController
 * @brief Abstract base class for controlling the game logic.
 *
 * This class provides an interface for game controllers, including methods for playing the game,
 * managing observers, and retrieving game state information.
 */
class GameController : public Observable {
public:
    /**
     * @brief Virtual destructor for GameController.
     */
    virtual ~GameController() = default;

    /**
     * @brief Gets the game board.
     * @return A constant reference to the game board.
     */
    virtual const Board& getBoard() const = 0;

    /**
     * @brief Gets the maximum number of colors allowed in the game.
     * @return The maximum number of colors.
     */
    virtual const int getMaxColor() const = 0;

    /**
     * @brief Plays at a specific position on the board.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    virtual void play_at(int x, int y) = 0;

    /**
     * @brief Adds an observer to the game.
     * @param observer The observer to be added.
     */
    virtual void addObserver(Observer* observer) = 0;

    /**
     * @brief Removes an observer from the game.
     * @param observer The observer to be removed.
     */
    virtual void removeObserver(Observer* observer) = 0;

    /**
     * @brief Checks if the game is finished.
     * @return True if the game is finished, false otherwise.
     */
    virtual bool isFinished() const = 0;

    /**
     * @brief Checks if a move can be played at a specific position.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @return True if the move can be played, false otherwise.
     */
    virtual bool can_play_at(int x, int y) const = 0;

    /**
     * @brief Gets the number of plays made.
     * @return The number of plays.
     */
    virtual int get_play_count() const = 0;

    /**
     * @brief Gets the best game results.
     * @param max_result The maximum number of results to return.
     * @return A vector of the best game results.
     */
    virtual std::vector<GameResult> get_best_result(int max_result) const = 0;
};

#endif //GAMECONTROLLER_HPP