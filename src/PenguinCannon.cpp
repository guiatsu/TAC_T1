#include "../include/PenguinCannon.hpp"
#include "../include/Bullet.hpp"
#include "../include/Game.hpp"
PenguinCannon::PenguinCannon(GameObject &associated, weak_ptr<GameObject> penguinBody) : Component(associated){
    angle = 0;
    pbody = penguinBody;
    Sprite *sprite = new Sprite(associated, "./assets/img/cubngun.png");
    associated.AddComponent(sprite);
}
void PenguinCannon::Update(float dt){
    InputManager instance = InputManager::GetInstance();
    if(shared_ptr<GameObject> go = pbody.lock()){
        associated.box.x = go -> box.center().x - associated.box.w/2;
        associated.box.y = go -> box.center().y - associated.box.h/2;
        Vect centerPos = Vect(instance.GetMouseX()+Camera::pos.x,instance.GetMouseY()+Camera::pos.y);
        Vect pos = associated.box.center();
        angle = pos.anglex2(centerPos);
        associated.angleDeg = angle*180/M_PI;
        if(instance.MousePress(LEFT_MOUSE_BUTTON)){
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
    Sprite *sprite = (Sprite *)associated.GetComponent("Sprite");
    Vect pos = associated.box.center();
    Vect aux =  Vect(sprite->GetWidth()/2,0).rotate(angle)+pos;
    GameObject *go = new GameObject();
    go -> box.x = aux.x;
    go -> box.y = aux.y;
    go -> angleDeg = angle*180/M_PI;
    
    Bullet *bullet = new Bullet(*go,angle,512,50,1024,"./assets/img/penguinbullet.png",4);
    go -> AddComponent(bullet);
    State *instance = &Game::GetInstance().GetState();
    instance -> AddObject(go);    
}
void PenguinCannon::Start(){

}
