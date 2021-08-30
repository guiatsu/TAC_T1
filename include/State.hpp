#ifndef STATE_HPP
#define STATE_HPP
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Sprite.hpp"
#include "Music.hpp"
using namespace std;

class State{
    private:
    Sprite *bg;
    Music *music;
    bool quitRequested;
    public:

    State();
    void LoadAssets();
    void Update(float dt);
    void Render();
    bool QuitRequested();
};
#endif