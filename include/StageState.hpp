#ifndef STAGESTATE_HPP
#define STAGESTATE_HPP
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
#include "State.hpp"
#include "PenguinBody.hpp"
#include <memory>
#include <math.h>
#include "Collider.hpp"
using namespace std;

class StageState : public State {
    private:
    TileSet *tileSet;
    Music *BackgroundMusic;
    public:

    StageState();
    ~StageState();
    void LoadAssets();
    void Update(float dt);
    void Render();
    void Start();
    void Pause();
    void Resume();
};
#endif