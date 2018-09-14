/*
    Ellipse.hpp

Source: https://www.sfml-dev.org/tutorials/2.4/graphics-shape.php

This is just a implementation for the default shapes if you want.

-> Credits to the SFML team.

*/

#pragma once

#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>

#include <math.h>

#define PI 3.141592654f

namespace esfe
{
    class EllipseShape : public sf::Shape
    {
    public:
        /** Default constructor */
        explicit EllipseShape(const sf::Vector2f& radius);

        /** Set m_radius
         * \param radius New value to set
         */
        void setRadius(const sf::Vector2f& radius);

        /** Access m_radius
         * \return The current value of m_radius
         */
        const sf::Vector2f& getRadius() const;

        /** Access number of points
         * \return The current value of HARD_CODE:30
         * Currently returns a hard codded value of 30
         */
        virtual std::size_t getPointCount() const;

        /** Access a point at specific index
         * \param index Index of the point
         * \return The value for the given point at index
         */
        virtual sf::Vector2f getPoint(unsigned int index) const;

    private:
        sf::Vector2f m_radius; //!< Member variable "m_radius"
    };
}

