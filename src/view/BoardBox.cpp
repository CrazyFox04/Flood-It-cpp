//
// Created by Enzo Renard on 26/09/2024.
//
#include "BoardBox.hpp"

#include <QPainter>

BoardBox::BoardBox(std::shared_ptr<GameController> controller, QWidget* parent) : QWidget(parent),
                                                                                  controller(controller), grid() {
    connect(dynamic_cast<const QObject *>(parent), SIGNAL(updateQt()), this, SLOT(updateQt()));
    grid = new QGridLayout(this);
    grid->setContentsMargins(0, 0, 0, 0);
    setLayout(grid);
    updateBlocks();
}

void BoardBox::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    drawBorder(painter);
    for (auto& block_views : blocks) {
        for (auto& block_view : block_views) {
            block_view->update();
        }
    }
}

void BoardBox::updateBlocks() {
    for (auto& block_views : blocks) {
        for (auto& block_view : block_views) {
            block_view->updateQt(0); // todo : add func to get int at this pos -> maybe use for i instead of foreach
        }
    }
}

void BoardBox::mousePressEvent(QMouseEvent* event) {

}

void BoardBox::updateQt() {
    updateBlocks();
}

void BoardBox::drawBorder(QPainter& painter) {

}


#include "moc_BoardBox.cpp"
