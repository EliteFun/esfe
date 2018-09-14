/*   DisplaySurf.hpp
 * 
 * Copyright 2018 - Elite Fun
 * Date: 2018-02-20
 * 
 * Graphics element like an image that
 * has extra methods, such as rect(),
 * ellipse(), etc.
 */


#pragma once


/******* INCLUDES *******/

// SFML //
#include <SFML/Graphics/Image.hpp>

namespace esfe
{
class DisplaySurf : public sf::Image // TODO: Make drawable
{
public:
    DisplaySurf();
    ~DisplaySurf();
    
    // Create a rect in the display surf
    void rect(sf::IntRect corners, sf::Color color);
    
    // Blit an image in the display surf
    void blit(sf::Image img, sf::Vector2i pos);
};
}
