#include "ESFE/Graphics/DisplaySurf.hpp"

#include <iostream>

namespace esfe
{
    
DisplaySurf::DisplaySurf ( ):
sf::Image::Image()
{ }

DisplaySurf::~DisplaySurf ( )
{ }

void DisplaySurf::rect(sf::IntRect corners, sf::Color color)
{
    for (int i = corners.width; i > corners.left-1; i--)
        for (int j = corners.height; j > corners.top-1; j--)
            setPixel(i, j, color);
}

void DisplaySurf::blit(sf::Image img, sf::Vector2i pos)
{
    for (int i = img.getSize().x-1; i != 0; i--)
        for (int j = img.getSize().y-1; j != 0; j--)
            setPixel( i + pos.x, j + pos.y, img.getPixel( i, j ) );
}
    
}  // namespace esfe
