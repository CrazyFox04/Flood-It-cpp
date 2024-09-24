//
// Created by Enzo Renard on 21/09/2024.
//

#ifndef FLOODITGAMEOVER_HPP
#define FLOODITGAMEOVER_HPP
#include <GameController.hpp>

#include "FloodItGameOver.hpp"
#include "GameSettings.hpp"
#include <memory>
#include <QWidget>


class FloodItGameOver : public QWidget {
    Q_OBJECT
    bool wantToExit;

    void restartGame();

    void quitGame();

public:
    FloodItGameOver(std::shared_ptr<GameController> game);

    virtual ~FloodItGameOver() = default;

    int start(QApplication* myQtApp);

signals:
    void exitGame();
};

#endif //FLOODITGAMEOVER_HPP
