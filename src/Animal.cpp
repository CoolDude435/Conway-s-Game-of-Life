#include "Animal.h"


Animal::Animal()
    : Organism{}, m_energy{}, m_maxEnergy{} {}
Animal::Animal(int x, int y, char id, int maxEnergy)
    : Organism{x,y,id}, m_energy{maxEnergy}, m_maxEnergy{maxEnergy} {}

int Animal::getEnergy() const { return m_energy; }
int Animal::getMaxEnergy() const { return m_maxEnergy; }
void Animal::setEnergy(int energy) { m_energy = energy; }

bool Animal::canConsume(Plant* plant) const {
    if ((m_energy+plant->getEnergyPts()-1)<=m_maxEnergy) {
        //check if it can eat a Plant without going over m_maxEnergy
        return true;
    } else {
        return false;
    }
}
void Animal::eat(Plant* plant) {
    m_energy = m_energy+plant->getEnergyPts();
    plant->wasEaten(); //tells the plant it was eaten
}

bool Animal::isDead() { return m_energy==0; }
