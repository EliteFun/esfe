/*
    ResourceManager.hpp

Slightly modified from:
https://www.youtube.com/watch?v=LY2pCfMqnik&list=PLRtjMdoYXLf7DB3--POF9lYzaZu0poT5V&index=4

Simple Resource Manager so that you don't have to load your fonts/textures
to many times in memory

-> Credits to Sonar Systems


HOWTO:
// create ResourceManager object with default texture and font path
esfe::ResourceMangager resources("default/texture", "default/font");
// load the image and store it at key value "name"
resources.loadFromFile("name", "path/to/file");
// get the image a key value of "name"
// (same as the one given when loading image)
sf::Sprite sprite;
sprite.setTexture(resouces.getTexture("name");

*/

#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <map>
#include <string>


namespace esfe
{
    class ResourceManager
    {
    public:

        /** Default constructor
         * \param defaultTexturePath Path to the default texture
         * \param defaultFontPath Path to the default font
         */
        explicit ResourceManager ( std::string defaultTexturePath, std::string defaultFontPath );

        /** Add a texture
         * \param name Name of the texture
         * \param filename Path to the texture image
         */
        void loadTexture ( std::string name, std::string filename );

        /** Access a texture
         * \return The the value of the texture assigned with the given name
         */
        sf::Texture &getTexture ( std::string name );
		const sf::Texture &getTexture(std::string name) const;

        /** Add a font
         * \param name Name of the font
         * \param filename Path to the font file
         */
        void loadFont ( std::string name, std::string filename );

        /** Access a font
         * \return The the value of the font assigned with the given name
         */
        sf::Font &getFont ( std::string name );
        const sf::Font &getFont ( std::string name ) const;

    private:
        //!< Member variable "m_textures": map of all the image texture files
        std::map<std::string, sf::Texture> m_textures;
        //!< Member variable "m_fonts": map of all the font files
        std::map<std::string, sf::Font> m_fonts;

        //!< Member variable "m_defaultTexture": path to the default texture
        std::string m_defaultTexture;
        //!< Member variable "m_defaultFont": path to the default font
        std::string m_defaultFont;

        //!< Member variable "m_t_texture": temporary texture to load the images
        sf::Texture m_t_texture;
        //!< Member variable "m_t_font": temporary font to load the font files
        sf::Font m_t_font;
    };
}
