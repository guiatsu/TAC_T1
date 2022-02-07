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

    GameObject *AlienGo = new GameObject();
    AlienGo -> box.y = 300 - AlienGo -> box.h/2;
    AlienGo -> box.x = 512 - AlienGo -> box.w/2;
    Alien *alien = new Alien(*AlienGo,5);
    AlienGo -> AddComponent(alien);
    
    objectArray.emplace_back(AlienGo);
    // Camera::Follow(AlienGo);
    GameObject *PenguinGo = new GameObject();
    PenguinGo -> box.y = 704 - PenguinGo -> box.h/2;
    PenguinGo -> box.x = 640 - PenguinGo -> box.w/2;
    PenguinBody *penguin = new PenguinBody(*PenguinGo);
    PenguinGo -> AddComponent(penguin);
    Camera::Follow(PenguinGo);

    objectArray.emplace_back(PenguinGo);

    music ->Play();
    quitRequested = false;
    started = false;

}
void State::Start(){
    LoadAssets();
    for(unsigned int i = 0; i < objectArray.size();i++){
        objectArray[i] -> Start();
    }
    started = true;
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

weak_ptr<GameObject> State::AddObject(GameObject *go){
    
    shared_ptr<GameObject> shrd_go(go);
    objectArray.push_back(shrd_go);
    if(started == true){
        shrd_go -> Start();
    }
    weak_ptr<GameObject> weak_go(shrd_go);
    return weak_go;

}
weak_ptr<GameObject> State::GetObjectPtr(GameObject *go){
    for(unsigned int i = 0; i < objectArray.size();i++){
        if(objectArray[i].get() == go){
            weak_ptr<GameObject> weak_go(objectArray[i]);
            return weak_go;
        }
    }
    return {};
}