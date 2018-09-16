/*   EllipseShape.hpp
 * 
 * Copyright SFML team
 * Version: alpha 1
 * Date: 2018-09-15
 * 
 * EllipseShape declaration. Adds a new
 * shape to draw with the default SFML-way
 * 
 * Taken from the official SFML website
 */

#ifndef ESFE_ELLIPSESHAPE_HPP
#define ESFE_ELLIPSESHAPE_HPP

#include <ESFE/GameMath.hpp>

#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>

#include <math.h>

namespace esfe
{

class EllipseShape : public sf::Shape
{
public:
    /**
     * @brief construct a new EllipseShape object
     * 
     * @param radius the two radiuses of the ellipse
     */
    explicit EllipseShape(const sf::Vector2f& radius);

    /**
     * @brief set the radiuses of the ellipse
     * 
     * @param radius new radiuses
     */
    void setRadius(const sf::Vector2f& radius);

    /**
     * @brief get the raduises of the ellipse
     * 
     * @return const sf::Vector2f& radiuses
     */
    const sf::Vector2f& getRadius() const;

    /**
     * @brief get the number of points of the ellipse
     * 
     * @return std::size_t number of points
     */
    virtual std::size_t getPointCount() const;

    /**
     * @brief get the points at the specified index
     * 
     * @param index index of the point
     * @return sf::Vector2f position of the point
     */
    virtual sf::Vector2f getPoint(unsigned int index) const;

private:
    sf::Vector2f m_radius; ///< two radiuses of the ellipse
};

} // namespace esfe

#endif // ESFE_ELLIPSESHAPE_HPP
