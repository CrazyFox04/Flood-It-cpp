//
// Created by Enzo Renard on 26/09/2024.
//

#ifndef BLOCKVIEW_HPP
#define BLOCKVIEW_HPP

#include "GameController.hpp"
#include <QColor>
#include <QLinearGradient>
#include <QPainter>
#include <QWidget>

/**
 * @class BlockView
 * @brief A custom QWidget that represents a block in the game.
 *
 * This class handles the rendering and interaction of a single block in the game.
 */
class BlockView : public QWidget {
    Q_OBJECT

    std::shared_ptr<GameController> controller; ///< Shared pointer to the game controller.
    int color; ///< Color of the block.
    int x; ///< X-coordinate of the block.
    int y; ///< Y-coordinate of the block.

    /**
     * @brief Generates a gradient for the block.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @return A QLinearGradient object.
     */
    QLinearGradient getGradient(int x, int y) const;

public:
    /**
     * @brief Constructor for BlockView.
     * @param controller Shared pointer to the game controller.
     * @param color Color of the block.
     * @param x X-coordinate of the block.
     * @param y Y-coordinate of the block.
     * @param parent Parent widget.
     */
    BlockView(std::shared_ptr<GameController> controller, int color, int x, int y, QWidget* parent = nullptr);

    /**
     * @brief Paint event handler.
     * @param event The paint event.
     */
    void paintEvent(QPaintEvent* event) override;

    /**
     * @brief Updates the block's color in the Qt framework.
     * @param color The new color.
     */
    void updateQt(int color);

    /**
     * @brief Sets the color of the block.
     * @param color The new color.
     */
    void setColor(QColor color);

    /**
     * @brief Gets the color of the block.
     * @return The current color.
     */
    QColor getColor() const;

    /**
     * @brief Makes the block blink.
     * @param blinkTime The duration of the blink.
     */
    void makeItBlink(int blinkTime);

    /**
     * @brief Converts a color number to a QColor object.
     * @param color The color number.
     * @return The corresponding QColor object.
     */
    QColor getColorFromNumber(int color);

protected:
    /**
     * @brief Mouse press event handler.
     * @param event The mouse event.
     */
    void mousePressEvent(QMouseEvent* event) override;
};

#endif // BLOCKVIEW_HPP