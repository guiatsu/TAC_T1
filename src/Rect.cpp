#include "../include/Rect.hpp"

Rect::Rect(){

}
Rect::Rect(float x, float y, float w, float h){
    this -> x = x;
    this -> y = y;
    this -> w = w;
    this -> h = h;
}
Rect Rect::operator+(Vect vect){
    return Rect(this -> x + vect.x, this -> y + vect.y, this -> w, this -> h);
}
Rect operator+(Vect vect, Rect rect){
    return Rect(rect.x + vect.x, rect.y + vect.y, rect.w, rect.h);
}
Vect Rect::center(){
    return Vect((this -> x + this -> w/2), (this -> h/2 + this -> y));
}
bool Rect::contains(Vect vect){
    if( 
        ((vect.x > this -> x) && (vect.x < (this -> x + this -> w))) &&
        ((vect.y > this -> y) && (vect.y < (this -> y + this -> h)))
    ){
        return true;
    }
    return false;
}