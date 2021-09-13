#include "../include/Sound.hpp"

Sound::Sound(GameObject &associated) : Component(associated){
    this -> chunk = nullptr;
}
Sound::Sound(GameObject &associated, string file) : Sound(associated){
    Open(file);
} 

void Sound::Play(int times){
    this -> channel = Mix_PlayChannel(-1,this -> chunk,times);
    if(this -> channel == -1){
        cout << "erro na mix_playchanell" << endl;
    }
}

void Sound::Stop(){
    if(chunk != nullptr){
        Mix_HaltChannel(this -> channel);
    }
}

void Sound::Open(string file){
    this -> chunk = Mix_LoadWAV(file.c_str());
    if(this -> chunk == nullptr){
        cout << "erro ao abrir arquivo de som" << endl;
    }
}
void Sound::Render(){

}
void Sound::Update(float dt){

}

Sound::~Sound(){
    // Stop();
    // if(this -> chunk != nullptr){
    //     Mix_FreeChunk(this -> chunk);
    // }
}
bool Sound::Is(string type){
    if(type == "Sound")
        return true;
    return false;
}
