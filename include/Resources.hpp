#ifndef RESOURCES_HPP
#define RESOURCES_HPP
#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <unordered_map>
#include <string>
#include <memory>
using namespace std;
class Resources{
    private:
        static unordered_map<string, shared_ptr<SDL_Texture>> imageTable;
        static unordered_map<string, Mix_Music*> musicTable;
        static unordered_map<string, Mix_Chunk*> soundTable;
    public:
        static shared_ptr<SDL_Texture>GetImage(string file);
        static void ClearImages();

        static Mix_Music *GetMusic(string file);
        static void ClearMusics();

        static Mix_Chunk *GetSound(string file);
        static void ClearSounds();
};

#endif