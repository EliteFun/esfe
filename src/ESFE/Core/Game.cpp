#include <ESFE/Core/Scene.hpp> // avoid header loop
#include <ESFE/Core/Game.hpp>

namespace esfe
{

Game::Game(sf::VideoMode mode, const sf::String &title, sf::Uint32 style,
           int framerate)
: window(mode, title, style)
{
    window.setKeyRepeatEnabled(false);
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
        timeSinceLastUpdate += elapsed;
        
        while (timeSinceLastUpdate.asMilliseconds() > 1000 / m_framerate)
        {
            timeSinceLastUpdate -= sf::milliseconds(1000 / m_framerate);

            sceneManager.update(sf::milliseconds(1000/m_framerate));
        }
        
        window.clear(m_clearColor);
        sceneManager.draw(elapsed);
        window.display();
    }
}

}
