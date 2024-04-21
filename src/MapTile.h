#pragma once

#include "Plant.h"
#include "Animal.h"
#include "Entity.h"

class MapTile : public Entity
{
    private:
        Plant* m_plant{};
        Animal* m_animal{};
    
    public:
        MapTile();
        MapTile(int x, int y, Plant* plant, Animal* animal);
        bool hasPlant();
        bool hasAnimal();
        Plant* getPlant();
        Animal* getAnimal();
        void setPlant(Plant* plant);
        void setAnimal(Animal* animal);
};