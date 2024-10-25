//
// Created by Enzo Renard on 21/09/2024.
//

#ifndef FLOODITVIEW_HPP
#define FLOODITVIEW_HPP
#include <BoardBox.hpp>

#include "GameController.hpp"
#include "GameSettings.hpp"
#include "FloodItView.hpp"
#include <memory>
#include <qboxlayout.h>
#include <QWidget>
#include "Observer.hpp"

/**
 * @class FloodItView
 * @brief A custom QWidget that represents the main view of the FloodIt game.
 *
 * This class handles the display and interaction of the main game view, including the game board and its layout.
 * It also observes changes in the game state and updates the view accordingly.
 */
class FloodItView : public QWidget, public Observer {
    Q_OBJECT
    QHBoxLayout* mainLayout; ///< Main layout for arranging the widgets horizontally.
    BoardBox* myBoardBox; ///< Pointer to the BoardBox widget representing the game board.
    std::shared_ptr<GameController> controller; ///< Shared pointer to the game controller.

    /**
     * @brief Handles the end of the game.
     */
    void endOfGame();

public:
    /**
     * @brief Constructor for FloodItView.
     * @param game Shared pointer to the game controller.
     */
    FloodItView(std::shared_ptr<GameController> game);

    /**
     * @brief Destructor for FloodItView.
     */
    virtual ~FloodItView() = default;

    /**
     * @brief Starts the main game view.
     * @param myQtApp Pointer to the QApplication.
     * @return An integer indicating the result of the start operation.
     */
    int start(QApplication* myQtApp);

    /**
     * @brief Updates the view when the observed subject changes.
     */
    void update() override;

protected:
    /**
     * @brief Handles the close event.
     * @param event The close event.
     */
    void closeEvent(QCloseEvent* event) override;

    signals:
        /**
         * @brief Signal emitted to update the Qt framework.
         */
        void updateQt();
};

#endif //FLOODITVIEW_HPP