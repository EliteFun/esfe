/*   Game.hpp
 * 
 * Version: dev 0.0.2
 * Copyright 2018 - Elite Fun
 * Date: 2018-02-23
 * 
 * Game class declaration. This class holds
 * the window, the game loop, etc.
 */


#pragma once


/***** HEADERS *****/

#include <ESFE/Core/SceneManager.hpp>
#include <ESFE/Util/Logger.hpp>

#include <SFML/Graphics.hpp>


namespace esfe
{

class State; // avoid header loop
    
class Game
{
public:

    Game(sf::VideoMode mode, const sf::String& title, sf::Uint32 style = sf::Style::Default,
         int framerate = 60);
    
    void gameLoop();
    
    sf::RenderWindow window; ///< game window
    
    esfe::SceneManager stateManager; ///< game state manager // TODO: change to sceneManager
    
private:
    
    sf::Color m_clearColor; ///< window clear color
    
    int m_framerate;

};

} // namespace esfe
