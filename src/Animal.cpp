#include "Animal.h"

Animal::Animal()
    : Organism{}, m_energy{}, m_maxEnergy{} {}
Animal::Animal(int x, int y, char id, int maxEnergy)
    : Organism{x,y,id}, m_energy{maxEnergy}, m_maxEnergy{maxEnergy} {}

int Animal::getEnergy() const { return m_energy; }
int Animal::getMaxEnergy() const { return m_maxEnergy; }




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