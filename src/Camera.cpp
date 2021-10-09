#include "../include/Camera.hpp"
#include <iostream>
Vect Camera::pos;
Vect Camera::speed;
GameObject *Camera::focus;

void Camera::Follow (GameObject* newFocus){
    focus = newFocus;
}

void Camera::Unfollow (){
    focus = nullptr;
}

void Camera::Update (float dt){
    InputManager instance = InputManager::GetInstance();
    speed = Vect(0,0);
    int spd = 256;
    if(focus != nullptr){
        pos.x = focus ->box.center().x;
        pos.y = focus ->box.center().y;
    }
    else{
        if(instance.IsKeyDown(UP_ARROW_KEY)){
            speed += Vect(0,-1);
        }
        if(instance.IsKeyDown(DOWN_ARROW_KEY)){
            speed += Vect(0,1);
        }
        if(instance.IsKeyDown(LEFT_ARROW_KEY)){
            speed += Vect(-1,0);
        }
        if(instance.IsKeyDown(RIGHT_ARROW_KEY)){
            speed += Vect(1,0);
        }
        pos += speed.normalized()*spd*dt;
    }
}