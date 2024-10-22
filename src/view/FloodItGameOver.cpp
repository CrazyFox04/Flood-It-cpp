//
// Created by Enzo Renard on 21/09/2024.
//
#include "FloodItGameOver.hpp"

#include <QCloseEvent>

FloodItGameOver::FloodItGameOver(std::shared_ptr<GameController> game): controller_(game),
                                                                        mainLayout(new QVBoxLayout(this)),
                                                                        buttonLayout(new QHBoxLayout()),
                                                                        gameOverLabel(new QLabel(this)),
                                                                        detailsLabel(new QLabel(this)),
                                                                        leaderboardLabel(new QLabel(this)),
                                                                        restartButton(new QPushButton("Restart", this)),
                                                                        exitButton(new QPushButton("Exit", this)) {
    configureWindow();
    createItems();
    setLayout(mainLayout);
    updateItems();
}

void FloodItGameOver::configureWindow() {
    setWindowTitle("Flood-It End Of Game");
    setFixedSize(500, 400);
}

void FloodItGameOver::createItems() {
    gameOverLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(gameOverLabel);

    detailsLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(detailsLabel);

    leaderboardLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(leaderboardLabel);

    buttonLayout->addWidget(restartButton);
    buttonLayout->addWidget(exitButton);
    buttonLayout->setSpacing(20);
    buttonLayout->setContentsMargins(10, 0, 10, 0);

    mainLayout->addLayout(buttonLayout);

    connect(restartButton, &QPushButton::clicked, this, &FloodItGameOver::restartGame);
    connect(exitButton, &QPushButton::clicked, this, &FloodItGameOver::quitGame);
}

void FloodItGameOver::updateItems() {
    gameOverLabel->setText("Game is finished !");
    detailsLabel->setText("You've finished the game in " + QString::number(controller_->get_play_count()) + " moves !");

    QString leaderboardText = "Leaderboard:\n";
    auto leaderboard = controller_->get_best_result(5);
    for (const auto& score : leaderboard) {
        leaderboardText += QString::fromStdString(score.settings.player_name) + ": " + QString::number(score.status.play_count) + " moves\n";
    }
    leaderboardLabel->setText(leaderboardText);
}

void FloodItGameOver::restartGame() {
    close();
    deleteLater();
}

void FloodItGameOver::quitGame() {
    emit exitGame();
    deleteLater();
}

void FloodItGameOver::closeEvent(QCloseEvent* event) {
    restartGame();
}

#include "moc_FloodItGameOver.cpp"
