//
// Created by Enzo Renard on 26/09/2024.
//

#include "BlockView.hpp"
#include <QHash>


BlockView::BlockView(std::shared_ptr<GameController> controller, int color, QWidget* parent): QWidget(parent),
    controller(controller), color(color) {
    setFixedSize(30,30);
}

void BlockView::setColor(QColor color) {
}

QColor BlockView::getColor() const {
    if (color < 0 || color >= controller->getMaxColor()) {
        return {0, 0, 0}; 
    }

    return QColor::fromHsv(color * 255/controller->getMaxColor(), 255, 128);
}

void BlockView::updateQt(int color) {
}

void BlockView::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    QRect block;
    QPen pen;
    pen.setColor(getColor());
    painter.setPen(pen);
    block.setRect(0,0,30,30);
    painter.fillRect(block,getColor());
    painter.drawRect(block);
}


#include "moc_BlockView.cpp"
