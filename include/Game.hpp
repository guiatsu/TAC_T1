#ifndef GAME_HPP
#define GAME_HPP
#define INCLUDE_SDL
#include <string>
#include <iostream>
#include <stack>
#include "SDL_include.h"
#include "State.hpp"
#include "StageState.hpp"
using namespace std;
class Game{

private:

    static Game *instance;
    SDL_Window *window;
    SDL_Renderer *renderer;
    State *storedState;
    static stack<unique_ptr<State>> stateStack;
    int frameStart;
    float dt;
    void CalculateDeltaTime();
public:
    Game(string title, int width, int height);
    ~Game();
    SDL_Renderer *GetRenderer();
    State &GetCurrentState();
    void Push(State *state);
    static Game &GetInstance();
    void Run();
    float GetDeltaTime();
};
#endif