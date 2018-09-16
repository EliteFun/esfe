#include "ESFE/Graphics/DisplaySurf.hpp"

#include <iostream>

namespace esfe
{
    
DisplaySurf::DisplaySurf(sf::Vector2i size)
{
    m_clearColor = sf::Color::Black;
    m_size       = size;

    m_image.create(m_size.x, m_size.y, m_clearColor);

    m_texture.loadFromImage(m_image);
    m_sprite.setTexture(m_texture);
}

DisplaySurf::DisplaySurf(sf::Vector2i size, sf::Color clearColor)
{
    m_clearColor = clearColor;
    m_size       = size;

    m_image.create(m_size.x, m_size.y, m_clearColor);

    m_texture.loadFromImage(m_image);
    m_sprite.setTexture(m_texture);
}

DisplaySurf::~DisplaySurf()
{
}

void DisplaySurf::point(sf::Vector2i pos, sf::Color color)
{
    m_image.setPixel(pos.x, pos.y, color);
    m_texture.loadFromImage(m_image);
}

void DisplaySurf::line(sf::IntRect pos, sf::Color color)
{
    int x1, y1, x2, y2, dx, dy;

    if (pos.left < pos.width)
    {
        x1 = pos.left;
        x2 = pos.width;
    }
    else
    {
        x1 = pos.width;
        x2 = pos.left;
    }

    if (pos.top < pos.height)
    {
        y1 = pos.top;
        y2 = pos.height;
    }
    else
    {
        y1 = pos.height;
        y2 = pos.top;
    }

    dx = x2 - x1;
    dy = y2 - y1;

    for (int x = x1; x < x2; x++)
    {
        int y = y1 + dy * (x - x1) / dx;
        m_image.setPixel(x, y, color);
    }

    m_texture.loadFromImage(m_image);
}

void DisplaySurf::ellipse(sf::IntRect pos, sf::Color color)
{
}

void DisplaySurf::fillEllipse(sf::IntRect pos, sf::Color color)
{
}

void DisplaySurf::polygon(std::vector<sf::Vector2i> points, sf::Color color)
{
    for (int i = 0; i < points.size(); i++)
    {
        // must not get the next element if is 1 lesse than size
        if (i != points.size() -1 )
            line(sf::IntRect(
                     points[i].x,
                     points[i].y,
                     points[i + 1].x,
                     points[i + 1].y),
                 color);
        else
            line(sf::IntRect(
                     points[i].x,
                     points[i].y,
                     points[0].x,
                     points[0].y),
                 color);
    }
}

void DisplaySurf::fillPolygon(std::vector<sf::Vector2i> points, sf::Color color)
{

}

void DisplaySurf::blit(sf::Image &img, sf::Vector2i pos)
{
    for (int i = img.getSize().x-1; i != 0; i--)
        for (int j = img.getSize().y-1; j != 0; j--)
            m_image.setPixel( i + pos.x, j + pos.y, img.getPixel( i, j ) );

    m_texture.loadFromImage(m_image);
}

void DisplaySurf::clear()
{
    m_image.create(m_size.x, m_size.y, m_clearColor);
}

void DisplaySurf::clear(sf::Color clearColor)
{
    m_image.create(m_size.x, m_size.y, clearColor);
}

void DisplaySurf::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(m_sprite, states);
}

}  // namespace esfe
