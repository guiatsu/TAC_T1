#include "../include/Minion.hpp"
#include "../include/Game.hpp"

#include <iostream>
Minion::Minion(GameObject &associated, weak_ptr<GameObject> alienCenter, float arcOffsetDeg) : Component(associated){
    Sprite *sprite = new Sprite(associated, "./assets/img/minion.png");
    associated.AddComponent(sprite);
    double scale = float(rand())/float(RAND_MAX/(0.5))+1;
    sprite->SetScale(scale,scale);
    this -> alienCenter = alienCenter;
    if(shared_ptr<GameObject> go = alienCenter.lock()){

        associated.box.x = go->box.center().x+200-associated.box.w/2;
        associated.box.y = go->box.center().y+0-associated.box.h/2;
    }
    arc = arcOffsetDeg;
    associated.angleDeg = arcOffsetDeg;
    Collider *collider = new Collider(associated);
    associated.AddComponent(collider);
}
Minion::~Minion(){

}
void Minion::Update(float dt){
    Vect center_pos = alienCenter.lock()->box.center();
    Vect aux = Vect(100,0).rotate(arc)+center_pos;
    arc+= 2*M_PI/360*dt*64;
    associated.box.x = aux.x-associated.box.w/2;
    associated.box.y = aux.y-associated.box.h/2;
    Vect pos = associated.box.center();
    associated.angleDeg = (pos.anglex2(center_pos)*360)/ (2*M_PI);

}

void Minion::Render(){

}
bool Minion::Is(string type){
    if(type == "Minion")
        return true;
    return false;
}
void Minion::Shoot(Vect target){
    Sprite *sprite = (Sprite *)associated.GetComponent("Sprite");
    Vect pos = associated.box.center();
    float angle = pos.anglex2(target);
    Vect aux =  Vect(sprite->GetWidth()/2,0).rotate(angle)+pos;
    GameObject *go = new GameObject();
    go -> box.x = aux.x;
    go -> box.y = aux.y;
    go -> angleDeg = angle*180/M_PI;
    
    Bullet *bullet = new Bullet(*go,angle,512,50,1024,"./assets/img/minionbullet2.png",3,true);
    go -> AddComponent(bullet);
    State *instance = &Game::GetInstance().GetState();
    instance -> AddObject(go);    
    GameObject *sd = new GameObject();
    Sound *sound = new Sound(*sd,"./assets/audio/laser.wav");
    sound ->Play(0);
    sound -> Volume(20);
    sd -> AddComponent(sound);
    instance ->AddObject(sd);
    sd -> RequestDelete();


}
void Minion::Start(){

}
void Minion::NotifyCollision(GameObject& other){

}