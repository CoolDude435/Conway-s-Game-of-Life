#pragma once

#include <vector>
#include "Organism.h"

class Map
{
    private:
        int m_height{};
        int m_width{};
        std::vector<std::vector<Entity*>> m_mapData{};
    public:
        Map();
        Map(int height, int width);
        
};