#include "Game.hpp"

    Game::Game(string title, int width, int height){
        if(instance != nullptr){
            instance = this;
        }
        state = new State();
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,0);
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    }

    Game::~Game(){
        // SDL_Music(Mix_CloseAudio);
        // SDL_Music(Mix_Quit);
        // SDL_image (IMG_Quit);
    };
    SDL_Renderer *Game::GetRenderer(){
        return renderer;
    };
    State &Game::GetState(){
        return *state;
    };
    Game &Game::GetInstance()
    {
        if(instance != nullptr)
            return *instance;
        Game("joguinho",1280,720);
        return *instance;
    };
    void Game::Run(){
        while(!GetState().QuitRequested()){
            SDL_Delay(33);
            cout << "rodando" << endl;
        }
    }
