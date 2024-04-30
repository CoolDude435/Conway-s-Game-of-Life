#include "Animal.h"


Animal::Animal()
    : Organism{}, m_energy{}, m_maxEnergy{} {}
Animal::Animal(int x, int y, char id, int maxEnergy)
    : Organism{x,y,id}, m_energy{maxEnergy}, m_maxEnergy{maxEnergy} {}

int Animal::getEnergy() const { return m_energy; }
int Animal::getMaxEnergy() const { return m_maxEnergy; }
bool Animal::canConsume(Plant* plant) {
    if ((m_energy+plant->getEnergyPts()-1)<=m_maxEnergy) {
        return true;
    } else {
        return false;
    }
}




void Animal::moveNorth() {
    setY(getY()-1);
    m_energy--;
}
void Animal::moveSouth() {
    setY(getY()+1);
    m_energy--;
}
void Animal::moveWest() {
    setX(getX()-1);
    m_energy--;
}
void Animal::moveEast() {
    setX(getX()+1);
    m_energy--;
}