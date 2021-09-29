#include "../include/State.hpp"
State::State(){
	GameObject *go = new GameObject();

	GameObject *oceango = new GameObject();
    Sprite *bg = new Sprite(*oceango,"./assets/img/ocean.jpg");
	oceango -> AddComponent(bg);
    CameraFollower *CF = new CameraFollower(*oceango);
    oceango -> AddComponent(CF);

	oceango -> box.x = Camera::pos.x;
	oceango -> box.y = Camera::pos.y;
	objectArray.emplace_back(oceango);
	string path = "./assets/img/tileset.png";
	TileSet *tileset = new TileSet(64,64,path);
	path = "./assets/map/tileMap.txt";
	TileMap *tileMap = new TileMap(*go,path,tileset);
	go -> AddComponent(tileMap);
	go -> box.x = 0;
	go -> box.y = 0;
	objectArray.emplace_back(go);
    music = new Music("./assets/audio/stageState.ogg");

    // music ->Play();
    quitRequested = false;
}

void State::LoadAssets(){

}
void State::Render(){
	for(unsigned int i = 0 ; i < objectArray.size();i++){
        objectArray[i] -> Render();
    }
}
void State::Update(float dt){
	InputManager instance = InputManager::GetInstance();
	if(instance.KeyPress(ESCAPE_KEY) || instance.QuitRequested())
		quitRequested = true;
	if(instance.KeyPress(SPACEBAR)){
		Vect objPos = Vect( 200, 0 ).rotate( -M_PI + M_PI*(rand() % 1001)/500.0 ) + Vect( instance.GetMouseX(), instance.GetMouseY() );
		AddObject((int)objPos.x , (int)objPos.y);
	}
    Camera::Update(dt);

    for(unsigned int i = 0 ; i < objectArray.size();i++){
        objectArray[i] -> Update(dt);
    }
    for(unsigned int i = 0 ; i < objectArray.size();i++){
        if(objectArray[i] -> IsDead()){
	            objectArray.erase(objectArray.begin()+i);
        }
    }

}
bool State::QuitRequested(){
    return quitRequested;
}
State::~State(){
    objectArray.clear();
}

void State::AddObject(int mouseX, int mouseY){
    
    GameObject *go = new GameObject();
	string path = "./assets/img/penguinface.png";
    Sprite *img = new Sprite(*go,path);
    go -> AddComponent(img);
    go -> box.x = mouseX - go->box.w/2 + Camera::pos.x;
    go -> box.y = mouseY - go->box.h/2 + Camera::pos.y;
	path = "./assets/audio/boom.wav";
    Sound *snd = new Sound(*go,path);
    go -> AddComponent(snd);
    Face *face = new Face(*go);
    go -> AddComponent(face);
    objectArray.emplace_back(go);
}