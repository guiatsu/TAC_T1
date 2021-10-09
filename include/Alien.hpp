#ifndef ALIEN_HPP
#define ALIEN_HPP
#include <string>
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "Component.hpp"
#include "Vect.hpp"
#include "Sprite.hpp"
#include "Minion.hpp"
#include <queue>
using namespace std;
#define MV Action::ActionType::MOVE
#define SHT Action::ActionType::SHOOT

class Alien : public Component{
    private:
        class Action {
            public:
                enum ActionType{MOVE,SHOOT};
                Action(ActionType type, float x, float y);
                ActionType type;
                Vect pos;
        };
        Vect speed;
        int hp;
        int nMinions;
        queue<Action> taskQueue;
        vector<weak_ptr<GameObject>> minionArray;
    public:
        Alien(GameObject& associated, int nMinions);
        ~Alien();
        void Start();
        void Update(float dt);
        void Render();
        bool Is(string type);
        
};

#endif