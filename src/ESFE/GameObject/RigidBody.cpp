#include "ESFE/GameObject/RigidBody.hpp"

namespace esfe
{
    RigidBody::RigidBody()
    {

    }

    RigidBody::~RigidBody()
    {

    }

    void RigidBody::update()
    {
        bounds = getGlobalBounds();
    }

    bool RigidBody::isColliding(RigidBody object)
    {
        return bounds.intersects(object.bounds);
    }
}
