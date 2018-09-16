/*   SceneManager.hpp
 * 
 * Copyright 2018 - Elite Fun
 * Version: alpha 1.0
 * Date: 2018-02-24
 * 
 * SceneManager class definition. This class
 * will store all the scenes, and call update,
 * draw, etc. to the top scene when necessary
 */


#ifndef ESFE_SCENEMANAGER_HPP
#define ESFE_SCENEMANAGER_HPP


#include <SFML/Window/Event.hpp>

#include <stack>



namespace esfe
{

class Scene; // fwd decl
    
class SceneManager
{
    public:
        
        /**
         * @brief Destroy the Scene Manager object
         * 
         */
        ~SceneManager ();

        /**
         * @brief change the current scene
         * 
         * @param scene new scene
         */
        void changeScene (esfe::Scene* scene);

        /**
         * @brief add a new scene to the stack
         * 
         * @param scene new scene
         */
        void pushScene (esfe::Scene* scene);

        /**
         * @brief remove the top scene of the stack
         * 
         */
        void popScene ();

        /**
         * @brief Get the Scene object
         * 
         * @return esfe::Scene* 
         */
        esfe::Scene* getScene ();

        /**
         * @brief update the top scene
         * 
         * @param dt delta time
         */
        void update (float dt);

        /**
         * @brief draw the top scene
         * 
         * @param dt delta time
         */
        void draw (float dt);

        /**
         * @brief send event to the current scene
         * 
         * @param e current event
         */
        void onEvent (sf::Event &e);

    private:

        std::stack<esfe::Scene*> m_scenes; ///< stack of all the scenes
};

} // namespace esfe

#endif // ESFE_SCENEMANAGER_HPP
