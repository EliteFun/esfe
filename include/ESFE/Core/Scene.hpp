/*   State.hpp
 * 
 * Copyright 2018 - Elite Fun
 * Version: dev 0.0.2
 * Date: 2018-02-24
 * 
 * State class declaration. This is
 * a virtual class that contain all
 * the methods and members that each
 * child State will have.
 */


#ifndef ESFE_SCENE_HPP
#define ESFE_SCENE_HPP


/*** HEADERS ***/

#include <ESFE/Core/Game.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace esfe
{

    
/**
 * \class Scene
 * \code
 * //comming soon...
 * \endcode
 */
class Scene
{
public:
    
    virtual void onEvent     (sf::Event &e) = 0;
    virtual void update      (float dt)     = 0;
    virtual void timedUpdate (float dt)     = 0;
    virtual void lateUpdate  (float dt)     = 0;
    virtual void draw        (float dt)     = 0;

protected:

    esfe::Game* m_game;
};

}

#endif // ESFE_SCENE_HPP
