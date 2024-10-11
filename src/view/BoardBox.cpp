//
// Created by Enzo Renard on 26/09/2024.
//
#include "BoardBox.hpp"

#include <QPainter>

BoardBox::BoardBox(std::shared_ptr<GameController> controller, QWidget* parent) : QWidget(parent),
                                                                                  controller(controller), grid(new QGridLayout(this)) {
    connect(parent, SIGNAL(updateQt()), this, SLOT(updateQt()));
    grid->setContentsMargins(0, 0, 0, 0);
    grid->setSpacing(0);
    setLayout(grid);
    createBlocks();
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

void BoardBox::createBlocks() {
    for (int i = 0; i < controller->getBoard().getHeight(); ++i) {
        QList<BlockView*> list;
        for (int j = 0; j < controller->getBoard().getWidth(); ++j) {
            const auto blockView = new BlockView(controller, controller->getBoard().get_color(i,j), i, j, this);
            list.append(blockView);
            grid->addWidget(blockView, i, j);
        }
        blocks.append(list);
    }
}

void BoardBox::updateBlocks() {
    for (int i = 0; i < blocks.size(); ++i) {
        for (int j = 0; j < blocks[0].size(); ++j) {
            blocks[i][j]->updateQt(controller->getBoard().get_color(i,j));
        }
    }
}

void BoardBox::updateQt() {
    updateBlocks();
}

void BoardBox::drawBorder(QPainter& painter) {

}


#include "moc_BoardBox.cpp"
