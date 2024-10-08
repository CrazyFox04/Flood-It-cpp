//
// Created by Enzo Renard on 21/09/2024.
//
#include "FloodItView.hpp"

#include <QApplication>

FloodItView::FloodItView(std::shared_ptr<GameController> game) : mainLayout(new QHBoxLayout(this)),
                                                                 myBoardBox(new BoardBox(game, this)), controller(game) {
    mainLayout->addWidget(myBoardBox);
    setLayout(mainLayout);
    myBoardBox->setFocus();
}
int FloodItView::start (QApplication *app) {
    show();
    return app->exec();
}
void FloodItView::closeEvent(QCloseEvent* event) {
    endOfGame();
}

void FloodItView::endOfGame() {
    close();
    controller->removeObserver(this);
    deleteLater();
}

void FloodItView::update() {
    emit updateQt();
    if (controller->isFinished()) {
        endOfGame();
    }
}

#include "moc_FloodItView.cpp"
