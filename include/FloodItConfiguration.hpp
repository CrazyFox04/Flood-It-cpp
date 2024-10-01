//
// Created by Enzo Renard on 21/09/2024.
//

#ifndef FLOODITCONFIGURATION_HPP
#define FLOODITCONFIGURATION_HPP

#include <GameSettings.hpp>
#include "FloodItConfiguration.hpp"
#include <memory>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QWidget>

class FloodItConfiguration : public QWidget {
    Q_OBJECT
    bool wantToExit;
    QVBoxLayout* layout_;
    QFormLayout* form_layout_;
    QLabel* titleLabel;
    QLabel* boardHeightLabel;
    QLabel* boardWidthLabel;
    QLabel* numberOfColorLabel;
    QLineEdit* boardHeightLineEdit;
    QLineEdit* boardWidthLineEdit;
    QLineEdit* numberOfColorLineEdit;
    QPushButton* startButton_;
    GameSettings* settings_;

    void configureWindow();

    void createLineEdits();

    void addFields();

    void createButtons();

    void setValues();

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
