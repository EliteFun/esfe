#ifndef ESFE_RIGIDBODY_HPP
#define ESFE_RIGIDBODY_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

namespace esfe
{

class RigidBody : public sf::Sprite
{
public:
    /**
     * @brief Construct a new Rigid Body object
     * 
     * @param gravityMultiplyer multiplyer to the eath's gravity
     */
    RigidBody(float gravityMultiplyer = 1.0f);

    /**
     * @brief Destroy the Rigid Body object
     * 
     */
    virtual ~RigidBody();

    /**
     * @brief update the RigidBody
     * 
     */
    virtual void update() = 0;

    /**
     * @brief add a force to the RigidBody
     * 
     * @param force force to be added
     */
    void addForce(sf::Vector2f force);

    /**
     * @brief detects a collision between two RigidBodies
     * 
     * @param body other body to compare
     * @return true there is a collision
     * @return false there isn't a collision
     */
    bool isColliding(RigidBody &body);

private:
    float gravity; ///< current gravity of the object //? really neaded?

    sf::Vector2f velocity; ///< velocity of the RigidBody
};

} // namespace esfe

#endif // ESFE_RIGIDBODY_HPP
