#include "ESFE\Util\ResourceManager.hpp"

namespace esfe
{
    ResourceManager::ResourceManager (
        std::string defaultTexturePath = "assets/no_texture.png",
        std::string defaultFontPath = "assets/no_font.ttf" )
    {
        m_defaultTexture = defaultTexturePath;
        m_defaultFont = defaultFontPath;
    }

    void ResourceManager::loadTexture ( std::string name, std::string filename )
    {
        if ( !m_t_texture.loadFromFile( filename ) )
        {
            // load no texture file if texture is not found
            m_t_texture.loadFromFile( m_defaultTexture );
        }

        m_textures[name] = m_t_texture;
    }

    sf::Texture &ResourceManager::getTexture ( std::string name )
    {
        return m_textures.at( name );
    }

	const sf::Texture &ResourceManager::getTexture(std::string name) const
	{
		return m_textures.at(name);
	}

    void ResourceManager::loadFont ( std::string name, std::string filename )
    {
        sf::Font t_font;

        if ( t_font.loadFromFile( filename ) )
        {
            m_fonts[name] = t_font;
        }
    }

    sf::Font &ResourceManager::getFont ( std::string name )
    {
        return m_fonts.at( name );
    }

    const sf::Font &ResourceManager::getFont ( std::string name ) const
    {
        return m_fonts.at( name );
    }
}
