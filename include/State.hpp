#ifndef STATE_HPP
#define STATE_HPP
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Sprite.hpp"
#include "Music.hpp"
#include "Sound.hpp"
#include "Face.hpp"
#include <memory>
#include <math.h>
#include "TileMap.hpp"
using namespace std;

class State{
    private:
    vector<unique_ptr<GameObject>> objectArray;
    Music *music;
    bool quitRequested;
    void Input();
    void AddObject(int mouseX, int mouseY);
    public:

    State();
    ~State();
    void LoadAssets();
    void Update(float dt);
    void Render();
    bool QuitRequested();
};
#endif