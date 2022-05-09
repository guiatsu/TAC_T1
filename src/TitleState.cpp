#include "../include/TitleState.hpp"
#include "../include/StageState.hpp"
#include "../include/Game.hpp"

TitleState::TitleState(){
    GameObject *go = new GameObject();
    Sprite *title = new Sprite(*go, "./assets/img/title.jpg");
    go->box.x = go->box.y = 0;
    go ->AddComponent(title);
    objectArray.emplace_back(go);
    GameObject *goText = new GameObject();
    SDL_Color color = {0,0,0,255};
    Text *text = new Text(*goText,"./assets/font/Call me maybe.ttf",20,Text::BLENDED,"Pressione espaco para iniciar", color,0.5);
    goText -> AddComponent(text);
    objectArray.emplace_back(goText);
    goText-> box.x = 405;
    goText-> box.y = 500;
    
    

}
void TitleState::Start(){
}

void TitleState::LoadAssets(){
}
void TitleState::Render(){
    Camera::pos = Vect(0,0);
    RenderArray();
}
void TitleState::Update(float dt){
    
	InputManager instance = InputManager::GetInstance();
	if(instance.KeyPress(ESCAPE_KEY) || instance.QuitRequested())
		quitRequested = true;
    if(instance.KeyPress(SPACEBAR)){
        Game::GetInstance().Push(new StageState());
    }
    UpdateArray(dt);


}
TitleState::~TitleState(){
    objectArray.clear();
}
void TitleState::Resume() {

}

void TitleState::Pause() {
}