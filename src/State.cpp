#include "../include/State.hpp"
State::State(){
    quitRequested = false;
    started = false;
    popRequested = false;

}
State::~State(){
    objectArray.clear();
}

void State::LoadAssets(){

}
bool State::QuitRequested(){
    return quitRequested;
}
bool State::PopRequested(){
    return popRequested;
}
void State::StartArray (){
    for(unsigned int i = 0; i < objectArray.size();i++){
        objectArray[i] -> Start();
    }
}
void State::UpdateArray (float dt){
    for(unsigned int i = 0; i < objectArray.size();i++){
        objectArray[i] -> Update(dt);
    }
}
void State::RenderArray (){
    for(unsigned int i = 0; i < objectArray.size();i++){
        objectArray[i] -> Render();
    }
}

weak_ptr<GameObject> State::AddObject(GameObject *go){
    
    shared_ptr<GameObject> shrd_go(go);
    objectArray.push_back(shrd_go);
    if(started == true){
        shrd_go -> Start();
    }
    weak_ptr<GameObject> weak_go(shrd_go);
    return weak_go;

}
weak_ptr<GameObject> State::GetObjectPtr(GameObject *go){
    for(unsigned int i = 0; i < objectArray.size();i++){
        if(objectArray[i].get() == go){
            weak_ptr<GameObject> weak_go(objectArray[i]);
            return weak_go;
        }
    }
    return {};
}