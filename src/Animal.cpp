#include "Animal.h"

Animal::Animal()
    : Organism{}, m_energy{}, m_maxEnergy{} {}
Animal::Animal(int x, int y, char id, int maxEnergy)
    : Organism{x,y,id}, m_energy{maxEnergy}, m_maxEnergy{maxEnergy} {}

int Animal::getEnergy() { return m_energy; }
int Animal::getMaxEnergy() { return m_maxEnergy; }

Animal* Animal::clone() {
    return new Animal(getX(),getY(),getID(),getMaxEnergy());
}

bool moveNorth() {
    //WIP
    return false;
}
bool moveSouth() {
    //WIP
    return false;
}
bool moveWest() {
    //WIP
    return false;
}
bool moveEast() {
    //WIP
    return false;
}