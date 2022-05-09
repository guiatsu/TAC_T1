#ifndef TITLESTATE_HPP
#define TITLESTATE_HPP
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
#include "Text.hpp"
#include "Collider.hpp"
using namespace std;

class TitleState : public State {
    public:

    TitleState();
    ~TitleState();
    void LoadAssets();
    void Update(float dt);
    void Render();

    void Start();
    void Pause();
    void Resume();
};
#endif