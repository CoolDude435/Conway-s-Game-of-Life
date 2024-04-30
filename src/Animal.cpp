#include "Animal.h"

Animal::Animal()
    : Organism{}, m_energy{}, m_maxEnergy{} {}
Animal::Animal(int x, int y, char id, int maxEnergy)
    : Organism{x,y,id}, m_energy{maxEnergy}, m_maxEnergy{maxEnergy} {}

int Animal::getEnergy() const { return m_energy; }
int Animal::getMaxEnergy() const { return m_maxEnergy; }




void Animal::moveNorth() {
    setY(getY()-1);
}
void Animal::moveSouth() {
    setY(getY()+1);
}
void Animal::moveWest() {
    setX(getX()-1);
}
void Animal::moveEast() {
    setX(getX()+1);
}