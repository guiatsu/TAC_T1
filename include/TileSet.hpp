#ifndef TILESET_HPP
#define TILESET_HPP
#define INCLUDE_SDL
#include "Sprite.hpp"
#include <iostream>
using namespace std;

class TileSet{
    private:
        Sprite *tileSet;
        int rows;
        int columns;
        int tileWidth;
        int tileHeight;
    public:
        TileSet(int tileWidth, int tileHeight, string file);
        void RenderTile(int index,float x, float y);
        int GetTileWidth();
        int GetTileHeight();   
};

#endif