#include "Herbivore.h"

Herbivore::Herbivore() : Animal{} {}
Herbivore::Herbivore(int x, int y, char id, int maxEnergy) 
    : Animal{x, y, id, maxEnergy} {}

Herbivore* Herbivore::clone() {
    return new Herbivore(getX(),getY(),getID(),getMaxEnergy());
}
SpeciesType Herbivore::getSpeciesType() { return herbivore; }
void Herbivore::takeTurn() {}