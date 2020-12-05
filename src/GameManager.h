/**
 * @file GameManager.h
 * @brief Definition of the GameManager class.
 * 
 * @version 1.0
 * @date 2020-12-06
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

// include required components
#include "ObjectManager.h"
#include "ObjectGenerator.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "GameObject/MovableObject/Player.h"

#include <math.h>
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

/**
 * @brief Handles the gameplay by providing an interface to ``main()``.
 * 
 * ``main()`` 에서 생성되어 게임을 실행하는 클래스.
 * 
 * This class handles the entire gameplay with all ``...Manager`` class objects 
 * and handles the interaction between those objects. Instantiated and used by ``main()``.
 * 
 * Expected to be used like the example below.
 * 
 * ```{.cpp}
 * #include ... // include required components
 * 
 * // global variables here
 * 
 * int main()
 * {
 *     GameManager game; // handles everything (user input, rendering, etc.) with initialization
 * 
 *     return 0;
 * }
 * ```
 * 
 * @see ObjectManager, InputManager, SceneManager
 */
class GameManager
{

private:
	/**
	 * @brief The ObjectManager object to use.
	 * 
	 * Will be referenced in ObjectGenerator and SceneManager.
	 */
	ObjectManager m_ObjectManager;
	ObjectGenerator m_ObjectGenerator; //!< The ObjectGenerator object to use.
	InputManager m_InputManager;       //!< The InputManager object to use.
	SceneManager m_SceneManager;       //!< The SceneManager object to use.
	
	bool exit = false;                 //!< ``true`` if game should exit, ``false`` otherwise.
	bool is_start = false;

	system_clock::time_point curr;     //!< %Current time point. Used in ``delta`` calculation.
	system_clock::time_point prev;     //!< Previous time point. Used in ``delta`` calculation.

	/**
	 * @brief Prepares the gameplay.
	 * 
	 * Initializes Manager objects, generates default obstacles, and display obstacles.
	 */
	void Ready();
	/**
	 * @brief Plays and renders a frame of gameplay.
	 * 
	 * Calls SceneManager::Render() to render the objects from ObjectManager, 
	 * InputManager::GetInput(), InputManager::ListenInput() to get the user input.
	 * 
	 * Handles the game input events, and game over events.
	 * - Loads input value and moves player, changes direction, change textures.
	 * - Saves score to file if the current score is the higher than current \c high_score .
	 */
	void Play();
	/**
	 * @brief Pauses the gameplay.
	 * 
	 * Called when user input is \c SPACE .
	 */
	void Pause();
	/**
	 * @brief Calculate the position of objects in next frame.
	 * 
	 * Moves movable objects and checks collision between objects.
	 * 
	 * Checks collision between:
	 * - \c MovableObject and \c Player
	 * - \c MovableObject and \c GameObject (immovable)
	 * - \c GameObject and \c Player
	 */
	void Update();
	/**
	 * @brief Returns the score from the given distance.
	 * 
	 * Since the distance is in \c float type, which is an abstract representation 
	 * of the position of the player in game, and the score is in \c int type, 
	 * which is denoted as _meters_ in the scoreboard, the abstract position 
	 * should be converted into distance traveled with a reasonable conversion rate.
	 * 
	 * Current conversion rate is \c 1.0 , implemented with \c floor(float) function.
	 */
	void DistanceToScore();
	/**
	 * @brief Reads and loads high score data from \c highscore.dat file into \c high_score .
	 * 
	 * @return \c 0 if the content of the file is not a positive integer or the file doesn't exist. 
	 * 
	 * ## File content structure
	 * ``highscore.dat`` file consists of 1 positive integer value as text. 
	 * Will be written with ``cout`` or ``printf`` and should be able to be read with ``cin`` or ``scanf``. 
	 * 
	 * Example ``highscore.dat``
	 * ```
	 * 420
	 * ```
	 */
	int LoadHighScore();
	/**
	 * @brief Saves and writes high score data from ``high_score`` into ``highscore.dat`` file.
	 * 
	 * Creates ``highscore.dat`` file if the file doesn't exist.
	 */
	void SaveHighScore();

public:
	/**
	 * @brief Construct a new GameManager object
	 */
	GameManager();
};

#endif