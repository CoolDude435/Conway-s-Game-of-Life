#include "Map.h"

Map::Map() : m_height{}, m_width{}, m_mapData{} {}
Map::Map(int height, int width) : m_height{height}, m_width{width} {
    m_mapData = std::vector<std::vector<MapTile*>>(width,std::vector<MapTile*>(height,nullptr));
}

MapTile* Map::getMapTile(int x, int y) {
    if ((0<=x&&x<m_width)&&(0<=y<m_height)) {
        return m_mapData[x][y];
    } else {
        return nullptr;
    }
}