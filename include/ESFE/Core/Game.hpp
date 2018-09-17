/*   Game.hpp
 * 
 * Copyright 2018 - Elite Fun
 * Version: alpha 1
 * Date: 2018-02-23
 * 
 * Game class declaration. This class holds
 * the window, the game loop, etc.
 */

#ifndef ESFE_GAME_HPP
#define ESFE_GAME_HPP

#include <ESFE/Core/SceneManager.hpp>
#include <ESFE/Util/Logger.hpp>

#include <SFML/Graphics.hpp>

namespace esfe
{

class State; // fwd decl

class Game
{
  public:
    /**
     * @brief Construct a new Game object
     * 
     * @param mode VideoMode for the window
     * @param title String title for the window
     * @param style Uint32 style for the window
     * @param framerate Int framerate of the game
     */
    Game(sf::VideoMode mode, const sf::String &title, sf::Uint32 style = sf::Style::Default,
         int framerate = 60);

    /**
     * @brief starts the game loop
     * 
     */
    void gameLoop();

    sf::RenderWindow window; ///< game window

    esfe::SceneManager sceneManager; ///< game state manager

  private:
    sf::Color m_clearColor; ///< window clear color

    int m_framerate; ///< game framerate
};

} // namespace esfe

#endif // ESFE_GAME_HPP
