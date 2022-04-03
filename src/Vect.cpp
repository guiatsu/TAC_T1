#include "../include/Vect.hpp"

Vect::Vect(){

}
Vect::Vect(float x, float y){
    this -> x = x;
    this -> y = y;
}
Vect Vect::operator+(Vect vect){
    return Vect(this->x+vect.x,this->y+vect.y);
}
Vect Vect::operator-(Vect vect){
    return Vect(this->x-vect.x,this->y-vect.y);
}
Vect Vect::operator* (float escalar){
    return Vect(this->x*escalar,this->y*escalar);
}
float Vect::magnitude(){
    return sqrt(pow(this -> x,2) + pow(this -> y,2));
}
Vect Vect::operator+=(Vect vect){
    *this = Vect(this->x+vect.x,this->y+vect.y);
    return *this;
}
Vect Vect::normalized(){
    if(this -> x != 0 && this -> y != 0)
        return Vect(this -> x/this -> magnitude(), this -> y / this -> magnitude());
    return *this;
}
float Vect::dist(Vect &vect){
    return (*this - vect).magnitude();
}
float Vect::anglex(){
    return atan2(this->y,this->x);
}
float Vect::anglex2(Vect &vect){
    Vect aux = (vect-*this);
    return atan2(aux.y,aux.x);
}
Vect Vect::rotate(float angle){
    Vect aux;
    float cosx = cos(angle);
    float sinx = sin(angle);
    aux.x = (this -> x * cosx) - (this -> y * sinx);
    aux.y = (this -> y * cosx) + (this -> x * sinx);
    return aux;
}
Vect operator*(float escalar, Vect &vect){
    return Vect(vect.x*escalar,vect.y*escalar);
}
Vect operator*(Vect const &vect,float escalar){
    return Vect(vect.x*escalar,vect.y*escalar);
}