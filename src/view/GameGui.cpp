//
// Created by Enzo Renard on 21/09/2024.
//

#include <QApplication>

#include "GameGui.hpp"

#include <Game.hpp>
#include <iostream>
#include <memory>

#include "FloodItConfiguration.hpp"
#include "FloodItView.hpp"
#include "FloodItGameOver.hpp"

GameGui::GameGui() : wantToExit(false), settings(), controller(std::make_shared<Game>()) {
}

void GameGui::run(int argc, char** argv) {
    QApplication* myApp = new QApplication(argc, argv);
    flood_it_configuration = new FloodItConfiguration(&settings);
    flood_it_view = new FloodItView(controller);
    flood_it_game_over = new FloodItGameOver(controller);
    myApp->setQuitOnLastWindowClosed(false);
    configureEndOfConfiguration();
    flood_it_configuration->show();
    myApp->exec();
    delete myApp;
}

void GameGui::configureEndOfConfiguration() {
    QObject::connect(flood_it_configuration, &QObject::destroyed, [=]() mutable {
        if (wantToExit) {
            QApplication::quit();
        }
        else {
            controller = std::make_shared<Game>(settings, player);
            // todo : add model start here
            flood_it_view = new FloodItView(controller);
            controller->addObserver(flood_it_view);
            flood_it_view->show();
            configureEndOfView();
        }
    });
    QObject::connect(flood_it_configuration, &FloodItConfiguration::exitGame, [=]() mutable {
        wantToExit = true;
    });
}

void GameGui::configureEndOfView() {
    QObject::connect(flood_it_view, &QObject::destroyed, [=]() mutable {
        flood_it_game_over = new FloodItGameOver(controller);
        flood_it_game_over->show();
        configureEndOfGameOver();
    });
}

void GameGui::configureEndOfGameOver() {
    QObject::connect(flood_it_game_over, &QObject::destroyed, [=]() mutable {
        if (wantToExit) {
            QApplication::quit();
        } else {
            flood_it_configuration = new FloodItConfiguration(&settings);
            flood_it_configuration->show();
            configureEndOfConfiguration();
        }
    });
    QObject::connect(flood_it_game_over, &FloodItGameOver::exitGame, [=]() mutable {
        wantToExit = true;
    });
}
