#ifndef GAME_HPP
#define GAME_HPP
#define INCLUDE_SDL
#include "SDL_include.h"
#include "State.hpp"
#include <string>
#include <iostream>
using namespace std;
class Game{

private:

    static Game *instance;
    SDL_Window *window;
    SDL_Renderer *renderer;
    State *state;
    int frameStart;
    float dt;
    void CalculateDeltaTime();
    Game(string title, int width, int height);
public:
    ~Game();
    SDL_Renderer *GetRenderer();
    State &GetState();
    static Game &GetInstance();
    void Run();
    float GetDeltaTime();
};
#endif