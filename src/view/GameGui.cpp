//
// Created by Enzo Renard on 21/09/2024.
//

#include <QApplication>

#include "GameGui.hpp"
#include "FloodItConfiguration.hpp"
#include "FloodItView.hpp"
#include "FloodItGameOver.hpp"

GameGui::GameGui() : wantToExit(false), settings() {
}

void GameGui::run(int argc, char** argv) {
    QApplication* myApp = new QApplication(argc, argv);
    flood_it_configuration = new FloodItConfiguration(&settings);
    flood_it_view = new FloodItView(controller);
    flood_it_game_over = new FloodItGameOver(controller);
    myApp->setQuitOnLastWindowClosed(false);
    configureEndOfConfiguration();
    myApp->exec();
    delete myApp;
}

void GameGui::configureEndOfConfiguration() {

}

void GameGui::configureEndOfView() {

}

void GameGui::configureEndOfGameOver() {

}


