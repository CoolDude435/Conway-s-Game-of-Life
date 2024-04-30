#include "MapTile.h"
#include <iostream>

MapTile::MapTile() 
    : m_x{}, m_y{}, m_plant{nullptr}, m_animal{nullptr} {}
MapTile::MapTile(int x, int y, Plant* plant, Animal* animal) 
    : m_x{x}, m_y{y}, m_plant{plant}, m_animal{animal} {}

int MapTile::getX() const { return m_x; }
int MapTile::getY() const { return m_y; }
void MapTile::setX(int x) { m_x = x; }
void MapTile::setY(int y) { m_y = y; } 

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