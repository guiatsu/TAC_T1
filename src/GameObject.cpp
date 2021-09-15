#include "../include/GameObject.hpp"

GameObject::GameObject(){
    isDead = false;
}

GameObject::~GameObject(){
    for (int i = this -> components.size()-1; i >= 0; i--)
    {
        components.erase(this -> components.begin()+i);
    }
}

void GameObject::Update(float dt){
    for(unsigned int i = 0; i < this -> components.size(); i++){
        components[i].get() -> Update(dt);
    }
}
void GameObject::Render(){
    for(unsigned int i = 0; i < this -> components.size(); i++){
        components[i].get() -> Render();
    }
}

bool GameObject::IsDead(){
    return this -> isDead;
}

void GameObject::AddComponent(Component *cpt){
    this -> components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component *cpt){
    for(unsigned int i = 0; i < this -> components.size(); i++){
        if(this -> components[i].get()  == cpt){
            components.erase(this -> components.begin()+i);
            break;
        }
    }
}
void GameObject::RequestDelete(){
    this -> isDead = true;
}

Component *GameObject::GetComponent(string type){
    for(unsigned int i = 0;i < this -> components.size();i++)
        if(this -> components[i] -> Is(type))
            return components[i].get();
    return nullptr;
}