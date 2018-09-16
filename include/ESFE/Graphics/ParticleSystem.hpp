/*   ParticleSystem.hpp
 * 
 * Copyright SFML team
 * Version: alpha 1
 * Date: 2018-09-16
 * 
 * ParticleSystem declaration. Basic
 * ParticleSystem using vertex arrays.
 * 
 * Taken from the official SFML website
 */

// TODO: have more options like size, scale, texture, etc.

#ifndef ESFE_PARTICLESYSTEM_HPP
#define ESFE_PARTICLESYSTEM_HPP

#include <ESFE/Util/Random.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

#include <vector>
#include <cmath>

namespace esfe
{

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:
    
    /**
     * @brief construct a new ParticleSystem object
     * 
     * @param count number of particles
     */
    ParticleSystem(unsigned int count);
    
    /**
     * @brief set the emitter position
     * 
     * @param position new position for the emitor
     */
    void setEmitter(sf::Vector2f position);

    /**
     * @brief update the ParticleSystem
     * 
     * @param dt delta time
     */
    void update(float dt);
    
private:

    /**
     * @brief default Drawable draw function
     * 
     * @param target render target
     * @param states render states
     */
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
    
    /**
     * @brief single particle struct
     * 
     */
    struct Particle
    {
        sf::Vector2f velocity; ///< velocity of the particle
        float lifetime; ///< lifetime of the particle
    };
    
    /**
     * @brief reuse the particle by moving it to the emitter
     * 
     * @param index index of the particle
     */
    void resetParticle(std::size_t index);
    
    std::vector<Particle> m_particles; ///< array of particles
    sf::VertexArray m_vertices; ///< verticies of the particles
    float m_lifetime; ///< lifetime of all the particles
    sf::Vector2f m_emitter; ///< position of the emitter
    
    Random randomGen; ///< random number generator
};

} // namespace esfe

#endif // ESFE_PARTICLESYSTEM_HPP
