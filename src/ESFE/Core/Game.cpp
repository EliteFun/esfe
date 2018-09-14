#include <ESFE/Core/Scene.hpp> // avoid header loop
#include <ESFE/Core/Game.hpp>

namespace esfe
{

Game::Game(sf::VideoMode mode, const sf::String &title, sf::Uint32 style,
           int framerate)
: window(mode, title, style)
{
    window.setFramerateLimit(framerate); // TODO Use sf::Clock instead
    window.setKeyRepeatEnabled(true);
    window.setVerticalSyncEnabled(true);
    
    m_clearColor = sf::Color::Black;
    m_framerate = framerate;
}

void Game::gameLoop()
{
    sf::Clock clock;
    
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            sceneManager.onEvent(event);
        }
        
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asMilliseconds();
        timeSinceLastUpdate += elapsed;
        
        sceneManager.update(dt);
        
        while (timeSinceLastUpdate.asMilliseconds() > 1000 / m_framerate)
        {
            timeSinceLastUpdate -= sf::milliseconds(1000 / m_framerate);

            sceneManager.timedUpdate(dt);
            sceneManager.lateUpdate(dt);
        }
        
        window.clear(m_clearColor);
        sceneManager.draw(dt);
        window.display();
    }
}

}
