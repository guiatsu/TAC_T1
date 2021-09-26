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
    music = Resources::GetMusic(file);
}
bool Music::IsOpen(){
    if(music != nullptr){
        return true;
    }
    return false;
}
Music::~Music(){
    Stop(1500);
}
