#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <memory>
#include "Component.hpp"
#include "Rect.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Component;
class GameObject{
    private:
        vector<unique_ptr<Component>> components;
        bool isDead;
    public:
        double angleDeg;
        Rect box;
        GameObject();
        ~GameObject();
        void Update(float dt);
        void Render();
        bool IsDead();
        void RequestDelete();
        void AddComponent(Component *cpt);
        void RemoveComponent(Component *cpt);
        Component *GetComponent(string type);
        
        void NotifyCollision(GameObject& other);
        void Start();
        bool started;

};

#endif