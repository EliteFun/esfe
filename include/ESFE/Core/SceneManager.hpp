/*   SceneManager.hpp
 * 
 * Version: alpha 0.1
 * Copyright 2018 - Elite Fun
 * Date: 2018-02-24
 * 
 * SceneManager class definition. This class
 * will store all the scenes, and call update,
 * draw, etc. to the top scene when necessary
 */


#ifndef ESFE_SCENEMANAGER_HPP
#define ESFE_SCENEMANAGER_HPP


/*** HEADERS ***/

#include <SFML/Window/Event.hpp>

#include <stack>



namespace esfe
{

class Scene; // Avoid header loop
    
class SceneManager
{
    public:
        
        /** \brief Desctructor
         * 
         * Pops all the remaining scenes
         */
        ~SceneManager ();

        /** \brief change the current scene
         * 
         * \param scene new scene
         * 
         * Replace the current scene (delete it)
         * with the new given scene
         */
        void changeScene (esfe::Scene* scene);
        /** \brief push a new scene
         * 
         * \param scene new scene
         * 
         * Push the current scene to the stack. 
         * This will not delete the previous one
         */
        void pushScene (esfe::Scene* scene);
        /** \brief pop the current scene
         * 
         * Pop the top scene, if there is one
         */
        void popScene ();
        /** \brief get the current scene
         * 
         * \return current top scene
         * 
         * Returns the current scene at the
         * top of the stack
         */
        esfe::Scene* getScene ();

        /** \brief update the top scene
         * 
         * \param dt time since last call
         * 
         * Update the scene that is currently
         * at the top of the stack and pass it
         * the elapsed time (dt)
         */
        void update (float dt);
        /** \brief update the top scene
         * 
         * \param dt time since last call
         * 
         * Updates the top scene at a specific interval,
         * wich is the framerate. Pass it the elapsed
         * time (dt)
         */
        void timedUpdate(float dt);
        /** \brief update the top scene
         * 
         * \param dt time since last call
         * 
         * Last update called to the top scene. After
         * every other update has been called. Happens
         * before the draw step
         */
        void lateUpdate(float dt);
        /** \brief draw the top scene
         * 
         * \param dt time since last call
         * 
         * Draw the scene that is currently
         * at the top of the stack and pass it
         * the elapsed time (dt)
         */
        void draw (float dt);
        /** \brief send event signal to the top scene
         * 
         * \param e current event
         * 
         * Tell the top scene that there was an
         * event and give it a reference to the
         * event that happened.
         */
        void onEvent (sf::Event &e);

    private:

        std::stack<esfe::Scene*> m_scenes; ///< stack of all the scenes
};

} // namespace esfe

#endif // ESFE_SCENEMANAGER_HPP
