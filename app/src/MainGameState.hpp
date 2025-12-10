#pragma once
#include <GameState.hpp>
extern "C" {
    #include <raylib.h>
}
#include <entt/entt.hpp>
#include <PhysicsSystem.hpp>
#include <RenderSystem.hpp>
#include <InputSystem.hpp>

class MainGameState : public GameState
{
    public:
        MainGameState();
        ~MainGameState();

        void init() override;
        void handleInput() override;
        void update(float deltaTime) override;
        void render() override;

        void pause(){};
        void resume(){};

    
    private:
        char entered_key;
        float GRAVITY = 900.f;
        float FLAP_VY = -300.f;
        float GAP_H = 140.f, PIPE_W = 70.f, PIPE_H=70.f;
        float PIPE_SPEED = 180.f;
        float spawnTimer = 0.f, spawnEvery = 1.8f; 
        uint8_t points = 0;

        Texture2D birdSprite;
        Texture2D pipeSprite;
        Texture2D backgroundSprite;

        entt::registry registry;
        PhysicsSystem physics_system;
        RenderSystem render_system;
        InputSystem input_system;
};