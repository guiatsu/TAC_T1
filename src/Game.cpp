#include "../include/Game.hpp"
    Game* Game::instance = nullptr;

    Game::Game(string title, int width, int height){
        if(instance != nullptr){
            cout << "algo ta estranho" << endl;
        }else{
            instance = this;
        }
        if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0){
            cout << SDL_GetError() << endl;
        }
        if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0){
            cout << "erro ao inicializar imagem" << endl;
        }

        if(Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3) == 0){
            cout << "erro ao inicializar o som" << endl;
        }
        if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024) != 0){
            cout << "erro ao abrir o audio" << endl;
        }
        Mix_AllocateChannels(32);
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,0);
        if(window == nullptr){
            cout << SDL_GetError() << endl;
        }
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        if(renderer == nullptr){
            cout << SDL_GetError() << endl;
        }
        srand(time(NULL));
        state = new State();
    }

    Game::~Game(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        Mix_CloseAudio();
        Mix_Quit();
        IMG_Quit();
        SDL_Quit();
    }
    SDL_Renderer *Game::GetRenderer(){
        return renderer;
    }
    State &Game::GetState(){
        return *state;
    }
    Game &Game::GetInstance()
    {
        if(instance != nullptr)
            return *instance;
        new Game("Yuri Crystian Ribeiro e Silva 180029479",1024,600);
        return *instance;
    }
    void Game::Run(){

        while(!state->QuitRequested()){
            state -> Update(0);
            state -> Render();
            SDL_RenderPresent(renderer);
            SDL_Delay(33);
        }
    }
