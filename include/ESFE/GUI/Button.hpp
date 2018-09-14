/*
*   Button.hpp
*/

// Should there be a GUILayer class? and you would need to use pack() to draw a Widget to it?

#ifndef ESFE_BUTTON_HPP
#define ESFE_BUTTON_HPP


#include <ESFE/Config.hpp>
#include <ESFE/GUI/GUIStyle.hpp>
#include <ESFE/GUI/Widget.hpp>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <string>

// struct GuiButtonStyle : GuiStyle{} ?

namespace esfe
{

struct ESFE_GUI_API ButtonStyle : GuiStyle // could remove GuiStyle inheritance
{
    ButtonStyle(
        sf::Color    bodyColor         , sf::Color   backgroundColor  , 
        sf::Texture* spritesheetTexture, sf::IntRect normalTextureRect,
        sf::IntRect  hoverTextureRect  , sf::IntRect clickTextureRect ,
        sf::Font*    font              , sf::Color   textHoverColor   ,
        sf::Color    textClickColor    , int characterSize
    );
    
    ButtonStyle();
    
    // background info
    sf::Texture* spritesheetTexture;
    sf::IntRect  normalTextureRect;
    sf::IntRect  hoverTextureRect;
    sf::IntRect  clickTextureRect;
    
    // text info
    sf::Font*    font;
    sf::Color    textHoverColor;
    sf::Color    textClickColor;
    int          characterSize;
};

class ESFE_GUI_API Button : public Widget
{
public:
    Button(ButtonStyle& style);
    
    virtual bool isMouseOver(sf::RenderWindow& window);
    
    void         setPosition(int x, int y);
    void         setPosition(sf::Vector2i pos);
    
    void         setString(std::string str);
    std::string  getString();
    
    void         setSpriteScale(float factorX, float factorY);
    
private:
    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;
    
    void         updatePositions();
    
private:
    ButtonStyle      m_style;
    
    sf::Sprite       m_sprite;
    sf::Text         m_text;
    
    std::string      m_string;
};

}

#endif
