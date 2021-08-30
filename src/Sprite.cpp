#include "../include/Sprite.hpp"
#include "../include/Game.hpp"
#include <iostream>
Sprite::Sprite (){
    texture = nullptr;
}
Sprite::Sprite (string file){
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
    }
}
void Sprite::SetClip (int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}
void Sprite::Render (int x, int y){
    SDL_Rect dsrect;
    dsrect.x = x;
    dsrect.y = y;
    dsrect.w = clipRect.w;
    dsrect.h = clipRect.h;
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