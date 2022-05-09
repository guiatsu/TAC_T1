#include "../include/StageState.hpp"
#include "../include/Game.hpp"
#include "../include/EndState.hpp"
StageState::StageState(){
	BackgroundMusic = nullptr;
    tileSet = nullptr;
    quitRequested = false;
    started = false;
    GameData::playerVictory = false;

}
void StageState::Start(){
    LoadAssets();
    for (unsigned int i = 0; i < objectArray.size(); i++) {
		objectArray[i]->Start();
	}
	started = true;
}

void StageState::LoadAssets(){
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
    BackgroundMusic = new Music("./assets/audio/stageState.ogg");
    BackgroundMusic ->Volume(10);
    GameObject *AlienGo = new GameObject();
    AlienGo -> box.y = 100 - AlienGo -> box.h/2;
    AlienGo -> box.x = 312 - AlienGo -> box.w/2;
    Alien *alien = new Alien(*AlienGo,5);
    AlienGo -> AddComponent(alien);
    
    objectArray.emplace_back(AlienGo);

    AlienGo = new GameObject();
    AlienGo -> box.y = 512 - AlienGo -> box.h/2;
    AlienGo -> box.x = 0 - AlienGo -> box.w/2;
    alien = new Alien(*AlienGo,5,0.25);
    AlienGo -> AddComponent(alien);
    
    objectArray.emplace_back(AlienGo);

    AlienGo = new GameObject();
    AlienGo -> box.y = 1080 - AlienGo -> box.h/2;
    AlienGo -> box.x = 452 - AlienGo -> box.w/2;
    alien = new Alien(*AlienGo,5,0.5);
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

    BackgroundMusic ->Play();
}
void StageState::Render(){
	for(unsigned int i = 0 ; i < objectArray.size();i++){
        objectArray[i] -> Render();
    }
}
void StageState::Update(float dt){
    if(PenguinBody::player == nullptr){
        GameData::playerVictory = false;
        BackgroundMusic->Stop();
        popRequested = true;
        Game::GetInstance().Push(new EndState());
    }
    else if(Alien::aliencount == 0){
        GameData::playerVictory = true;
        BackgroundMusic->Stop();
        popRequested = true;
        Game::GetInstance().Push(new EndState());
    }
    else{
        InputManager instance = InputManager::GetInstance();
        if(instance.KeyPress(ESCAPE_KEY) || instance.QuitRequested()){
            popRequested = true;
            BackgroundMusic->Stop();
            Camera::Unfollow();
            Camera::pos = Vect(0,0);
        }
        Camera::Update(dt);
        for(unsigned int i = 0 ; i < objectArray.size();i++){
            objectArray[i] -> Update(dt);
        }
        for(unsigned int i = 0 ; i < objectArray.size();i++){
            Collider *collider = (Collider *)objectArray[i] -> GetComponent("Collider");
            if(collider == nullptr)
                continue;
            for (unsigned int j = i+1; j < objectArray.size(); j++){
                Collider *collider2 = (Collider *)objectArray[j] -> GetComponent("Collider");
                if(collider2 == nullptr)
                    continue;
                if(collider ->IsColliding(*collider2)){
                    objectArray[i] ->NotifyCollision(*objectArray[j]);
                    objectArray[j] ->NotifyCollision(*objectArray[i]);
                }
            }
        }
        
        for(unsigned int i = 0, j = objectArray.size() ; i < j;i++){
            if(objectArray[i] -> IsDead()){
                objectArray.erase(objectArray.begin()+i);
                i--;
                j--;
            }
        }
    }
    

}
StageState::~StageState(){
    objectArray.clear();
}
void StageState::Resume() {

}

void StageState::Pause() {
}