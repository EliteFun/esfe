/*   Widget.hpp
 * 
 * Copyright 2018 - Elite Fun
 * Version: alpha 0.1
 * Date: 2018-03-11
 * 
 * Widget class declaration. This is
 * a virtual class that is used to
 * declare new GUI Elements.
 */

#ifndef ESFE_WIDGET_HPP
#define ESFE_WIDGET_HPP

#include <ESFE/Config.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace esfe
{
    
class Widget : public sf::Drawable, public sf::Transformable
{
public:
    virtual bool isMouseOver(sf::RenderWindow& window) = 0;

private:
    virtual void draw(sf::RenderTarget & target,
                      sf::RenderStates states) const   = 0;
    
};

}

#endif // ESFE_WIDGET_HPP
