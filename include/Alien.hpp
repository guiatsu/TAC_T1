#ifndef ALIEN_HPP
#define ALIEN_HPP
#include <string>
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "Component.hpp"
#include "Vect.hpp"
#include "Sprite.hpp"
#include "Minion.hpp"
#include "Collider.hpp"
#include <queue>
#include "PenguinBody.hpp"
using namespace std;
#define MV AlienState::MOVING
#define RST AlienState::RESTING

class Alien : public Component{
    private:
        enum AlienState{MOVING,RESTING};
        AlienState state;
        Timer *rest;
        Vect destination;
        Vect speed;
        int hp;
        int nMinions;
        vector<weak_ptr<GameObject>> minionArray;
        float timeOffset;
    public:
        static bool canMove;
        static int aliencount;
        Alien(GameObject& associated, int nMinions,float timeOffset = 0);
        ~Alien();
        void Start();
        void Update(float dt);
        void Render();
        bool Is(string type);
        int ClosestMinion(Vect pos);
        void NotifyCollision(GameObject& other);
        
};

#endif