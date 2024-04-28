#include "MapTile.h"
#include <iostream>

MapTile::MapTile() 
    : Entity{}, m_plant{nullptr}, m_animal{nullptr} {}
MapTile::MapTile(int x, int y, Plant* plant, Animal* animal) 
    : Entity{x,y}, m_plant{plant}, m_animal{animal} {}

bool MapTile::hasPlant() { return m_plant; }
bool MapTile::hasAnimal() { return m_animal; }

Plant* MapTile::getPlant() { return m_plant; }
Animal* MapTile::getAnimal() { return m_animal; }

void MapTile::setPlant(Plant* plant) {
    if (this->hasPlant()) {
        //for testing purposes, this should be checked by the caller
        std::cerr << "Can't set a plant on a tile already with a plant.\n";
    } else {
        m_plant = plant;
    }
}
void MapTile::setAnimal(Animal* animal) {
    if (this->hasAnimal()) {
        //for testing purposes, this should be checked by the caller
        std::cerr << "Can't set an animal on a tile already with an animal.\n";
    } else {
        m_animal = animal;
    }
}