//
// Created by Enzo Renard on 21/09/2024.
//
#include "FloodItConfiguration.hpp"
#include <QCloseEvent>

FloodItConfiguration::FloodItConfiguration(GameSettings* settings): wantToExit(true), layout_(new QVBoxLayout(this)),
                                                                    form_layout_(new QFormLayout()),
                                                                    titleLabel(new QLabel("Flood-It")),
                                                                    boardHeightLabel(new QLabel("Board Height")),
                                                                    boardWidthLabel(new QLabel("Board Width")),
                                                                    numberOfColorLabel(new QLabel("Number of colors")),
                                                                    boardHeightLineEdit(
                                                                        new QLineEdit(QString::number(0), this)),
                                                                    boardWidthLineEdit(
                                                                        new QLineEdit(QString::number(0), this)),
                                                                    numberOfColorLineEdit(
                                                                        new QLineEdit(QString::number(0), this)),
                                                                    startButton_(new QPushButton("Start", this)),
                                                                    settings_(settings) {
    setWindowTitle("Flood-It configuration");
    configureWindow();
    setLayout(layout_);
}

void FloodItConfiguration::configureWindow() {
    resize(400, 300);
    createLineEdits();
    addFields();
    createButtons();
    setValues();

    layout_->addWidget(titleLabel);
    layout_->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout_->addLayout(form_layout_);
    layout_->addWidget(startButton_);
    layout_->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    layout_->setAlignment(titleLabel, Qt::AlignCenter);
    layout_->setAlignment(form_layout_, Qt::AlignCenter);
    layout_->setAlignment(startButton_, Qt::AlignCenter);

    layout_->setContentsMargins(10, 10, 10, 10);
}

void FloodItConfiguration::setValues() {
    boardHeightLineEdit->setText(QString::number(settings_->board_height));
    boardWidthLineEdit->setText(QString::number(settings_->board_width));
    numberOfColorLineEdit->setText(QString::number(settings_->number_color));
}

void FloodItConfiguration::createButtons() {
    connect(startButton_, &QPushButton::clicked, this, &FloodItConfiguration::closeWidget);
}

void FloodItConfiguration::createLineEdits() {

}

void FloodItConfiguration::addFields() {
    form_layout_->addRow(boardWidthLabel, boardWidthLineEdit);
    form_layout_->addRow(boardHeightLabel, boardHeightLineEdit);
    form_layout_->addRow(numberOfColorLabel, numberOfColorLineEdit);

    QList<QWidget *> widgets = {boardHeightLineEdit, boardWidthLineEdit, numberOfColorLineEdit};
    for (auto widget : widgets) {
        widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        widget->setMinimumWidth(300);
    }
}

void FloodItConfiguration::closeEvent(QCloseEvent* event) {
    if (wantToExit) {
        emit exitGame();
        deleteLater();
    }
    else {
        QWidget::closeEvent(event);
    }
}

void FloodItConfiguration::closeWidget() {
    wantToExit = false;
    close();
    deleteLater();
}


#include "moc_FloodItConfiguration.cpp"
