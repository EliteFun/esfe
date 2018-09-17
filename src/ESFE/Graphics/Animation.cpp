#include <ESFE/Graphics/Animation.hpp>

namespace esfe
{

Animation::Animation(int frames, float duration, sf::Vector2i frameSize)
{
    m_duration = duration;
    m_frameSize = frameSize;
    m_frames = frames;
    
    m_currentFrame = 1;
    m_frameTime = sf::Time::Zero;
    
    setTexture(m_texture);
    
    setTextureRect(sf::IntRect(
        0 + m_frameSize.x * (m_currentFrame-1),
        0,
        m_frameSize.x,
        m_frameSize.y
    ));
}

void Animation::update(sf::Time dt)
{
    m_frameTime += dt; 
    if (m_frameTime.asMilliseconds() >= m_duration)
    {
        if (m_currentFrame < m_frames)
            m_currentFrame++;
        else
            m_currentFrame = 1;
        
        setTextureRect(sf::IntRect(
            0 + m_frameSize.x * (m_currentFrame-1),
            0,
            m_frameSize.x,
            m_frameSize.y
        ));
        
        m_frameTime = sf::Time::Zero;
    }
}

void Animation::loadFromFile(std::string imgPath)
{
    m_texture.loadFromFile(imgPath);
}
    
} // namespace esfe
