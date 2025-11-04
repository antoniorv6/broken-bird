#include <Components.hpp>
#include <PhysicsSystem.hpp>
extern "C"
{
    #include <raylib.h>
}

void PhysicsSystem::update(entt::registry& registry, float deltaTime)
{
    auto player_view = registry.view<PlayerComponent, PhysicsComponent>();
    for (auto [entity, p, phys] : player_view.each())
    {
        if(p.flap)
        {
            phys.vy = -300.f;
        }
        p.flap = 0;
    };

    auto view = registry.view<PhysicsComponent>();
    for (auto [entity, phys] : view.each())
    {
        if(phys.hasGravity)
            phys.vy += 900.f * deltaTime;
        phys.x += phys.vx * deltaTime;
        phys.y += phys.vy * deltaTime;        
    };
}

void PhysicsSystem::check_collisions(entt::registry& registry)
{   
}


