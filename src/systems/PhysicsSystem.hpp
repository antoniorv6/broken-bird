#pragma once
#include <entt/entt.hpp>

class PhysicsSystem
{
    public:
        PhysicsSystem(){};
        ~PhysicsSystem(){};
        void update(entt::registry& registry, float deltaTime);
    private:
        void check_collisions(entt::registry& registry);
};
