#pragma once
#include <entt/entt.hpp>

class RenderSystem
{
    public:
        RenderSystem(){};
        ~RenderSystem(){};
        void update(entt::registry& registry);
};