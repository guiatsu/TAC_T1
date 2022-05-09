#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Sprite.hpp"
#include "Music.hpp"
#include "Sound.hpp"
#include "InputManager.hpp"
#include "Camera.hpp" 
#include "CameraFollower.hpp"
#include "State.hpp"
#include <memory>
#include <math.h>
#include "Text.hpp"
#include "Collider.hpp"
using namespace std;

class GameData {
    public:
    static bool playerVictory;

};
#endif