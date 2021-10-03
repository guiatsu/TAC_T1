#ifndef CAMERAFOLLOWER_HPP
#define CAMERAFOLLOWER_HPP
#include <string>
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "Vect.hpp"
#include "Camera.hpp"
#include "Sprite.hpp"
using namespace std;

class CameraFollower : public Component{
    public:
        CameraFollower (GameObject &go);
        void Update (float dt);
        void Render ();
        bool Is (string type);
};


#endif