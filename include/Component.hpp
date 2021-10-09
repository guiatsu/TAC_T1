#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include <string>
#include "GameObject.hpp"
using namespace std;
class GameObject;
class Component{
    public:
        Component(GameObject &associated);
        virtual ~Component();
        void virtual Update(float dt) = 0;
        void virtual Render() = 0;
        bool virtual Is(string type) = 0; 
        void virtual Start() = 0;
    protected:
        GameObject &associated;
};










#endif