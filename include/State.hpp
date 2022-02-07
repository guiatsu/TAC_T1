#ifndef STATE_HPP
#define STATE_HPP
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Sprite.hpp"
#include "Music.hpp"
#include "Sound.hpp"
#include "InputManager.hpp"
#include "Camera.hpp" 
#include "CameraFollower.hpp"
#include "Alien.hpp"
#include "TileMap.hpp"
#include "PenguinBody.hpp"
#include <memory>
#include <math.h>
using namespace std;

class State{
    private:
    vector<shared_ptr<GameObject>> objectArray;
    Music *music;
    bool quitRequested;
    void Input();
    bool started;
    public:

    State();
    ~State();
    void LoadAssets();
    void Update(float dt);
    void Render();
    void Start();
    weak_ptr<GameObject> AddObject(GameObject *go);
    weak_ptr<GameObject> GetObjectPtr(GameObject *go);
    bool QuitRequested();
};
#endif