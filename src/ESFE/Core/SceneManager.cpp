/*   SceneManager.cpp
 * 
 * Version: dev 0.0.3
 * Copyright 2018 - Elite Fun
 * Date: 2018-02-24
 * 
 * SceneManager class definition
 * --> see SceneManager.hpp for 
 * more details
 */


/***** HEADERS *****/

#include <ESFE/Core/SceneManager.hpp>
#include <ESFE/Core/Scene.hpp> // avoid header loop


namespace esfe
{

SceneManager::~SceneManager( )
{
    while (!m_scenes.empty( )) popScene( );
}

void SceneManager::changeScene ( Scene* scene )
{
    if (!m_scenes.empty())
        popScene();

    pushScene(scene);
}

void SceneManager::pushScene( Scene* scene )
{
    m_scenes.push( scene );
}

void SceneManager::popScene ( )
{
    delete m_scenes.top( );
    m_scenes.pop( );
}

void SceneManager::update ( float dt )
{
    if (!m_scenes.empty( )) m_scenes.top( )->update( dt );
}

// void SceneManager::lateUpdate(float dt)
// {
// 	if (!m_scenes.empty()) m_scenes.top()->lateUpdate(dt);
// }
// void SceneManager::timedUpdate(float dt)
// {
// 	if (!m_scenes.empty()) m_scenes.top()->timedUpdate(dt);
// }

void SceneManager::draw ( float dt )
{
    if (!m_scenes.empty( )) m_scenes.top( )->draw( dt );
}

void SceneManager::onEvent ( sf::Event &e )
{
    if (!m_scenes.empty( )) m_scenes.top( )->onEvent( e );
}

} // namespace esfe
