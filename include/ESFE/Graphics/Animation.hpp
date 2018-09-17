/*   Animation.hpp
 * 
 * Copyright 2018 - Elite Fun
 * Version: alpha 1
 * Date: 2018-09-15
 * 
 * Spritesheet animation class. Animates
 * Sprites with the given frames, duration
 * and frameSize.
 */

// TODO: implement animations from json files

#ifndef ESFE_ANIMATION_HPP
#define ESFE_ANIMATION_HPP

#include <ESFE/Util/ConfigManager.hpp>

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>
#include <iostream>

namespace esfe
{

class Animation : public sf::Sprite
{
  public:
    /**
     * @brief Construct a new Animation object
     * 
     * @param frames number of frames for the animation
     * @param duration duration of each frame
     * @param frameSize size of a frame
     */
    Animation(int frames, float duration, sf::Vector2i frameSize);

    /**
     * @brief update the animation
     * 
     * @param dt delta time
     */
    void update(sf::Time dt);

    /**
     * @brief load the spritesheet from file
     * 
     * @param imgPath path to the file
     */
    void loadFromFile(std::string imgPath);

    /**
     * @brief play the animation
     * 
     */
    void play();

    /**
     * @brief pause the animation
     * 
     */
    void pause();

    /**
     * @brief tells if the animation is playing
     * 
     * @return true the animation is playing
     * @return false the animation is in pause
     */
    bool isPlaying();

  private:
    float m_duration; ///< duration of the frame
    sf::Time m_frameTime; ///< current time between frames

    int m_currentFrame; ///< index to the current frame
    int m_frames;       ///< number of frames for the animation
    bool m_isPlaying;   ///< if the animation is playing

    sf::Texture m_texture;    ///< the texture of the spritesheet
    sf::Vector2i m_frameSize; ///< size of a frame
};

} // namespace esfe

#endif // ESFE_ANIMATION_HPP
