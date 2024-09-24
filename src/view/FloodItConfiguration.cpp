//
// Created by Enzo Renard on 21/09/2024.
//
#include "FloodItConfiguration.hpp"
#include <QCloseEvent>

FloodItConfiguration::FloodItConfiguration(GameSettings* settings) {
}

void FloodItConfiguration::closeEvent(QCloseEvent* event) {
    if (wantToExit) {
        emit exitGame();
        deleteLater();
    } else {
        QWidget::closeEvent(event);
    }
}

void FloodItConfiguration::closeWidget() {
    wantToExit = false;
    close();
    deleteLater();
}

#include "moc_FloodItConfiguration.cpp"
