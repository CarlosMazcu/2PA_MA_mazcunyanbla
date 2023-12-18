/**
 * @file game.h
 * @author Carlos Mazcuñán Blanes <mazcunyanbla@esat-alumni.com>
 * @brief header with game class who manage the game loop
 * 
 * Game class and other algorithms and functions that initializes, update and releas the
 * resources needed
 *
 * @version 1.5
 * @date 2023-12-3
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __GAME_H__
#define __GAME_H__ 1

#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>

#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>
#include <esat_extra/soloud/soloud.h>
#include <esat_extra/soloud/soloud_wav.h>

#include "app_window.h"
#include "gtexture.h"
#include "gsprite.h"
#include "entity.h"
#include "path.h"
#include "game_manager.h"
/**
 * @brief Class representing the main game logic and loop.
 *
 * The Game class encapsulates the main game logic, including initialization,
 * the main game loop, and cleanup.
 */
class game
{
 public:
  game(/* args */);
  ~game();

  /**
   * @brief Initialize the game.
   *
   * Initializes various aspects of the game, including loading music samples,
   * setting the initial game state (welcome window), configuring window properties,
   * applying a theme, initializing music variables, and setting the global speed.
   * It also initializes audio using the SoLoud library and sets mouse visibility.
   */
  void init();
  /**
   * @brief Main game loop.
   *
   * This method contains the main loop of the game, which runs as long as the window is open,
   * the Escape key is not pressed, and the exit flag in the GameManager is not set.
   * It calculates the delta time, clears the screen, begins drawing, and processes the main menu bar
   * and the game state machine. The loop continues until the exit conditions are met.
   */
  void gameLoop();
  /**
   * @brief Finalize and clean up resources.
   *
   * This method is responsible for finalizing the game and cleaning up resources.
   */
  void finish();
};

/**
 * @brief Initialize animation configurations for various characters.
 *
 * Initializes animation configurations for different characters
 * by calling specific initialization functions for each character type.
 */
void initAllAnimationConfig();

/**
 * @brief Update animations for various characters.
 *
 * This function updates animations for different characters
 * by calling specific update functions for each character type.
 */
void updateAllAnimation();
/**
 * @brief Initialize animation configuration for Flygon.
 *
 * Initializes the animation configuration for the Flygon character.
 * It sets the initial phase, animation configuration parameters, and creates
 * an AnimationInstance for the Flygon character using the specified configuration.
 */
void initAnimationConfigFlygon();
/**
 * @brief Initialize animation configuration for Manektrik.
 *
 * Initializes the animation configuration for Manektrik.
 * It sets the initial phase, animation configuration parameters, and creates
 * an AnimationInstance using the specified configuration.
 */
void initAnimationConfigManektrik();
/**
 * @brief Initialize animation configuration for the main character.
 *
 * Initializes the animation configuration for main character.
 * It sets the initial phase, animation configuration parameters, and creates
 * an AnimationInstance using the specified configuration.
 */
void initAnimationConfigMainCharacter();
/**
 * @brief Initialize animation configuration for Volbeat.
 *
 * Initializes the animation configuration for Volbeat.
 * It sets the initial phase, animation configuration parameters, and creates
 * an AnimationInstance using the specified configuration.
 */
void initAnimationConfigVolbeat();
/**
 * @brief Initialize animation configuration for Torchic.
 *
 * Initializes the animation configuration for Torchic.
 * It sets the initial phase, animation configuration parameters, and creates
 * an AnimationInstance using the specified configuration.
 */
void initAnimationConfigTorchic(); 
/**
 * @brief Update the animation for Flygon.
 *
 * This function updates the animation for Flygon based on its current phase.
 * It increments the phase and switches between different animation configurations for
 * Flygon's movement. The animation is updated using AnimationInstance with the specified
 * configuration for each phase. The update is performed using the delta time and the
 * global speed factor.
 */
void updateAnimationFlygon();
/**
 * @brief Update the animation for Manektrik.
 *
 * This function updates the animation for Manektrik based on its current phase.
 * It increments the phase and switches between different animation configurations for
 * Manektrik's movement. The animation is updated using AnimationInstance with the specified
 * configuration for each phase. The update is performed using the delta time and the
 * global speed factor.
 */
void updateAnimationManektrik();
/**
 * @brief Update the animation for the main character.
 *
 * This function updates the animation for the main character based on its current phase.
 * It increments the phase and switches between different animation configurations for
 * the main character's movement. The animation is updated using AnimationInstance with the specified
 * configuration for each phase. The update is performed using the delta time and the
 * global speed factor.
 */
void updateAnimationMainCharacter();
/**
 * @brief Update the animation for Volbeat.
 *
 * This function updates the animation for Volbeat based on its current phase.
 * It increments the phase and switches between different animation configurations for
 * Volbeat's movement. The animation is updated using AnimationInstance with the specified
 * configuration for each phase. The update is performed using the delta time and the
 * global speed factor.
 */
void updateAnimationVolbeat();
/**
 * @brief Update the animation for Flygon.
 *
 * This function updates the animation for Flygon based on its current phase.
 * It increments the phase and switches between different animation configurations for
 * Flygon's movement. The animation is updated using AnimationInstance with the specified
 * configuration for each phase. The update is performed using the delta time and the
 * global speed factor.
 */
void updateAnimationTorchic();
/**
 * @brief Initialize background.
 *
 * Initialize all data for the different entities for parallax background
 */
void initAllEntityParallax();
/**
 * @brief Initialize characters.
 *
 * Initialize all data for the different entities for the characters
 */
void initAllEntityCharacter();
/**
 * @brief Update background.
 *
 * Update and move the background in different layers and different speed to have
 * parallax effect. Also teleport the sprites at the begining when arrive to the window limit
 */
void updateParallax();
/**
 * @brief Draw background.
 *
 * Draw all sprites for the background
 *  Space, clouds, mountains, small and big trees and grass
 */
void drawParallax();
/**
 * @brief Draw sprites for various characters.
 *
 * This function draws sprites for different characters
 * by calling specific update functions for each character type.
 */
void drawSprites();
/**
 * @brief Draw and animate Manektrik.
 *
 * This function draws sprite for Manektrik and do the effect that runs changing
 * sprites in a time lapse
 */
void animManektrik();
/**
 * @brief Draw and animate the main character.
 *
 * This function draws sprite for the main character and do the effect that runs changing
 * sprites in a time lapse
 */
void animMainCharacter();
/**
 * @brief Draw and animate Volbeat.
 *
 * This function draws sprite for Volbeat and do the effect that runs changing
 * sprites in a time lapse
 */
void animVolbeat();
/**
 * @brief Draw and animate Torchic.
 *
 * This function draws sprite for Torchic and do the effect that runs changing
 * sprites in a time lapse
 */
void animTorchic();

#endif