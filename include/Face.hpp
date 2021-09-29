#ifndef FACE_HPP
#define FACE_HPP
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "Sound.hpp"
#include "Camera.hpp"
class Face : public Component{
    public:
        Face(GameObject &associated);
        void Damage(int damage);
        void Update(float dt);
        void Render();
        bool Is(string type);
    private:
    int hitpoints;

};









#endif