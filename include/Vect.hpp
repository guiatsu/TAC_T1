#ifndef VECT_HPP
#include <math.h>

class Vect{
    public:
    float x,y;
    Vect();
    Vect(float x, float y);
    Vect operator+ (Vect vect);
    Vect operator- (Vect vect);
    Vect operator* (float escalar);
    friend Vect operator*(float escalar, Vect &vect);
    float magnitude();
    float dist(Vect &vect);
    float anglex();
    float anglex2(Vect &vect);
    Vect rotate(float angle);
};

#endif