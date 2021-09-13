#include "../include/Sprite.hpp"
#include "../include/Game.hpp"
#include <iostream>
Sprite::Sprite (GameObject &associated) : Component(associated){
    texture = nullptr;
}
Sprite::Sprite (GameObject &associated, string file) : Component(associated){
    texture = nullptr;
    Open(file);
}
Sprite::~Sprite (){
    SDL_DestroyTexture(texture);
}
void Sprite::Open (string file){
    if(IsOpen()){
        texture = nullptr;
    }
    else{
        texture = IMG_LoadTexture( Game::GetInstance().GetRenderer(), file.c_str());
        if(texture == nullptr){
            cout << IMG_GetError()  << endl;
        }
        if(SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) != 0)
            cout << SDL_GetError() << endl;
        SetClip(0,0,width,height);
        associated.box.w = width;
        associated.box.h = height;
    }
}
void Sprite::SetClip (int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}
void Sprite::Render (){
    SDL_Rect dsrect;
    dsrect.x = associated.box.x;
    dsrect.y = associated.box.y;
    dsrect.w = associated.box.w;
    dsrect.h = associated.box.h;
    if(IsOpen())
        if(SDL_RenderCopy(Game::GetInstance().GetRenderer(),texture,&clipRect,&dsrect) != 0)
            cout << SDL_GetError() << endl;
}
int Sprite::GetWidth (){
    return width;
}
int Sprite::GetHeight (){
    return height;
}
bool Sprite::IsOpen (){
    if(texture != nullptr)
        return true;
    return false;
}
void Sprite::Update(float dt){

}
bool Sprite::Is(string type){
    if(type == "Sprite")
        return true;
    return false;
}