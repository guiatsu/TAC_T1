#include "../include/Minion.hpp"
#include "../include/Game.hpp"

#include <iostream>
Minion::Minion(GameObject &associated, weak_ptr<GameObject> alienCenter, float arcOffsetDeg) : Component(associated){
    Sprite *sprite = new Sprite(associated, "./assets/img/minion.png");
    associated.AddComponent(sprite);
    this -> alienCenter = alienCenter;
    if(shared_ptr<GameObject> go = alienCenter.lock()){

        associated.box.x = go->box.center().x+200-associated.box.w/2;
        associated.box.y = go->box.center().y+0-associated.box.h/2;
    }
    arc = arcOffsetDeg;
}

void Minion::Update(float dt){
    Vect center_pos = alienCenter.lock()->box.center();
    Vect aux = Vect(100,0).rotate(arc)+center_pos;
    arc+= M_PI/360*dt*256;
    associated.box.x = aux.x-associated.box.w/2;
    associated.box.y = aux.y-associated.box.h/2;
}
void Minion::Render(){

}
bool Minion::Is(string type){
    if(type == "Minion")
        return true;
    return false;
}
void Minion::Shoot(Vect target){
    Vect pos = Vect(associated.box.x,associated.box.y);
    float angle = pos.anglex2(target);
    GameObject *go = new GameObject();
    go -> box.x = pos.x;
    go -> box.y = pos.y;
    Bullet *bullet = new Bullet(*go,angle,512,50,1024,"./assets/img/minionbullet1.png");
    go -> AddComponent(bullet);
    State *instance = &Game::GetInstance().GetState();
    instance -> AddObject(go);    

}
void Minion::Start(){

}