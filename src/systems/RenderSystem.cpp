#include <RenderSystem.hpp>
#include <Components.hpp>
#include <raylib.h>
#include <iostream>

void RenderSystem::update(entt::registry& registry)
{
    auto view = registry.view<const RenderComponent, const PhysicsComponent>();
    for (auto [entity, rend, phys] : view.each())
    {
        float posx = phys.x;
        float posy = phys.y;
        
        if(rend.rotation > 0.f)
        {
            posx += phys.width;
            posy += phys.height;
        }

        DrawTextureEx(rend.texture, {posx, posy}, rend.rotation, 1.f, WHITE);
    };
}