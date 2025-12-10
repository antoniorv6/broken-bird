#pragma once
#include <entt/entt.hpp>

class InputSystem
{
    public:
        InputSystem(){};
        ~InputSystem(){};
        void update(entt::registry& registry);
};