#ifndef CAMERA_HPP
#define CAMERA_HPP
#include <string>
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "Vect.hpp"
using namespace std;

class Camera{
    private:
        static GameObject *focus;
    public:
        static Vect pos;
        static Vect speed;
        static void Follow (GameObject* newFocus);
        static void Unfollow ();
        static void Update (float dt);
};


#endif