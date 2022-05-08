#include "../include/TitleState.hpp"
#include "../include/StageState.hpp"
#include "../include/Game.hpp"

TitleState::TitleState(){
    GameObject *go = new GameObject();
    Sprite *title = new Sprite(*go, "./assets/img/title.jpg");
    go ->AddComponent(title);
    objectArray.emplace_back(go);

}
void TitleState::Start(){
}

void TitleState::LoadAssets(){
}
void TitleState::Render(){
    RenderArray();
}
void TitleState::Update(float dt){
    
	InputManager instance = InputManager::GetInstance();
	if(instance.KeyPress(ESCAPE_KEY) || instance.QuitRequested())
		quitRequested = true;
    if(instance.KeyPress(SPACEBAR)){
        Game::GetInstance().Push(new StageState());
    }


}
TitleState::~TitleState(){
    objectArray.clear();
}
void TitleState::Resume() {

}

void TitleState::Pause() {
}