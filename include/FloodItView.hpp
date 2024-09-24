//
// Created by Enzo Renard on 21/09/2024.
//

#ifndef FLOODITVIEW_HPP
#define FLOODITVIEW_HPP
#include "GameController.hpp"
#include "GameSettings.hpp"
#include "FloodItView.hpp"
#include <memory>
#include <QWidget>
class FloodItView : public QWidget {
    Q_OBJECT
    bool wantToExit;

    void endOfGame();

public:
    FloodItView(std::shared_ptr<GameController> game);

    virtual ~FloodItView() = default;

    int start(QApplication* myQtApp);

protected:
    void closeEvent(QCloseEvent* event) override;

signals:
    void exitGame();
};
#endif //FLOODITVIEW_HPP
