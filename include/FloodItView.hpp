//
// Created by Enzo Renard on 21/09/2024.
//

#ifndef FLOODITVIEW_HPP
#define FLOODITVIEW_HPP
#include <BoardBox.hpp>

#include "GameController.hpp"
#include "GameSettings.hpp"
#include "FloodItView.hpp"
#include <memory>
#include <qboxlayout.h>
#include <QWidget>
#include "Observer.hpp"

class FloodItView : public QWidget, public Observer {
    Q_OBJECT
    QHBoxLayout* mainLayout;
    BoardBox* myBoardBox;
    std::shared_ptr<GameController> controller;

    void endOfGame();

public:
    FloodItView(std::shared_ptr<GameController> game);

    virtual ~FloodItView() = default;

    int start(QApplication* myQtApp);

    void update() override;

protected:
    void closeEvent(QCloseEvent* event) override;

signals:
    void updateQt();
};
#endif //FLOODITVIEW_HPP
