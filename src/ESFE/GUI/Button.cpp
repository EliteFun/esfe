#include <ESFE/GUI/Button.hpp>

#include <iostream>

namespace esfe
{

ButtonStyle::ButtonStyle(
    sf::Color    bodyColor         , sf::Color   backgroundColor  , 
    sf::Texture* spritesheetTexture, sf::IntRect normalTextureRect,
    sf::IntRect  hoverTextureRect  , sf::IntRect clickTextureRect ,
    sf::Font*    font              , sf::Color   textHoverColor   ,
    sf::Color    textClickColor    , int         characterSize    )
{
    this->bodyColor          = bodyColor;
    this->backgroundColor    = backgroundColor; // useless
    this->spritesheetTexture = spritesheetTexture;
    this->normalTextureRect  = normalTextureRect;
    this->hoverTextureRect   = hoverTextureRect; // currently useless*
    this->clickTextureRect   = clickTextureRect; // currently useless*
    this->font               = font;
    this->textHoverColor     = textHoverColor; // currently useless*
    this->textClickColor     = textClickColor; // currently useless*
    this->characterSize      = characterSize;
    
    //* : trying to find a way to update these
}

ButtonStyle::ButtonStyle()
{
}
    
Button::Button(ButtonStyle& style)
{
    m_style = style;
    
    m_string = "";
    
    m_sprite.setTexture(*m_style.spritesheetTexture);
    m_sprite.setTextureRect(m_style.normalTextureRect);
    m_text.setFont(*m_style.font);
    m_text.setString(m_string);
    m_text.setCharacterSize(m_style.characterSize);
    m_text.setFillColor(m_style.bodyColor);
}

bool Button::isMouseOver(sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    return m_sprite.getGlobalBounds().contains(sf::Vector2f(mousePos));
}

void Button::setPosition(int x, int y)
{
    m_sprite.setPosition(x, y);
    updatePositions();
}

void Button::setPosition(sf::Vector2i pos)
{
    setPosition(pos.x, pos.y);
}

void Button::setString(std::string str)
{
    m_string = str;
    m_text.setString(m_string);
    std::cout << "Test: " << m_text.getGlobalBounds().width << std::endl;
    updatePositions();
}

std::string Button::getString()
{
    return m_string;
}

void Button::setSpriteScale(float factorX, float factorY)
{
    m_sprite.setScale(factorX, factorY);
    updatePositions();
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
    target.draw(m_text  , states);
}

void Button::updatePositions()
{ // re-center text, etc.
    // sf::FloatRect spriteRect = m_sprite.getGlobalBounds();
    float posX = 0; //spriteRect.left + (spriteRect.width - m_text.getGlobalBounds().width) / 2;
    float posY = 0; //spriteRect.top + (spriteRect.height - m_style.characterSize) / 2;
    
    std::cout << m_text.getGlobalBounds().width;
    
    m_text.setPosition(posX, posY);
}

}
