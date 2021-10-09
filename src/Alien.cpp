#include "../include/Alien.hpp"
#include "../include/Game.hpp"
#include <iostream>
Alien::Alien(GameObject &associated, int nMinions) : Component(associated){
    Sprite *sprite = new Sprite(associated, "./assets/img/alien.png");
    associated.AddComponent(sprite);
    hp = 100;
    speed = Vect(0,0);
    this -> nMinions = nMinions;
}
    
void Alien::Start(){
    for (int i = 0 ; i<nMinions;i++){

        State *instance = &Game::GetInstance().GetState();
        GameObject *go = new GameObject();
        weak_ptr<GameObject> aliencenter = instance -> GetObjectPtr(&associated);
        Minion *minion = new Minion(*go,aliencenter,(M_PI*(1+2*i*360/nMinions))/360);
        go -> AddComponent(minion);
        minionArray.push_back(instance -> AddObject(go));    
    }

}
Alien::Action::Action(ActionType type, float x, float y){
    pos.x = x;
    pos.y = y;
    this -> type = type;
}
Alien::~Alien(){

}

void Alien::Update(float dt){
    int spd = 256;
    InputManager input = InputManager::GetInstance();
    if(input.MousePress(LEFT_MOUSE_BUTTON)){
        taskQueue.push(Action(SHT,input.GetMouseX()+Camera::pos.x,input.GetMouseY()+Camera::pos.y));
    }

    else if (input.MousePress(RIGHT_MOUSE_BUTTON)){
        taskQueue.push(Action(MV,input.GetMouseX()+Camera::pos.x,input.GetMouseY()+Camera::pos.y));
    }
    speed = Vect(0,0);
    Vect alien_pos = Vect(associated.box.x,associated.box.y);

    if(taskQueue.size() >= 1){
        Action action = taskQueue.front();
        if(action.type == MV){
            Vect destiny_center;
            destiny_center.x = action.pos.x - associated.box.w/2;
            destiny_center.y = action.pos.y - associated.box.h/2;
            speed += (destiny_center-alien_pos).normalized();
            alien_pos += speed*dt*spd;
            if(std::abs(alien_pos.dist(destiny_center)) <= 5){
                alien_pos = destiny_center;
                taskQueue.pop();
            }
            associated.box.x = alien_pos.x;
            associated.box.y = alien_pos.y;
        }
        if(action.type == SHT){
            int minionN = rand()%nMinions;
            if(shared_ptr<GameObject> go = minionArray[minionN].lock()){

                Minion *minion = (Minion *)go -> GetComponent("Minion");
                minion -> Shoot(action.pos);
                taskQueue.pop();
            }
        }
    }
    if(hp <= 0){
        associated.RequestDelete();
    }
}
void Alien::Render(){

}
bool Alien::Is(string type){
    if(type == "Alien")
        return true;
    return false;
}