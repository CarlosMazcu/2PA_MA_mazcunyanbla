/**
 * @file app_window.h
 * @author Carlos Mazcuñán Blanes <mazcunyanbla@esat-alumni.com>
 * @brief Header that manage the windows and game states 
 * @version 2.0
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __APP_WINDOW__
#define __APP_WINDOW__ 1

#include "esat_extra/imgui.h"
#include "game_manager.h"
#include "gsprite.h"

/**
* @brief Main menu bar for the game's user interface.
*
* This function creates a main menu bar using ImGui for the game's user interface. It includes
* options for changing the theme, displaying settings information, and selecting music tracks.
*
*/
void MainMenuBar();

/**
* @brief Manages the visibility of different windows in the game.
*
* This function is responsible for managing the visibility of various windows in the game,
* such as the welcome window, credits window, parallax window, and path window.
*
* @param n An integer representing the window to be displayed:
*   - 0: Welcome window
*   - 1: Credits window
*   - 2: Parallax window
*   - 3: Path window
*/
void windowManager(int n);
/**
 * @brief Displays the welcome window of the game.
 *
 * Shows the welcome window, which is the initial window that appears when
 * the game is executed. It provides options for navigating to different sections of the game,
 * such as animations, paths, and credits. Additionally, it allows the user to exit the game.
 */
void welcomeWindow();

/**
 * @brief Displays the credits window of the game.
 *
 * This function renders the credits window, providing information about the project's authors.
 */
void creditsWindow();
/**
 * @brief Displays the parallax window of the game.
 *
 * This function shows the aniamtion of the  pokemon intro window, 
 * allowing users to configure settings related to speed and volume.
 * It provides options to start, stop, and return to the welcome window.
 */
void parallaxWindow();
/**
 * @brief Initializes the path for the game.
 *
 * This function initializes the path used in the path window. It stores the stroke and fill colors,
 * removes all existing vertices, updates the vertices, and sets the initial position and size of the path entity.
 */
void initPath();
/**
 * @brief Renders the window for configuring and displaying the path in the game.
 *
 * This function displays an ImGui window for configuring various parameters related to the game's path.
 * It provides controls for adjusting the position, scale, rotation, number of vertices, stroke color, fill color,
 * and whether the path should be solid or not.
 */
void pathWindow();
/**
 * @brief Manages the game's state machine, directing the flow of the program based on the current state.
 *
 * This function is responsible for handling the game's state machine, 
 * where different windows or states are
 * displayed based on the current state of the game. 
*/
void stateMachine();
/**
 * @brief Sets the Dark Purple color theme for ImGui windows.
 *
 * This function modifies the ImGui style to apply the Dark Purple color theme to ImGui windows.
 */
void themePurple();
/**
 * @brief Sets the Lemon Pie color theme for ImGui windows.
 *
 * This function modifies the ImGui style to apply the Lemon Pie color theme to ImGui windows.
 */
void themeLemonPie();
/**
 * @brief Sets the default color theme for ImGui windows.
 *
 * This function modifies the ImGui style to apply the default color theme to ImGui windows.
 */
void themeBoring();
/**
 * @brief Sets the Orange and Dark color theme for ImGui windows.
 *
 * This function modifies the ImGui style to apply the Orange and Dark color theme to ImGui windows.
 */
void darkTaronja();
/**
 * @brief Sets the Black and White color theme for ImGui windows.
 *
 * This function modifies the ImGui style to apply the Black and White color theme to ImGui windows.
 */
void themeBW();
/**
 * @brief Sets the Aquamarine color theme for ImGui windows.
 *
 * This function modifies the ImGui style to apply the Aquamarine color theme to ImGui windows.
 */
void aquamarineTheme();
/**
 * @brief Sets the Pink color theme for ImGui windows.
 *
 * This function modifies the ImGui style to apply the Pink color theme to ImGui windows.
 */
void hiBarbieTheme();
/**
 * @brief Handles input for adjusting the animation speed.
 *
 * This function checks for specific key presses to increase or decrease the animation speed.
 */
void inputSpeed();
/**
 * @brief Updates the GameManager's sample name based on the current selected audio sample.
 *
 * This function sets the sample name based on the current audio sample selected.
 * If audio is not available, it sets the sample name to indicate that audio is not available.
 */
void sampleName();

#endif