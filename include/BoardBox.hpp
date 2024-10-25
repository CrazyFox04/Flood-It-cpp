//
// Created by Enzo Renard on 26/09/2024.
//

#ifndef BOARDBOX_HPP
#define BOARDBOX_HPP

#include "BlockView.hpp"
#include <QWidget>
#include <QtWidgets/qgridlayout.h>
#include <memory>
#include "GameController.hpp"

/**
 * @class BoardBox
 * @brief A custom QWidget that represents the game board.
 *
 * This class handles the rendering and interaction of the game board, including the blocks and their animations.
 */
class BoardBox : public QWidget {
    Q_OBJECT

    std::shared_ptr<GameController> controller; ///< Shared pointer to the game controller.
    QGridLayout* grid; ///< Layout manager for arranging the blocks in a grid.
    QList<QList<BlockView *>> blocks; ///< 2D list of pointers to BlockView objects representing the blocks.

    /**
     * @brief Draws the border of the board.
     * @param painter The QPainter object used for drawing.
     */
    void drawBorder(QPainter& painter);

    /**
     * @brief Updates the blocks on the board.
     */
    void updateBlocks();

    /**
     * @brief Animates the blocks that have changed.
     */
    void animateChangedBlocks();

    /**
     * @brief Creates the blocks for the board.
     */
    void createBlocks();

public:
    /**
     * @brief Constructor for BoardBox.
     * @param controller Shared pointer to the game controller.
     * @param parent Parent widget.
     */
    explicit BoardBox(std::shared_ptr<GameController> controller, QWidget* parent = nullptr);

    public slots:
        /**
         * @brief Slot to update the board in the Qt framework.
         */
        void updateQt();

protected:
    /**
     * @brief Paint event handler.
     * @param event The paint event.
     */
    void paintEvent(QPaintEvent* event) override;
};

#endif // BOARDBOX_HPP