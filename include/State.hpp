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
#include "Collider.hpp"
#include "GameData.hpp"
using namespace std;

class State{
    private:
    Music *music;
    void Input();
    public:

    State();
    virtual ~State();
    virtual void LoadAssets() = 0;
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual void Start() = 0;
    virtual void Pause () = 0;
    virtual void Resume () = 0;
    virtual weak_ptr<GameObject> AddObject(GameObject *go);
    virtual weak_ptr<GameObject> GetObjectPtr(GameObject *go);
    bool QuitRequested();
    bool PopRequested();
    protected:
    void StartArray();
    virtual void UpdateArray(float dt);
    virtual void RenderArray();
    bool popRequested;
    bool quitRequested;
    bool started;
    vector<shared_ptr<GameObject>> objectArray;
};
#endif