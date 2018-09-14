// Dev, needs work

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

namespace esfe
{
    class RigidBody : public sf::Sprite
    {
    public:
        /** Default constructor 
         *\param garvityMultiplyer the multiplyer to the earth's default garvity
         */
        RigidBody(float gravityMultiplyer = 1.0f);

        /** Default destructor */
        virtual ~RigidBody();

        void update();
        // void addForce(sf::Vector2f force);

        bool isColliding(RigidBody body);

        sf::FloatRect bounds;

    private:
    };
}
