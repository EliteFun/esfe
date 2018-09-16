/*   Scene.hpp
 * 
 * Copyright 2018 - Elite Fun
 * Version: alpha 1.0
 * Date: 2018-02-24
 * 
 * Scene class declaration. This is
 * a virtual class that contain all
 * the methods and members that each
 * child Scene will have.
 */


#ifndef ESFE_SCENE_HPP
#define ESFE_SCENE_HPP


#include <ESFE/Core/Game.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace esfe
{

class Scene
{
public:

    /**
     * @brief called when there is a window event
     * 
     * @param e the current event
     */
    virtual void onEvent     (sf::Event &e) = 0;

    /**
     * @brief update function called every frame 
     * 
     * @param dt delta time
     */
    virtual void update      (float dt)     = 0;

    /**
     * @brief draw function called every time the game renders
     * 
     * @param dt delta time
     */
    virtual void draw        (float dt)     = 0;

protected:

    esfe::Game* m_game; ///< pointer to the game
};

} // namespace esfe

#endif // ESFE_SCENE_HPP
