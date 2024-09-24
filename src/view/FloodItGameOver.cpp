//
// Created by Enzo Renard on 21/09/2024.
//
#include "FloodItGameOver.hpp"

FloodItGameOver::FloodItGameOver(std::shared_ptr<GameController> game) {

}

void FloodItGameOver::restartGame() {
    // todo : add model game restart
    close();
    deleteLater();
}

void FloodItGameOver::quitGame() {
    emit exitGame();
    deleteLater();
}

#include "moc_FloodItGameOver.cpp"