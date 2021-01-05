/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    stage.hpp
 * @brief   Represents the stage that contains all game components.
 */

#ifndef KABUKI_STAGE_H_
#define KABUKI_STAGE_H_

#include "engine_component.hpp"
#include "scene.hpp"
#include "input/input_manager.hpp"
#include <map>

namespace kabuki
{
    class stage : public engine_component
    {
    public:
        stage(const input::input_manager *input);

        /**
         * Create an empty scene with the specified scene id.
         * @param scene_id      ID of scene being created.
         * @return              A reference to the newly created scene.
         */
        scene *create_scene(std::string scene_id);

        /**
         * Change the current scene being shown to one with the specified id.
         * 
         * @param scene_id      ID of scene to switch to.
         * @return              True if the scene was found and switched to, 
         *                      false otherwise.
         */
        bool change_scene(std::string scene_id);

        /**
         * Move the events on stage forward by one tick.
         */
        void tick();

        /**
         * Gets the current scene being shown on stage.
         */
        inline const scene *current_scene() const { return this->scene_by_id(_current_scene_id); }

        /**
         * Gets the scene with the specified ID
         */
        inline const scene *scene_by_id(std::string scene_id) const 
        { 
            auto it = _scenes.find(scene_id);
            if(it != _scenes.end())
            {
                return it->second.get();
            }
            return nullptr;
        }
    private:
        std::string _current_scene_id;
        std::map<std::string, std::unique_ptr<scene>> _scenes;
    };
}

#endif