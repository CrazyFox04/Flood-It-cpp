//
// Created by Enzo Renard on 21/09/2024.
//

#ifndef FLOODITCONFIGURATION_HPP
#define FLOODITCONFIGURATION_HPP

#include "GameSettings.hpp"
#include "FloodItConfiguration.hpp"
#include <memory>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QWidget>

/**
 * @class FloodItConfiguration
 * @brief A custom QWidget for configuring the FloodIt game settings.
 *
 * This class provides a user interface for setting up the game parameters such as board dimensions,
 * number of colors, and player name. It also handles the validation and saving of these settings.
 */
class FloodItConfiguration : public QWidget {
    Q_OBJECT
    bool wantToExit; ///< Flag indicating if the user wants to exit.
    QVBoxLayout* layout_; ///< Main layout for the widget.
    QFormLayout* form_layout_; ///< Layout for the form fields.
    QLabel* titleLabel; ///< Label for the title.
    QLabel* boardHeightLabel; ///< Label for the board height field.
    QLabel* boardWidthLabel; ///< Label for the board width field.
    QLabel* numberOfColorLabel; ///< Label for the number of colors field.
    QLabel* playerNameLabel; ///< Label for the player name field.
    QLineEdit* boardHeightLineEdit; ///< Line edit for the board height.
    QLineEdit* boardWidthLineEdit; ///< Line edit for the board width.
    QLineEdit* numberOfColorLineEdit; ///< Line edit for the number of colors.
    QLineEdit* playerNameLineEdit; ///< Line edit for the player name.
    QPushButton* startButton_; ///< Button to start the game.
    GameSettings* settings_; ///< Pointer to the game settings.

    /**
     * @brief Configures the window properties.
     */
    void configureWindow();

    /**
     * @brief Creates the line edit fields.
     */
    void createLineEdits();

    /**
     * @brief Adds the form fields to the layout.
     */
    void addFields();

    /**
     * @brief Creates the buttons for the widget.
     */
    void createButtons();

    /**
     * @brief Sets the initial values for the form fields.
     */
    void setValues();

    /**
     * @brief Closes the widget.
     */
    void closeWidget();

    /**
     * @brief Shows a message indicating invalid settings.
     */
    void show_invalid_settings_message();

    /**
     * @brief Saves the game settings.
     */
    void save_game_settings();

public:
    /**
     * @brief Constructor for FloodItConfiguration.
     * @param settings Pointer to the game settings.
     */
    FloodItConfiguration(GameSettings* settings);

    /**
     * @brief Destructor for FloodItConfiguration.
     */
    virtual ~FloodItConfiguration() = default;

    /**
     * @brief Starts the configuration widget.
     * @param myQtApp Pointer to the QApplication.
     * @return An integer indicating the result of the start operation.
     */
    int start(QApplication* myQtApp);

protected:
    /**
     * @brief Handles the close event.
     * @param event The close event.
     */
    void closeEvent(QCloseEvent* event) override;

    /**
     * @brief Handles the key press event.
     * @param event The key event.
     */
    void keyPressEvent(QKeyEvent* event) override;

signals:
    /**
     * @brief Signal emitted when the user wants to exit the game.
     */
    void exitGame();
};

#endif //FLOODITCONFIGURATION_HPP