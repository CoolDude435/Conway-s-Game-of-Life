#pragma once

#include "Plant.h"
#include "Animal.h"

class MapTile
{
    private:
        int m_x{};
        int m_y{};
        Plant* m_plant{};
        Animal* m_animal{};
    
    public:
        MapTile();
        MapTile(int x, int y, Plant* plant, Animal* animal);
        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);
        bool hasPlant();
        bool hasAnimal();
        Plant* getPlant();
        Animal* getAnimal();
        void setPlant(Plant* plant);
        void setAnimal(Animal* animal);
};