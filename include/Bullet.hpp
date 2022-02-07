#ifndef BULLET_HPP
#define BULLET_HPP
#include <string>
#include "Component.hpp"
#include "Vect.hpp"
#include "Sprite.hpp"
#include "GameObject.hpp"
using namespace std;

class Bullet : public Component {
    private:
        Vect speed;
        float distanceLeft;
        int damage;
    public:
        Bullet(GameObject &associated, float angle, float speed, int damage, float maxDistance, string sprite,int frameCount = 1);
        int GetDamage();
        bool Is(string type);
        void Render();
        void Update (float dt);
        void Start();
};


#endif