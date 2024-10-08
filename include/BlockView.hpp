//
// Created by Enzo Renard on 26/09/2024.
//

#ifndef BLOCKVIEW_HPP
#define BLOCKVIEW_HPP
#include <GameController.hpp>
#include <QColor>
#include <QLinearGradient>
#include <QPainter>
#include <QWidget>

class BlockView : public QWidget {
    Q_OBJECT
    //Q_PROPERTY(QColor color READ getColor write setColor)
    std::shared_ptr<GameController> controller;
    int color;
    int x;
    int y;

    QLinearGradient getGradient(int x, int y) const;

public:
    BlockView(std::shared_ptr<GameController> controller, int color, int x, int y, QWidget* parent = nullptr);

    void paintEvent(QPaintEvent* event) override;

    void updateQt(int color);

    void setColor(QColor color); // todo : maybe private
    QColor getColor() const;

    void makeItBlink(int blinkTime);

    QColor getColorFromNumber(int color);

protected:
    void mousePressEvent(QMouseEvent* event) override;
};
#endif //BLOCKVIEW_HPP
