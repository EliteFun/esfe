#ifndef ESFE_GUIMANAGER_HPP
#define ESFE_GUIMANAGER_HPP

#include <ESFE/Config.hpp>
#include <ESFE/GUI/Widget.hpp>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <vector>

namespace esfe
{

class GUILayer : public sf::Drawable,
                 public sf::Transformable
{
public:
    GUILayer();
    
    int addWidget(esfe::Widget* widget);
    
private:
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const; //update too?

private:
    std::vector<Widget*> m_widgets;
    
};

}

#endif

//THERE ARE TWO POSSIBLE WAYS OF DRAWING GUI!
// 1. use GUI manager and add all your widgets
// 2. draw each of your widgets 1 by 1
