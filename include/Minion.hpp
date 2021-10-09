#ifndef MINION_HPP
#define MINION_HPP
#include <string>
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "Vect.hpp"
#include "Component.hpp"
#include "Sprite.hpp"
#include "GameObject.hpp"
#include "Bullet.hpp"
#include <memory>
using namespace std;

class Minion : public Component{
    private:
        weak_ptr<GameObject> alienCenter;
        float arc;
        
    public:
        Minion(GameObject &associated, weak_ptr<GameObject> alienCenter, float arcOffsetDeg = 0);
        void Update(float dt);
        void Render();
        bool Is(string type);
        void Shoot(Vect target);
        void Start();
};


#endif