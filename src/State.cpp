#include "../include/State.hpp"
State::State(){
    bg = new Sprite("./assets/img/ocean.jpg");
    music = new Music("./assets/audio/stageState.ogg");

    music ->Play();
    quitRequested = false;
}

void State::LoadAssets(){
}
void State::Render(){
    bg -> Render(0,0);
}
void State::Update(float dt){
    if(SDL_QuitRequested()){
        music ->Stop();
        quitRequested = true;
    }
}
bool State::QuitRequested(){
    return quitRequested;
}