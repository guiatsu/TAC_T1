#include "../include/Collider.hpp"
#include "../include/Game.hpp"
#include "Collision.cpp"
#include <iostream>


// Adicione o trecho abaixo no começo do seu Collider.cpp,
// logo após os seus includes e antes de qualquer função.

#ifdef DEBUG
#include "../include/Camera.hpp"
#include "../include/Game.hpp"
#include "SDL_include.h"
#endif // DEBUG

#include "../include/Collider.hpp"




// Copie o conteúdo dessa função para dentro da sua e adapte o nome das funções para as suas.
// Funções usadas:
// Rect::center()				- Retorna um Vect no centro do Rect
// Vect::operator-( const Vect& )	- Subtrai dois Vect
// Vect::rotate( float rad )		- Rotaciona um Vect pelo ângulo em radianos passado
void Collider::Render() {
#ifdef DEBUG
        Vect center( box.center() );
        SDL_Point points[5];

        Vect point = (Vect(box.x, box.y) - center).rotate( associated.angleDeg/(180/M_PI) )
                        + center - Camera::pos;
        points[0] = {(int)point.x, (int)point.y};
        points[4] = {(int)point.x, (int)point.y};
        
        point = (Vect(box.x + box.w, box.y) - center).rotate( associated.angleDeg/(180/M_PI) )
                        + center - Camera::pos;
        points[1] = {(int)point.x, (int)point.y};
        
        point = (Vect(box.x + box.w, box.y + box.h) - center).rotate( associated.angleDeg/(180/M_PI) )
                        + center - Camera::pos;
        points[2] = {(int)point.x, (int)point.y};
        
        point = (Vect(box.x, box.y + box.h) - center).rotate( associated.angleDeg/(180/M_PI) )
                        + center - Camera::pos;
        points[3] = {(int)point.x, (int)point.y};

        SDL_SetRenderDrawColor(Game::GetInstance().GetRenderer(), 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLines(Game::GetInstance().GetRenderer(), points, 5);
#endif // DEBUG
}
Collider::Collider (GameObject& associated, Vect scale, Vect offset) : Component(associated){
    this -> scale = scale;
    this -> offset = offset;

}
void Collider::Update (float dt){
    box = associated.box;
    box.w *= scale.x;
    box.h *= scale.y;
    float angle = associated.angleDeg*(M_PI/180);
    Vect offsetRotated = offset.rotate(angle);
    box.x = (box.center().x + offsetRotated.x)-box.w/2;
    box.y = (box.center().y + offsetRotated.y)-box.h/2;
    

}

bool Collider::Is (string type){
    if(type == "Collider")
        return true;
    return false;
}
void Collider::SetScale (Vect scale ){
    this -> scale = scale;
}
void Collider::SetOffset (Vect offset){
    this -> offset = offset;
}
void Collider::Start(){

}
bool Collider::IsColliding(Collider collidingRect){
    float angle1 = associated.angleDeg * (M_PI/180);
    float angle2 = collidingRect.associated.angleDeg * (M_PI/180);
    Rect box2 = collidingRect.box;
    return Collision::IsColliding(box,box2,angle1,angle2);
}
void Collider::NotifyCollision(GameObject& other){

}