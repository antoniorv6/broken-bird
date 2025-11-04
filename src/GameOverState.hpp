#pragma once
#include <GameState.hpp>
extern "C" {
    #include <raylib.h>
}
#include <deque>

class GameOverState : public GameState
{
    public:
        GameOverState();
        ~GameOverState() {};

        void init() override;
        void handleInput() override;
        void update(float deltaTime) override;
        void render() override;

        void pause(){};
        void resume(){};

    
    private:
        
};