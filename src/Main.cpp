#include "../include/Game.hpp"
#include <iostream>
int main(int argc, char** argv)
{
    Game::GetInstance().Push(new TitleState());
	Game::GetInstance().Run();

    return 0;
}
