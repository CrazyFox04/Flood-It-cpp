//
// Created by Enzo Renard on 21/09/2024.
//

#ifndef FLOODITGAMEOVER_HPP
#define FLOODITGAMEOVER_HPP
#include <GameController.hpp>

#include "FloodItGameOver.hpp"
#include "GameSettings.hpp"
#include <memory>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QtWidgets/qboxlayout.h>


class FloodItGameOver : public QWidget {
    Q_OBJECT
    std::shared_ptr<GameController> controller_;
    QVBoxLayout* mainLayout;
    QHBoxLayout* buttonLayout;
    QLabel* gameOverLabel;
    QLabel* detailsLabel;
    QLabel* leaderboardLabel;
    QPushButton* restartButton;
    QPushButton* exitButton;

private:
    void configureWindow();

    void createItems();

    void updateItems();

public:
    FloodItGameOver(std::shared_ptr<GameController> game);

    virtual ~FloodItGameOver() = default;

    int start(QApplication* myQtApp);

    void restartGame();

    void quitGame();

protected:
    void closeEvent(QCloseEvent* event) override;

signals:
    void exitGame();
};

#endif //FLOODITGAMEOVER_HPP
