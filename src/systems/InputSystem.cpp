#include <InputSystem.hpp>
#include <Components.hpp>
extern "C"
{
    #include <raylib.h>
}

void InputSystem::update(entt::registry& registry)
{
    auto view = registry.view<PlayerComponent>();

    for(auto [entity, comp] : view.each())
    {
        if(IsKeyPressed(KEY_SPACE))
            comp.flap = 1;
    }
}
