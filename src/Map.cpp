#include "Map.h"

Map::Map() : m_height{}, m_width{}, m_mapData{} {}
Map::Map(int height, int width) : m_height{height}, m_width{width} {
    m_mapData = std::vector<std::vector<MapTile*>>(height,std::vector<MapTile*>(width,nullptr));
    for (int i=0;i<m_height;i++) {
        for (int j=0;j<m_width;j++) {
            m_mapData[i][j] = new MapTile(j,i,nullptr,nullptr);
            //setting up empty MapTiles with correct xy-coordinates
        }
    }
}

MapTile* Map::getTile(int x, int y) {
    if ((0<=x&&x<m_width)&&(0<=y&&y<m_height)) { //check if out of bounds
        return m_mapData[y][x];
    } else {
        return nullptr; // returns nullptr if out of bounds
    }
}
std::vector<MapTile*> Map::getAdjacent(int x,int y) {
    //returns a vector of existing adjacent tiles to a spot
    std::vector<MapTile*> adjacent{};
    MapTile* n = getTile(x,y-1);
    if (n) { adjacent.push_back(n); }
    MapTile* w = getTile(x-1,y);
    if (w) { adjacent.push_back(w); }
    MapTile* s = getTile(x,y+1);
    if (s) { adjacent.push_back(s); }
    MapTile* e = getTile(x+1,y);
    if (e) { adjacent.push_back(e); }
    return adjacent;
}

int Map::getWidth() const { return m_width; }
int Map::getHeight() const { return m_height; }

void Map::print() const { 
    //prints out the map, chars represent an Organism in that tile
    for (int i=0;i<m_width;i++) { std::cout << '-'; }
    std::cout << '\n';
    for (int i=0;i<m_height;i++) {
        for (int j=0;j<m_width;j++) {
            MapTile* tile = m_mapData[i][j];
            if (tile->hasAnimal()) {
                Animal* animal = tile->getAnimal();
                std::cout << animal->getID();
            } else if (tile->hasPlant()&&(tile->getPlant()->isEaten()==false)) {
                Plant* plant = tile->getPlant();
                std::cout << plant->getID();
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
    for (int i=0;i<m_width;i++) { std::cout << '-'; }
    std::cout << '\n';
}