#ifndef ENDSTATE_HPP
#define ENDSTATE_HPP
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

class EndState : public State {
    public:

    EndState();
    ~EndState();

    void LoadAssets();
    void Update(float dt);
    void Render();

    void Start();
    void Pause();
    void Resume();

    private:
    Music *backgroundMusic;

};
#endif