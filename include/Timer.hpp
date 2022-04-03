#ifndef TIMER_HPP
#define TIMER_HPP
#include <string>

using namespace std;


class Timer {
    public:
        Timer();
        void Update(float dt);
        void Restart();
        float Get();
    private:
        float time;
            
};

#endif