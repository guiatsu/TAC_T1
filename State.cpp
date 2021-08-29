#include "State.hpp"

State::State(){
    quitRequested = false;
}

void State::LoadAssets(){
    true;
}
void State::Render(){
    true;
}
void State::Update(float dt){
    true;
}
bool State::QuitRequested(){
    return quitRequested;
}