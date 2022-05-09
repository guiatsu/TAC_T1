#include "../include/Alien.hpp"
#include "../include/Game.hpp"
#include <iostream>
int Alien::aliencount = 0;
Alien::Alien(GameObject &associated, int nMinions, float timeOffset) : Component(associated){
    Sprite *sprite = new Sprite(associated, "./assets/img/alien.png");
    associated.AddComponent(sprite);
    hp = 100;
    speed = Vect(0,0);
    this -> nMinions = nMinions;
    Collider *collider = new Collider(associated);
    associated.AddComponent(collider);
    aliencount += 1;
    state = RST;
    rest = new Timer();
    this -> timeOffset = timeOffset;
}
    
void Alien::Start(){
    for (int i = 0 ; i<nMinions;i++){

        State *instance = &Game::GetInstance().GetCurrentState();
        GameObject *go = new GameObject();
        weak_ptr<GameObject> aliencenter = instance -> GetObjectPtr(&associated);
        Minion *minion = new Minion(*go,aliencenter,(M_PI*(1+2*i*360/nMinions))/360);
        go -> AddComponent(minion);
        minionArray.push_back(instance -> AddObject(go));
    }

}

Alien::~Alien(){
    for(unsigned int i = 0 ; i< minionArray.size();i++){
        if(shared_ptr<GameObject> go = minionArray[i].lock())
            go ->RequestDelete();
    }
    aliencount -= 1;
}

void Alien::Update(float dt){
    int spd = 256;
    InputManager input = InputManager::GetInstance();
    if(hp <= 0){
        associated.RequestDelete();
    }
    else{
        rest -> Update(dt);
        Vect alien_pos = Vect(associated.box.x,associated.box.y);
        if(state == RST){
            if(rest -> Get() >= (0.5+timeOffset)){
                Vect destiny_center;
                PenguinBody *pbody = PenguinBody::player;
                if(pbody != nullptr){
                    destiny_center.x = pbody->GetPosition().center().x - associated.box.w/2;
                    destiny_center.y = pbody->GetPosition().center().y - associated.box.h/2;
                    destination = Vect(destiny_center.x,destiny_center.y);
                    speed = (destiny_center-alien_pos).normalized();
                    state = MV;
                }
            }
        }

        associated.angleDeg -= M_PI/180*dt*spd*8;

        if(state == MV){
            bool arrived = false;
            alien_pos += speed*dt*spd;
            if(std::abs(alien_pos.dist(destination)) <= 325){
                arrived = true;
                speed = Vect(0,0);
            }
            associated.box.x = alien_pos.x;
            associated.box.y = alien_pos.y;
            if(arrived){
                Vect destiny_center;
                PenguinBody *pbody = PenguinBody::player;
                if(pbody != nullptr){
                    destiny_center.x = pbody->GetPosition().center().x;
                    destiny_center.y = pbody->GetPosition().center().y;
                    destination = Vect(destiny_center.x,destiny_center.y);

                    int minionN = ClosestMinion(destination);
                    if(minionN != -1)
                        if(shared_ptr<GameObject> go = minionArray[minionN].lock()){

                            Minion *minion = (Minion *)go -> GetComponent("Minion");
                            minion -> Shoot(destination);
                        }
                    state = RST;
                    rest ->Restart();
                }

            }
        }
    }
        
    
}
int Alien::ClosestMinion(Vect pos){
    int minion = -1;
    float min_distance = 999999999; 
    for(unsigned int i = 0; i < minionArray.size(); i++){
        if(shared_ptr<GameObject> go = minionArray[i].lock()){
            Vect aux = Vect(go->box.x,go->box.y);
            float dist = aux.dist(pos);
            if(dist <= min_distance){
                min_distance = dist;
                minion = i;
            }
        }
    }
    return minion;
}
void Alien::Render(){

}
bool Alien::Is(string type){
    if(type == "Alien")
        return true;
    return false;
}
void Alien::NotifyCollision(GameObject& other){
    Bullet *bullet = (Bullet *)other.GetComponent("Bullet");
    if(bullet != nullptr){
        if(!bullet->targetsPlayer){
            other.RequestDelete();
            GameObject *snow = new GameObject();
            State *instance = &Game::GetInstance().GetCurrentState();
            Sound *sound = new Sound(*snow,"./assets/audio/snow.wav");
            sound ->Play(0);
            sound -> Volume(20);
            snow -> AddComponent(sound);
            instance ->AddObject(snow);
            snow -> RequestDelete();
            hp -= bullet->GetDamage();
            if(hp <= 0){
                GameObject *go = new GameObject();
                go -> angleDeg = associated.angleDeg;
                Sprite *sprite = new Sprite(*go, "./assets/img/aliendeath.png",4,3.0/30.0,12.0/30.0);
                go->box.x = associated.box.center().x - go->box.w/2;
                go->box.y = associated.box.center().y - go->box.h/2;
                Sound *sound = new Sound(*go,"./assets/audio/boom.wav");
                sound ->Play(0);
                sound -> Volume(5);

                go -> AddComponent(sound);
                go -> AddComponent(sprite);
                instance ->AddObject(go);
                for(unsigned int i = 0 ; i< minionArray.size();i++){
                    if(shared_ptr<GameObject> go = minionArray[i].lock()){
                        GameObject *go2 = new GameObject();
                        Sprite *minionSprite = (Sprite *)go ->GetComponent("Sprite");
                        go2 ->angleDeg = go->angleDeg;
                        Vect scale = minionSprite->GetScale();
                        Sprite *sprite = new Sprite(*go2, "./assets/img/aliendeath.png",4,3.0/30.0,12.0/30.0);
                        sprite ->SetScale(scale.x*0.5,scale.y*0.5);
                        go2->box.x = go->box.center().x - go2->box.w/2;
                        go2->box.y = go->box.center().y - go2->box.h/2;
                        Sound *sound = new Sound(*go2,"./assets/audio/boom.wav");
                        sound ->Play(0);
                        sound -> Volume(0.5);

                        go2 -> AddComponent(sound);
                        go2 -> AddComponent(sprite);
                        instance ->AddObject(go2);
                    }
                }
            }
        }
    }
}