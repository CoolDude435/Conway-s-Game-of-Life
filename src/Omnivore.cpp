#include "Omnivore.h"

Omnivore::Omnivore() : Animal{} {}
Omnivore::Omnivore(int x, int y, char id, int maxEnergy) 
    : Animal{x, y, id, maxEnergy} {}

Omnivore* Omnivore::clone() {
    return new Omnivore(getX(),getY(),getID(),getMaxEnergy());
}
SpeciesType Omnivore::getSpeciesType() { return omnivore; }

bool Omnivore::canConsume(Herbivore* herbivore) {
    if ((this->getEnergy()+herbivore->getEnergy()-1)<=this->getMaxEnergy()) {
        return true;
    } else {
        return false;
    }
}