//
// Created by Enzo Renard on 26/09/2024.
//

#ifndef BOARDBOX_HPP
#define BOARDBOX_HPP
#include <BlockView.hpp>
#include <QWidget>
#include <QtWidgets/qgridlayout.h>
#include <memory>
#include "GameController.hpp"


class BoardBox : public QWidget {
    Q_OBJECT
    std::shared_ptr<GameController> controller;
    QGridLayout* grid;
    QList<QList<BlockView *>> blocks;

public:
    explicit BoardBox(std::shared_ptr<GameController> controller, QWidget* parent = nullptr);

public slots :
    void updateQt();

protected:
    void paintEvent(QPaintEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;

private:
    void drawBorder(QPainter&painter);

    void updateBlocks();

    void animateChangedBlocks();
};
#endif //BOARDBOX_HPP
