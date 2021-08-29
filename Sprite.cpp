#include "Sprite.hpp"
#include "Game.hpp"

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
    if(texture != nullptr){
        texture = nullptr;
    }
    else{
        texture = IMG_LoadTexture( Game::GetInstance().GetRenderer(), file.c_str());
        SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
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
    SDL_RenderCopy(Game::GetInstance().GetRenderer(),texture,&clipRect,&dsrect);
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