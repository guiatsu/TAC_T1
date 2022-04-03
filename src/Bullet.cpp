#include "../include/Bullet.hpp"

Bullet::Bullet(GameObject &associated, float angle, float speed, int damage, float maxDistance, string sprite,int frameCount,bool targetsPlayer) : Component(associated){
    Sprite *spr = new Sprite(associated, sprite,frameCount,0.017);
    associated.box.x-=spr->GetWidth()/2;
    associated.box.y-=spr->GetHeight()/2;
    associated.AddComponent(spr);
    this -> speed = Vect(1,0);
    this -> speed = this -> speed.rotate(angle)*speed;
    distanceLeft = maxDistance;
    this -> damage = damage;
    Collider *collider = new Collider(associated);
    associated.AddComponent(collider);
    this -> targetsPlayer = targetsPlayer;
}
int Bullet::GetDamage(){
    return damage;
}
bool Bullet::Is(string type){
    if(type == "Bullet")
        return true;
    return false;
}
void Bullet::Render(){
    
}
void Bullet::Update (float dt){
    Vect pos = Vect(associated.box.x,associated.box.y);
    pos += speed*dt;
    associated.box.x = pos.x;
    associated.box.y = pos.y;
    distanceLeft -=  (speed*dt).magnitude();
    if(distanceLeft <= 0)
        associated.RequestDelete();
}
void Bullet::Start(){}
void Bullet::NotifyCollision(GameObject& other){
}