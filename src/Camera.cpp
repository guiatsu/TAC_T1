#include "../include/Camera.hpp"
#include <iostream>
Vect Camera::pos;
GameObject *Camera::focus;

void Camera::Follow (GameObject* newFocus){
    focus = newFocus;
}

void Camera::Unfollow (){
    focus = nullptr;
}

void Camera::Update (float dt){
    InputManager instance = InputManager::GetInstance();
    int spd = 128;
    if(focus != nullptr){
        pos.x = focus ->box.center().x;
        pos.y = focus ->box.center().y;
    }
    else{
        if(instance.IsKeyDown(UP_ARROW_KEY)){
            pos.y -= dt*spd;
        }
        if(instance.IsKeyDown(DOWN_ARROW_KEY)){
            pos.y += dt*spd;
        }
        if(instance.IsKeyDown(LEFT_ARROW_KEY)){
            pos.x -= dt*spd;
        }
        if(instance.IsKeyDown(RIGHT_ARROW_KEY)){
            pos.x += dt*spd;
        }
        // cout << pos.x << " " << pos.y << endl;
    }
}