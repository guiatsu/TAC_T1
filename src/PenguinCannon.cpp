#include "../include/PenguinCannon.hpp"
#include "../include/Bullet.hpp"
#include "../include/Game.hpp"
PenguinCannon::PenguinCannon(GameObject &associated, weak_ptr<GameObject> penguinBody) : Component(associated){
    angle = 0;
    pbody = penguinBody;
    Sprite *sprite = new Sprite(associated, "./assets/img/cubngun.png");
    associated.AddComponent(sprite);
    Collider *collider = new Collider(associated);
    associated.AddComponent(collider);
    timer = nullptr;
}
void PenguinCannon::Update(float dt){
    InputManager instance = InputManager::GetInstance();
    if(timer != nullptr)
        timer -> Update(dt);
    if(shared_ptr<GameObject> go = pbody.lock()){
        associated.box.x = go -> box.center().x - associated.box.w/2;
        associated.box.y = go -> box.center().y - associated.box.h/2;
        Vect centerPos = Vect(instance.GetMouseX()+Camera::pos.x,instance.GetMouseY()+Camera::pos.y);
        Vect pos = associated.box.center();
        angle = pos.anglex2(centerPos);
        associated.angleDeg = angle*180/M_PI;
        if(instance.IsMouseDown(LEFT_MOUSE_BUTTON)){
            Shoot();
        }
    }
    else{
        associated.RequestDelete();
    }

}
void PenguinCannon::Render(){

}
bool PenguinCannon::Is(string type){
    if(type == "PenguinCannon")
        return true;
    return false;
}
void PenguinCannon::Shoot(){
    if(timer == nullptr || timer -> Get() >= 0.5){
        Sprite *sprite = (Sprite *)associated.GetComponent("Sprite");
        Vect pos = associated.box.center();
        Vect aux =  Vect(sprite->GetWidth()/2,0).rotate(angle)+pos;
        GameObject *go = new GameObject();
        go -> box.x = aux.x;
        go -> box.y = aux.y;
        go -> angleDeg = angle*180/M_PI;
        
        Bullet *bullet = new Bullet(*go,angle,512,10,1024,"./assets/img/penguinbullet.png",4,false);
        go -> AddComponent(bullet);
        State *instance = &Game::GetInstance().GetCurrentState();
        instance -> AddObject(go);
        GameObject *sd = new GameObject();
        Sound *sound = new Sound(*sd,"./assets/audio/cannon.wav");
        sound ->Play(0);
        sound -> Volume(20);
        sd -> AddComponent(sound);
        instance ->AddObject(sd);
        sd -> RequestDelete();
        if(timer == nullptr){
            timer = new Timer();

        }
        timer -> Restart();
    }
}
void PenguinCannon::Start(){

}
void PenguinCannon::NotifyCollision(GameObject& other){

}