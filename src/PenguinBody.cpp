#include "../include/PenguinBody.hpp"
#include "../include/PenguinCannon.hpp"
#include "../include/Game.hpp"
#include <iostream>
PenguinBody* PenguinBody::player = nullptr;
PenguinBody::PenguinBody(GameObject &associated) : Component(associated){
    Sprite *sprite = new Sprite(associated, "./assets/img/penguin.png");
    associated.AddComponent(sprite);
    player = this;
    speed = Vect(0,0);
    linearSpeed = 1;
    angle = 0;
    hp = 100;

}
PenguinBody::~PenguinBody(){
    player = nullptr;
}
void PenguinBody::Start(){
    State *instance = &Game::GetInstance().GetState();
    GameObject *go = new GameObject();
    weak_ptr<GameObject> penguinCenter = instance -> GetObjectPtr(&associated);
    PenguinCannon *penguinCannon = new PenguinCannon(*go,penguinCenter);
    go -> AddComponent(penguinCannon);
    pcannon = instance -> AddObject(go);

}
void PenguinBody::Update(float dt){
    Vect penguinPos = Vect(associated.box.x,associated.box.y);
    InputManager instance = InputManager::GetInstance();
    if(instance.IsKeyDown(W_KEY)){
        if(speed.x <= 40)
            speed = speed+Vect(1,0);
    }
    if(instance.IsKeyDown(S_KEY)){
        if(speed.x >= -40)
            speed = speed+Vect(-1,0);
    }
    if(instance.IsKeyDown(D_KEY)){
        angle+= M_PI/15*dt*512;
        associated.angleDeg = angle;
    }
    if(instance.IsKeyDown(A_KEY)){
        angle -= M_PI/15*dt*512;
        associated.angleDeg = angle;
    }
    penguinPos+= speed.normalized().rotate(angle/180*M_PI)*dt*8;
    associated.box.x = penguinPos.x;
    associated.box.y = penguinPos.y;
    if(hp <= 0){
        if(shared_ptr<GameObject> go = pcannon.lock()){
            go->RequestDelete();
        }
        associated.RequestDelete();
    }

}
void PenguinBody::Render(){

}
bool PenguinBody::Is(string type){
    if(type == "PenguinBody")
        return true;
    return false;
}