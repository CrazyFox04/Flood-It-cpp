//
// Created by Enzo Renard on 21/09/2024.
//
#include "FloodItView.hpp"

FloodItView::FloodItView(std::shared_ptr<GameController> game): wantToExit() {
}

void FloodItView::closeEvent(QCloseEvent* event) {
    endOfGame();
}

void FloodItView::endOfGame() {
    close();
    deleteLater();
}


#include "moc_FloodItView.cpp"
