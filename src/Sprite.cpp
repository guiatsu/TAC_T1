#include "../include/Sprite.hpp"
#include "../include/Game.hpp"
#include <iostream>
Sprite::Sprite (GameObject &associated) : Component(associated){
    texture = nullptr;
    scale.x = 1;
    scale.y = 1;
}
Sprite::Sprite (GameObject &associated, string file) : Component(associated){
    texture = nullptr;
    scale.x = 1;
    scale.y = 1;
    Open(file);
}
Sprite::~Sprite (){
}
void Sprite::Open (string file){
    if(!IsOpen()){
        texture =  Resources::GetImage(file);
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
    Render(associated.box.x-Camera::pos.x,associated.box.y-Camera::pos.y);
}
void Sprite::Render (float x, float y){
    SDL_Rect dsrect;

    dsrect.x = x+clipRect.w/2 - clipRect.w/2*scale.x;
    dsrect.y = y+clipRect.h/2 - clipRect.h/2*scale.y;
    dsrect.w = clipRect.w*scale.x;
    dsrect.h = clipRect.h*scale.y;
    if(IsOpen())
        if(SDL_RenderCopyEx(Game::GetInstance().GetRenderer(),texture,&clipRect,&dsrect,associated.angleDeg,nullptr,SDL_FLIP_NONE) != 0)
            cout << SDL_GetError() << endl;
}
int Sprite::GetWidth (){
    return width*scale.x;
}
int Sprite::GetHeight (){
    return height*scale.y;
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
Vect Sprite::GetScale(){
    return scale;
}
void Sprite::SetScale(float scaleX, float scaleY){
    scale.x = scaleX == 0 ? scale.x : scaleX;
    scale.y = scaleY == 0 ? scale.y : scaleY;
}
void Sprite::Start(){
    
}