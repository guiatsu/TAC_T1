#include "../include/TileMap.hpp"
#include <regex>
vector<string> split_string(string line, string delimiter){
	regex space("[^"+delimiter+"]+");
	vector<string> splitted_line;
	auto line_begin = sregex_iterator(line.begin(),line.end(),space);
	auto line_end = sregex_iterator();
	for(sregex_iterator j = line_begin; j != line_end; j++){
		smatch match = *j;
		splitted_line.push_back(match.str());
	}
	return splitted_line;
}

TileMap::TileMap(GameObject &associated, string file, TileSet *tileSet) : Component(associated){
    this -> tileSet = tileSet;
    Load(file);
}

void TileMap::Load(string file){
    fstream File;
    File.open(file,ios::in);
    string line;
    getline(File,line);
    vector<string> splitted_line = split_string(line,",");
    mapWidth = stoi(splitted_line[0]);
    mapHeight = stoi(splitted_line[1]);
    mapDepth = stoi(splitted_line[2]);
    while(getline(File,line)){
        if(line != ""){
            splitted_line = split_string(line,",");
            for(unsigned i = 0; i < splitted_line.size();i++){
                tileMatrix.push_back(stoi(splitted_line[i])-1);
            }
        }
    }
    File.close();
}
void TileMap::SetTileSet(TileSet *tileSet){
    this -> tileSet = tileSet;
}

int &TileMap::At(int x, int y, int z){
    return tileMatrix.at( x + (y*mapWidth) + (z*mapHeight*mapWidth));
}
void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
    for(int i = 0; i < mapHeight;i++){
        for(int j = 0; j < mapWidth;j++){
            int x = j * tileSet -> GetTileWidth()-cameraX;
            int y = i * tileSet -> GetTileHeight()-cameraY;
            tileSet -> RenderTile(At(j,i,layer),x,y);
        }
    }
    
}
void TileMap::Render(){
    for(int i = 0; i < mapDepth;i++)
        RenderLayer(i,Camera::pos.x*(1+(i*0.50)), Camera::pos.y*(1+(i*0.50)));
}
int TileMap::GetWidth(){
    return mapWidth;
}
int TileMap::GetHeight(){
    return mapHeight;
}
int TileMap::GetDepth(){
    return mapDepth;
}
void TileMap::Update(float dt)  {

}
bool TileMap::Is(string type) {
    if(type == "TileMap")
        return true;
    return false;
}
void TileMap::Start(){

}