#ifndef RECT_HPP
#define RECT_HPP
#include "Vect.hpp"
class Rect{
    public:
    float x,y,w,h;
    Rect();
    Rect(float x, float y, float w, float h);
    Rect operator+(Vect vect);
    friend Rect operator+(Vect vect,Rect rect);
    Vect center();
    bool is_in(Vect vect);
};

#endif