#ifndef STATE_HPP
#define STATE_HPP
#include <SDL2/SDL.h>
#include "Sprite.hpp"
using namespace std;

class State{
    private:
    Sprite bg;
    //Music music;
    bool quitRequested;
    public:

    State();
    void LoadAssets();
    void Update(float dt);
    void Render();
    bool QuitRequested();
};
#endif