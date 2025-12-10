#include <config.h>
#include <MainGameState.hpp>
#include <GameOverState.hpp>
#include <StateMachine.hpp>
#include <Components.hpp>
#include <iostream>

MainGameState::MainGameState()
{
    physics_system = PhysicsSystem();
}

MainGameState::~MainGameState()
{
    for(const auto entity: registry.view<RenderComponent>()) {
        registry.destroy(entity);
    }
    UnloadTexture(this->birdSprite);
    UnloadTexture(this->pipeSprite);
}

void MainGameState::init()
{
    std::string pipe_path = GetAssetPath(std::string("pipe-green.png"));
    pipeSprite = LoadTexture(pipe_path.c_str());

    std::string background_path = GetAssetPath(std::string("background-day.png"));
    backgroundSprite = LoadTexture(background_path.c_str());

    std::string player_path = GetAssetPath(std::string("yellow_bird-downflap.png"));
    birdSprite = LoadTexture(player_path.c_str());

    auto player = registry.create();
    //Añadimos componente de físicas al jugador
    registry.emplace<PlayerComponent>(player, 0);
    registry.emplace<PhysicsComponent>(player, 128.0f, 256.0f, 0.0f, 0.0f, birdSprite.width, birdSprite.height, 1);
    registry.emplace<RenderComponent>(player, LoadTexture("assets/yellowbird-downflap.png"), 0);
    
    PIPE_W = (float)this->pipeSprite.width;
    PIPE_H = (float)this->pipeSprite.height;
}

void MainGameState::handleInput()
{
    input_system.update(registry);
}

void MainGameState::update(float deltaTime)
{
    //this->player.vy += GRAVITY * deltaTime;
    //this->player.y += this->player.vy * deltaTime;
//
    //Rectangle player_bbox = {
    //    this->player.x - this->player.width/2, 
    //    this->player.y - this->player.height/2, 
    //    this->player.width, 
    //    this->player.height
    //};
//
    ////Control de spawn de tuberias
    this->spawnTimer += deltaTime;
    if(spawnTimer >= spawnEvery)
    {
        this->spawnTimer = 0.f;
        int window_width = GetScreenWidth();
        int window_height = GetScreenHeight();
        float pipe_y_offset_top = GetRandomValue(PIPE_H/2.f, window_height/2);

        auto pipe_bottom = registry.create();
        registry.emplace<PhysicsComponent>(pipe_bottom, 
            float(window_width), (PIPE_H - pipe_y_offset_top) + GetRandomValue(PIPE_H/2.f, window_height/2.f), -PIPE_SPEED, 0.f, PIPE_W, PIPE_H, 0
        );
        registry.emplace<RenderComponent>(pipe_bottom, pipeSprite, 0);

        auto pipe_top = registry.create();
        registry.emplace<PhysicsComponent>(pipe_top, 
            float(window_width), -pipe_y_offset_top, -PIPE_SPEED, 0.f, PIPE_W, PIPE_H, 0
        );
        registry.emplace<RenderComponent>(pipe_top, pipeSprite, 180.f);

    }

    physics_system.update(registry, deltaTime); 
}

void MainGameState::render()
{
    BeginDrawing();
    ClearBackground(SKYBLUE);
    
    DrawTextureEx(backgroundSprite, {0.0f, 0.0f}, 0, 1, WHITE);

    render_system.update(registry);

    EndDrawing();
}