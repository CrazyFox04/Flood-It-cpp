//
// Created by Enzo Renard on 20/09/2024.
//

#ifndef GAME_HPP
#define GAME_HPP
#include "GameController.hpp"
#include "GameResults.hpp"
#include "GameStatus.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "GameSettings.hpp"

/**
 * @class Game
 * @brief Manages the core logic and state of the FloodIt game.
 *
 * This class handles the game board, settings, status, and observers. It provides methods to play the game,
 * validate settings, and notify observers of changes.
 */
class Game : public GameController {
    Board board; ///< The game board.
    GameSettings settings; ///< The game settings.
    GameStatus status; ///< The current status of the game.
    std::vector<Observer *> observers; ///< List of observers watching the game state.
    GameResults results; ///< The results of the game.

    /**
     * @brief Recursively marks the board starting from a given position.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    void recursive_mark(int x, int y);

public:
    static constexpr int MIN_NUMBER_OF_COLOR = 2; ///< Minimum number of colors allowed.
    static constexpr int MAX_NUMBER_OF_COLOR = 20; ///< Maximum number of colors allowed.

    /**
     * @brief Default constructor for Game.
     */
    Game();

    /**
     * @brief Constructor for Game with a player.
     * @param player The player of the game.
     */
    Game(Player player);

    /**
     * @brief Constructor for Game with settings and a player.
     * @param settings The game settings.
     * @param player The player of the game.
     */
    Game(GameSettings settings, Player player);

    /**
     * @brief Gets the game board.
     * @return A constant reference to the game board.
     */
    const Board& getBoard() const override;

    /**
     * @brief Plays at a specific position on the board.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    void play_at(int x, int y);

    /**
     * @brief Checks if a move can be played at a specific position.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @return True if the move can be played, false otherwise.
     */
    bool can_play_at(int x, int y) const;

    /**
     * @brief Checks if the game is finished.
     * @return True if the game is finished, false otherwise.
     */
    bool isFinished() const;

    /**
     * @brief Gets the maximum number of colors allowed.
     * @return The maximum number of colors.
     */
    const int getMaxColor() const override;

    /**
     * @brief Adds an observer to the game.
     * @param observer The observer to be added.
     */
    void addObserver(Observer* observer) override;

    /**
     * @brief Removes an observer from the game.
     * @param observer The observer to be removed.
     */
    void removeObserver(Observer* observer) override;

    /**
     * @brief Notifies all observers of changes in the game state.
     */
    void notifyObservers() override;

    /**
     * @brief Gets the number of plays made.
     * @return The number of plays.
     */
    int get_play_count() const;

    /**
     * @brief Validates the game settings.
     * @param settings The game settings to be validated.
     * @return True if the settings are valid, false otherwise.
     */
    static bool are_game_settings_valid(const GameSettings& settings);

    /**
     * @brief Validates the number of colors.
     * @param number_of_color The number of colors to be validated.
     * @return True if the number of colors is valid, false otherwise.
     */
    static bool is_number_of_color_valid(int number_of_color);

    /**
     * @brief Gets the best game results.
     * @param max_result The maximum number of results to return.
     * @return A vector of the best game results.
     */
    std::vector<GameResult> get_best_result(int max_result) const override;
};

#endif //GAME_HPP