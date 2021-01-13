/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    entity.hpp
 * @brief   An entity that can be used on stage. This can either be a visual 
 *          element or a logical one (eg, for an audio emitter).
 */

#ifndef KABUKI_ENTITY_H_
#define KABUKI_ENTITY_H_

#include "utility/log.hpp"
#include "engine_component.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

namespace kabuki
{
    class entity : public engine_component
    {
    public:
        entity(std::string tag);

        inline glm::vec3 position() const { return _position; }
        inline void set_position(glm::vec3 position)
        {
            _position = position;
            on_set_position();
        }
        inline void set_position(float x, float y, float z) 
        {
            set_position(glm::vec3(x, y, z));
        }

        inline glm::quat rotation() const { return _rotation; }
        inline void set_rotation(glm::quat rotation)
        {
            _rotation = rotation;
            on_set_rotation();
        }
        inline void set_rotation(float a, float b, float c, float d)
        {
            set_rotation(glm::quat(a, b, c, d));
        }

        /**
         * Lets the entity update any state about itself. This will be 
         * called every engine::tick
         */
        void tick();

        virtual void on_tick() {}
        virtual void on_set_position() {}
        virtual void on_set_rotation() {}
        virtual ~entity() {}
    protected:
        glm::vec3 _position;
        glm::vec3 _last_position;
        glm::vec3 _velocity;
        glm::quat _rotation;
    };
}

#endif