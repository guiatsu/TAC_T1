#ifndef TILEMAP_HPP
#define TILEMAP_HPP
#define INCLUDE_SDL
#include "Component.hpp"
#include "TileSet.hpp"
#include "Camera.hpp"
#include <fstream>

class TileMap : public Component {
    public:
        TileMap(GameObject &associated, string file, TileSet *tileSet);
        void Load(string file);
        void SetTileSet(TileSet *tileSet);
        int &At(int x, int y, int z = 0);
        void Render();
        void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
        int GetWidth();
        int GetHeight();
        int GetDepth();
        void Update(float dt);
        bool Is(std::string type);
    private:
        vector<int> tileMatrix;
        TileSet *tileSet;
        int mapWidth;
        int mapHeight;
        int mapDepth;
};

#endif