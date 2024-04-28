#pragma once

#include <vector>
#include "MapTile.h"
#include <iostream>

class Map
{
    private:
        int m_height{};
        int m_width{};
        std::vector<std::vector<MapTile*>> m_mapData{};
    public:
        Map();
        Map(int height, int width);
        MapTile* getTile(int x, int y) const;
        int getWidth() const;
        int getHeight() const;
        void print() const;
};