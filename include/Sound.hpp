#ifndef SOUND_HPP
#define SOUND_HPP
#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "GameObject.hpp"
#include "Component.hpp"
#include "Resources.hpp"
#include <iostream>
using namespace std;
class Sound : public Component{
    public:
        Sound(GameObject &associated);
        Sound(GameObject &associated, string file);
        ~Sound();
        void Play(int times = 1);
        void Stop();
        void Open(string file);
        bool IsOpen();
        void Update(float dt);
        void Render();
        bool Is(string type);
        void Start();
        void NotifyCollision(GameObject& other);
        void Volume(int volume);
    private:
        Mix_Chunk* chunk;
        int channel;

};

#endif