/*   DisplaySurf.hpp
 * 
 * Copyright 2018 - Elite Fun
 * Version: alpha 1
 * Date: 2018-09-15
 * 
 * DisplaySurf class declaration. Used
 * to create shapes procedurally.
 */

#ifndef ESFE_DISPLAYSURF_HPP
#define ESFE_DISPLAYSURF_HPP

#include <vector>
#include <SFML/Graphics.hpp>

namespace esfe
{

class DisplaySurf : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{
  public:

    /**
     * @brief construct a new DisplaySurf object
     * 
     * @param size size of the DisplaySurf
     */
    DisplaySurf(sf::Vector2i size);

    /**
     * @brief construct a new DisplaySurf object
     * 
     * @param size size of the DisplaySurf
     * @param clearColor clearColor for the DisplaySurf
     */
    DisplaySurf(sf::Vector2i size, sf::Color clearColor);

    /**
     * @brief destroy the DisplaySurf object
     * 
     */
    ~DisplaySurf();


    /**
     * @brief draw a point on the DisplaySurf
     * 
     * @param pos position of the point
     * @param color color of the point
     */
    void point(sf::Vector2i pos, sf::Color color);

    /**
     * @brief draw a line on the DisplaySurf
     * 
     * @param pos position and size of the line
     * @param color color of the line
     */
    void line(sf::IntRect pos, sf::Color color);

    /**
     * @brief draw an ellipse on the DisplaySurf
     * 
     * @param pos position and size of the ellipse
     * @param color color of the ellipse
     */
    void ellipse(sf::IntRect pos, sf::Color color);

    /**
     * @brief draw a filled ellipse on the DisplaySurf
     * 
     * @param pos position and size of the ellipse
     * @param color color of the ellipse
     */
    void fillEllipse(sf::IntRect pos, sf::Color color);

    /**
     * @brief draw a polygon on the DisplaySurf
     * 
     * @param points position of each point of the polygon
     * @param color color of the polygon
     */
    void polygon(std::vector<sf::Vector2i> points, sf::Color color);

    /**
     * @brief draw a filled polygon on the DisplaySurf
     * 
     * @param points position of each point of the polygon
     * @param color color of the polygon
     */
    void fillPolygon(std::vector<sf::Vector2i> points, sf::Color color);

    /**
     * @brief draw an image on the DisplaySurf
     * 
     * @param img reference to the image to be drawn
     * @param pos position of the image
     */
    void blit(sf::Image &img, sf::Vector2i pos);

    /**
     * @brief clear the DisplaySurf
     * 
     */
    void clear();

    /**
     * @brief clear the DisplaySurf with the clearColor
     * 
     * @param clearColor clear color for the image
     */
    void clear(sf::Color clearColor);

    /**
     * @brief get the image object
     * 
     * @return sf::Image& image object
     */
    sf::Image &getImage();

  private:

    /**
     * @brief default Drawable draw function
     * 
     * @param target render target
     * @param states render states
     */
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    sf::Image    m_image; ///< image member
    sf::Texture  m_texture; ///< texture member
    sf::Sprite   m_sprite; ///< sprite member

    sf::Color    m_clearColor; ///< clear color for the image
    sf::Vector2i m_size; ///< size of the image
};

} // namespace esfe

#endif // ESFE_DISPLAYSURF_HPP
