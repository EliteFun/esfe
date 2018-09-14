//source : https://www.sfml-dev.org/tutorials/2.4/graphics-vertex-array.php

#pragma once

#include <ESFE/Util/Random.hpp>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

#include <vector>
#include <cmath>

namespace esfe
{

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:
    
    ParticleSystem(unsigned int count);
    
    void setEmitter(sf::Vector2f position);
    void update(sf::Time elapsed);
    
private:
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
    
    struct Particle
    {
        sf::Vector2f velocity;
        sf::Time lifetime;
    };
    
    void resetParticle(std::size_t index);
    
    std::vector<Particle> m_particles;
    sf::VertexArray m_vertices;
    sf::Time m_lifetime;
    sf::Vector2f m_emitter;
    
    Random randomGen;
};

}
