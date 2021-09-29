#include "../include/Resources.hpp"
#include "../include/Game.hpp"

unordered_map<string,SDL_Texture *> Resources::imageTable;
unordered_map<string,Mix_Chunk *> Resources::soundTable;
unordered_map<string,Mix_Music *> Resources::musicTable;

SDL_Texture *Resources::GetImage(string file){
    auto it = imageTable.find(file);
    SDL_Texture* texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    if(it == imageTable.end())
        if(texture != nullptr){
            imageTable[file] = texture;
            return imageTable[file];
        }
        else
            return nullptr;
    else
        return it -> second;
}
void Resources::ClearImages(){
    for(auto i = imageTable.begin();i != imageTable.end();i++)
        SDL_DestroyTexture(i -> second);
}

Mix_Music *Resources::GetMusic(string file){
    auto it = musicTable.find(file);
    Mix_Music *music = Mix_LoadMUS(file.c_str());
    if(it == musicTable.end())
        if(music != nullptr){
            musicTable[file] = music;
            return musicTable[file];
        }
        else
            return nullptr;
    else
        return it -> second;
}
void Resources::ClearMusics(){
    for(auto i = musicTable.begin();i != musicTable.end();i++)
        Mix_FreeMusic(i -> second);
}

Mix_Chunk *Resources::GetSound(string file){
    auto it = soundTable.find(file);
    Mix_Chunk *sound = Mix_LoadWAV(file.c_str());
    if(it == soundTable.end())
        if(sound !=  nullptr){
            soundTable[file] = sound;
            return soundTable[file];
        }
        else
            return nullptr;
    else
        return it -> second;
      
}
void Resources::ClearSounds(){
    for(auto i = soundTable.begin();i != soundTable.end();i++)
        Mix_FreeChunk(i -> second);
}


