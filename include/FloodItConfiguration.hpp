//
// Created by Enzo Renard on 21/09/2024.
//

#ifndef FLOODITCONFIGURATION_HPP
#define FLOODITCONFIGURATION_HPP

#include <GameSettings.hpp>
#include "FloodItConfiguration.hpp"
#include <memory>
#include <QWidget>

class FloodItConfiguration : public QWidget {
    Q_OBJECT
    bool wantToExit;

    void closeWidget();

public:
    FloodItConfiguration(GameSettings* settings);

    virtual ~FloodItConfiguration() = default;

    int start(QApplication* myQtApp);

protected:
    void closeEvent(QCloseEvent* event) override;

signals:
    void exitGame();
};
#endif //FLOODITCONFIGURATION_HPP
