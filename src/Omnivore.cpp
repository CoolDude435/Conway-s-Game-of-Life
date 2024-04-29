#include "Omnivore.h"

Omnivore::Omnivore() : Animal{} {}
Omnivore::Omnivore(int x, int y, char id, int maxEnergy) 
    : Animal{x, y, id, maxEnergy} {}

Omnivore* Omnivore::clone() {
    return new Omnivore(getX(),getY(),getID(),getMaxEnergy());
}
SpeciesType Omnivore::getSpeciesType() { return omnivore; }
void Omnivore::takeTurn() {}