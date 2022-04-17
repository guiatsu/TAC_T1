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
        frameStart = 0;
        dt = 0;
        srand(time(NULL));
        storedState = nullptr;
    }

    Game::~Game(){
        if(storedState != nullptr){
            delete(storedState);
        }
        while(!stateStack.empty())
            stateStack.pop();

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
    State &Game::GetCurrentState(){
        return *stateStack.top();
    }
    void Game::Push(State *state){
        storedState = state;
    }
    Game &Game::GetInstance()
    {
        if(instance != nullptr)
            return *instance;
        new Game("Yuri Crystian Ribeiro e Silva 180029479",1024,600);
        return *instance;
    }
    void Game::Run(){
        if(storedState != nullptr){
            stateStack.emplace(storedState);
            storedState = nullptr;
            stateStack.top() -> Start();
        }
        else{
            exit(0);
        }
        while(!stateStack.top()->QuitRequested() && !stateStack.empty()){
            if(stateStack.top()->QuitRequested()){
                stateStack.pop();
                if(!stateStack.empty()){
                    stateStack.top() -> Resume();
                }
            }
            if(storedState != nullptr){
                stateStack.top() -> Pause();
                stateStack.emplace(storedState);
                storedState = nullptr;
                stateStack.top() ->Start();
            }
            CalculateDeltaTime();
            InputManager::GetInstance().Update();
            stateStack.top() -> Update(dt);
            stateStack.top() -> Render();
            SDL_RenderPresent(renderer);
            SDL_Delay(16);
        }
        Resources::ClearImages();
        Resources::ClearSounds();
        Resources::ClearMusics();
    }
    void Game::CalculateDeltaTime(){
        int lastFrame = frameStart;
        frameStart = SDL_GetTicks ();
        dt = (frameStart - lastFrame)/1000.0;
    }
    float Game::GetDeltaTime(){
        return dt;
    }