#include "../include/Game.hpp"
#include <iostream>
int main(int argc, char** argv)
{
    Game game = Game::GetInstance();
    game.Run();
    return 0;
}
