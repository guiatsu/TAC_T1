#include "../include/CameraFollower.hpp"
#include <iostream>
using namespace std;
    CameraFollower::CameraFollower (GameObject &go) : Component(go){

    }
    void CameraFollower::Update (float dt){
        associated.box.x = Camera::pos.x;
        associated.box.y = Camera::pos.y;
    }
    void CameraFollower::Render (){

    }
    bool CameraFollower::Is (string type){
        if(type == "CameraFollower")
            return true;
        return false;
    }