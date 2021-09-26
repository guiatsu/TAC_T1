#include "../include/TileSet.hpp"

TileSet::TileSet(int tileWidth,int tileHeight, string file){
    this -> tileHeight = tileHeight;
    this -> tileWidth = tileWidth;
    
    GameObject *go = new GameObject();
    this -> tileSet = new Sprite(*go,file);
    if (this -> tileSet -> IsOpen()){
        this -> rows = this -> tileSet -> GetHeight() / tileHeight;
        this -> columns = this -> tileSet -> GetWidth() / tileWidth;
    }
}
void TileSet::RenderTile(int index, float x, float y){
    if(index >= 0 && index <= (rows*columns)){
        int trueX = (index%columns) * tileWidth;
        int trueY = (index/columns) * tileHeight;
        tileSet -> SetClip(trueX,trueY, tileWidth, tileHeight);
        tileSet -> Render(x,y);
    }
}
int TileSet::GetTileHeight(){
    return tileHeight;
}
int TileSet::GetTileWidth(){
    return tileWidth;
}

