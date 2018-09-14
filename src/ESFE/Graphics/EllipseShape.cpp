#include "ESFE\Graphics\EllipseShape.hpp"


namespace esfe
{
    EllipseShape::EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0, 0)) :
    m_radius(radius)
    {
        update();
    }

    void EllipseShape::setRadius(const sf::Vector2f& radius)
    {
        m_radius = radius;
        update();
    }

    const sf::Vector2f& EllipseShape::getRadius() const
    {
        return m_radius;
    }

    std::size_t EllipseShape::getPointCount() const
    {
        return 30;
    }

    sf::Vector2f EllipseShape::getPoint(unsigned int index) const
    {
        float angle = index * 2 * PI / getPointCount() - PI / 2;
        float x = std::cos(angle) * m_radius.x;
        float y = std::sin(angle) * m_radius.y;

        return sf::Vector2f(m_radius.x + x, m_radius.y + y);
    }

}
