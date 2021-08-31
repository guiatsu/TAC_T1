#include "../include/Music.hpp"

Music::Music(){

}
Music::Music(string file){
    Open(file);
}

void Music::Play(int times){
    Mix_PlayMusic(music,times);
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file){

    music = Mix_LoadMUS(file.c_str());
}
bool Music::IsOpen(){
    if(music != nullptr){
        return true;
    }
    return false;
}
Music::~Music(){
    Stop(1500);
    Mix_FreeMusic(music);
}
