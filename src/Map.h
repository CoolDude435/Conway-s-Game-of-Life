#pragma once

#include <vector>
#include "MapTile.h"

class Map
{
    private:
        int m_height{};
        int m_width{};
        std::vector<std::vector<MapTile*>> m_mapData{};
    public:
        Map();
        Map(int height, int width);
        MapTile* getMapTile(int x, int y);
        
};