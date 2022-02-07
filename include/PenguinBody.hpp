#ifndef PENGUINBODY_HPP
#define PENGUINBODY_HPP
#include <string>
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "Component.hpp"
#include "Vect.hpp"
#include "Sprite.hpp"
#include <queue>
using namespace std;

class PenguinBody : public Component{
    public:
    PenguinBody(GameObject &associated);
    ~PenguinBody();
    void Start();
    void Update(float dt);
    void Render();
    bool Is(string type);
    static PenguinBody *player;
    private:
    weak_ptr<GameObject> pcannon;
    Vect speed;
    float linearSpeed;
    float angle;
    int hp;
};





#endif