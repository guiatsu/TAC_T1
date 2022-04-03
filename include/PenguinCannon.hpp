#ifndef PENGUINCANNON_HPP
#define PENGUINCANNON_HPP
#include <string>
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "Component.hpp"
#include "Vect.hpp"
#include "Sprite.hpp"
#include <queue>
#include "Collider.hpp"
#include "Timer.hpp"
#include "Sound.hpp"
using namespace std;

class PenguinCannon : public Component{
    public:
    PenguinCannon(GameObject &associated,weak_ptr<GameObject>);
    void Update(float dt);
    void Render();
    void Start();
    bool Is(string type);
    void Shoot();
    void NotifyCollision(GameObject& other);
    private:
    float angle;
    weak_ptr<GameObject> pbody;
    Timer *timer;
};





#endif