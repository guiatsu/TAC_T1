#ifndef COLLIDER_HPP
#define COLLIDER_HPP
#include <string>
#include "GameObject.hpp"
#include "Component.hpp"
#include "Vect.hpp"
#include <queue>
#include "InputManager.hpp"
using namespace std;

class Collider : public Component{
    public:
        Collider (GameObject& associated, Vect scale = {1, 1}, Vect offset = {0, 0});
        Rect box;
        void Update (float dt);
        void Render ();
        bool Is (string type);
        void SetScale (Vect scale );
        void SetOffset (Vect offset);
        void Start();
        bool IsColliding(Collider collidingRect);
        void NotifyCollision(GameObject& other);
    private:
        bool debug;
        Vect scale;
        Vect offset;
};





#endif