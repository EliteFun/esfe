/*  -Animator.hpp-
 */

//TODO: implement animations from json files
// NOTE: this is a spritesheet animation class for now

#pragma once

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
    Animation (int frames, float duration, sf::Vector2i frameSize);
    // TODO: int startFrame, endFrame instead of frames
    void update (float dt);
    void loadFromFile (std::string imgPath); // TODO: add config file loading
    // void play();
    // void pause();
    // bool isPlaying();
    // Config File will have a imagePath = path
    //void saveToFile (std::string filePath);
    
private:
    float m_duration;
    float m_frameTime;
    
    int m_currentFrame;
    int m_frames;
    // int m_currentAnim;
    // bool m_isPlaying;

    sf::Texture m_texture;
    sf::Vector2i m_frameSize;
};

}
