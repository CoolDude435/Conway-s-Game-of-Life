#include "Omnivore.h"

Omnivore::Omnivore() : Animal{} {}
Omnivore::Omnivore(int x, int y, char id, int maxEnergy) 
    : Animal{x, y, id, maxEnergy} {}

Omnivore* Omnivore::clone() const {
    return new Omnivore(getX(),getY(),getID(),getMaxEnergy());
}
SpeciesType Omnivore::getSpeciesType() { return omnivore; }

bool Omnivore::canConsume(Animal* animal) const {
    //check if it can consume a herbivore without going over m_maxEnergy
    if (animal->getSpeciesType()==herbivore) {
        if ((this->getEnergy()+animal->getEnergy()-1)<=this->getMaxEnergy()) {
            return true;
        }
    }
    return false;
}

void Omnivore::eat(Herbivore* herbivore) {
    int energy = getEnergy()+herbivore->getEnergy();
    setEnergy(energy);
    herbivore->wasEaten();
}