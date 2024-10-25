//
// Created by Enzo Renard on 21/09/2024.
//

#ifndef FLOODITGAMEOVER_HPP
#define FLOODITGAMEOVER_HPP
#include "GameController.hpp"

#include "FloodItGameOver.hpp"
#include "GameSettings.hpp"
#include <memory>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QtWidgets/qboxlayout.h>

/**
 * @class FloodItGameOver
 * @brief A custom QWidget that represents the game over screen.
 *
 * This class handles the display and interaction of the game over screen, including options to restart or exit the game.
 */
class FloodItGameOver : public QWidget {
    Q_OBJECT
    std::shared_ptr<GameController> controller_; ///< Shared pointer to the game controller.
    QVBoxLayout* mainLayout; ///< Main layout for arranging the widgets vertically.
    QHBoxLayout* buttonLayout; ///< Layout for arranging the buttons horizontally.
    QLabel* gameOverLabel; ///< Label displaying the game over message.
    QLabel* detailsLabel; ///< Label displaying additional details.
    QLabel* leaderboardLabel; ///< Label displaying the leaderboard.
    QPushButton* restartButton; ///< Button to restart the game.
    QPushButton* exitButton; ///< Button to exit the game.

private:
    /**
     * @brief Configures the window properties.
     */
    void configureWindow();

    /**
     * @brief Creates the items for the game over screen.
     */
    void createItems();

    /**
     * @brief Updates the items on the game over screen.
     */
    void updateItems();

public:
    /**
     * @brief Constructor for FloodItGameOver.
     * @param game Shared pointer to the game controller.
     */
    FloodItGameOver(std::shared_ptr<GameController> game);

    /**
     * @brief Destructor for FloodItGameOver.
     */
    virtual ~FloodItGameOver() = default;

    /**
     * @brief Starts the game over screen.
     * @param myQtApp Pointer to the QApplication.
     * @return An integer indicating the result of the start operation.
     */
    int start(QApplication* myQtApp);

    /**
     * @brief Restarts the game.
     */
    void restartGame();

    /**
     * @brief Quits the game.
     */
    void quitGame();

protected:
    /**
     * @brief Handles the close event.
     * @param event The close event.
     */
    void closeEvent(QCloseEvent* event) override;

signals:
    /**
     * @brief Signal emitted when the user wants to exit the game.
     */
    void exitGame();
};

#endif //FLOODITGAMEOVER_HPP