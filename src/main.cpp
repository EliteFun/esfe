//In the future, there might be other required libs such as:
// - tinyXML
// - glew (for 3D)
// - json parser?
// - ffmpeg (for videos)

#include <ESFE/Core/Scene.hpp>
#include <ESFE/Core/Game.hpp>
#include <ESFE/Graphics/ParticleSystem.hpp>
#include <ESFE/Graphics/Animation.hpp>
#include <ESFE/GUI/Button.hpp>

#include <SFML/Graphics.hpp>

#include <iostream>

class MenuScene;

class GameScene : public esfe::Scene
{
public:
    
    GameScene(esfe::Game* game)
    {
        m_game = game;
        
        m_font.loadFromFile("assets/font.ttf");
        m_text.setFont(m_font);
        m_text.setString("test");
        
    }
    
    ~GameScene()
    {
    }
    
    virtual void onEvent(sf::Event &e)
    {
        if (e.type == sf::Event::MouseButtonPressed)
            m_game->sceneManager.popScene();
        else if (e.type == sf::Event::KeyReleased)
            std::cout << "Top: "    << m_text.getGlobalBounds().top    << "\n"
                      << "Left: "   << m_text.getGlobalBounds().left   << "\n"
                      << "Width: "  << m_text.getGlobalBounds().width  << "\n"
                      << "Height: " << m_text.getGlobalBounds().height << std::endl;
    }
    
    virtual void update(float dt)
    {
    }
    
    virtual void draw(float dt)
    {
        m_game->window.draw(m_text);
    }

    virtual void lateUpdate(float dt)
    {
    }

    virtual void timedUpdate(float dt)
    {
    }

  private:
    sf::Font m_font;
    sf::Text m_text;
};


class MenuScene : public esfe::Scene
{
public:
    
    MenuScene(esfe::Game* game)
    : particles(1000)
    , m_buttonStyle(
        sf::Color(0, 255, 0)       , sf::Color(0, 0, 0)         ,
        &m_buttonTexture           , sf::IntRect(0, 0, 500, 500),
        sf::IntRect(0, 0, 500, 500), sf::IntRect(0, 0, 500, 500),
        &m_font                    , sf::Color(0, 255, 0)       ,
        sf::Color(255, 0, 0)       , 10
      )
    , m_button(m_buttonStyle)
    {
        m_game = game;
        m_button.setString("PRESS ME");
        m_button.setPosition(100, 100);
        m_button.setSpriteScale(0.5f, 0.5f);
        m_buttonTexture.loadFromFile("assets/button.png");
        m_font.loadFromFile("assets/font.ttf");
    }
    
    ~MenuScene()
    {
    }
    
    virtual void onEvent(sf::Event &e)
    {
        if (e.type == sf::Event::Closed)
            m_game->window.close();
        else if (e.type == sf::Event::MouseButtonPressed)
        {
            if (m_button.isMouseOver(m_game->window))
                m_game->sceneManager.pushScene(new GameScene(m_game));
            else
                particles.setEmitter(
                    m_game->window.mapPixelToCoords(
                        sf::Mouse::getPosition(m_game->window)
                    ));
        }
    }
    
    virtual void update(float dt)
    {
        sf::Time elapsed = clock.restart();
        particles.update(elapsed);
    }
    
    virtual void draw(float dt)
    {
        m_game->window.draw(particles);
        m_game->window.draw(m_button);
    }

    virtual void lateUpdate(float dt)
    {

    }

    virtual void timedUpdate(float dt)
    {

    }
    
private:
    
    esfe::ParticleSystem particles;
    esfe::ButtonStyle    m_buttonStyle;
    esfe::Button         m_button;
    
    sf::Texture m_buttonTexture;
    sf::Font    m_font;
    sf::Clock clock;
};


int main()
{
    esfe::Game game(sf::VideoMode(800, 600), "ESFE");
    game.sceneManager.pushScene(new MenuScene(&game));

    game.gameLoop();
    return 0;
}

/*#include "config.hpp"

// should there be utils for file exploring, progress bar in windows task bar icon, windows system tray, etc.?

// create GUI call with methods like addWidget(esfe::Widget &widget) and create virtual widget class with some
// children like Text, Button, etc. Also create esfe::TextStyle, esfe::ButtonStyle, etc. in GUIStyle.hpp
// (could be structs)

int main(int argc, char* argv[], char* envp[])
{
    esfe::Random random;
    esfe::Logger logger("Main", esfe::LoggerMode::CONSOLE);
    
    esfe::DisplaySurf draw_surface;
    draw_surface.create(WIDTH, HEIGHT, sf::Color::White);
    
    //sf::Image myImage;
    //myImage.loadFromFile("assets/image.png");
    
    //draw_surface.blit(myImage, sf::Vector2i(0, 0));
    
    sf::Texture draw_texture;
    draw_texture.loadFromImage(draw_surface);
    
    sf::Sprite draw_sprite;
    draw_sprite.setTexture(draw_texture);
    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "ESFE");

    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }
        
        window.clear();
        window.draw(draw_sprite);
        window.display();
    }

    return 0;
}*/

// TODO: IMPROVE DOC!!!


/* FOR TESTS
#include "config.hpp"


int main(int argc, char* argv[], char* envp[])
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "ESFE");
    esfe::Logger log("MAIN", esfe::LoggerMode::MULTI_FILES);

    log.error("test", 12);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return EXIT_SUCCESS;
}*/

/* Flappy Bird - States' main.cpp:
#include "config.hpp"

// CLASSES //
class GameState : public State
{
public:
    GameState ( sf::RenderWindow* win ):
    State( win )
    { };

    void init()
    {
        rect.setFillColor(sf::Color::Red);
        rect.setPosition(100, 100);
        rect.setSize(sf::Vector2f(100, 100));
    }

    // TODO: add in-game menu when pressing ESC

    void draw()
    {
        m_window->draw(rect);
    }

    void onEvent( sf::Event* e )
    {
        switch (e->type)
        {
        case sf::Event::KeyReleased:
            // try changing state in a clean way
            break;
        default:
            break;
        }
    }

private:
    sf::RectangleShape rect;
};

class MenuState : public State
{
public:
    MenuState(sf::RenderWindow *win) :
    State(win)
    { }

    ~MenuState ( )
    {

    }

    void init ( )
    {
        //std::cout << "test";
    }

    void update ( )
    {

    }

    void draw ( )
    {
        std::cout << "menu state";
    }

    void clean()
    {
        std::cout << "clearing";
    }
};

int main(int argc, char* argv[], char* envp[])
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Flappy Bird",
                            sf::Style::Close | sf::Style::Titlebar);
                            //sf::Style::None);
    window.setFramerateLimit(60);

    MenuState menu_state(&window);
    GameState game_state(&window);

    state_manager.pushState(&menu_state);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased)
                state_manager.changeState(&game_state);

            state_manager.onEvent(&event);
        }

        state_manager.update();

        window.clear(sf::Color::White);
        state_manager.draw();
        window.display();
    }

    return 0;
}
*/


