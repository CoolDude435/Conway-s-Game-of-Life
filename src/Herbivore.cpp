#include "Herbivore.h"

Herbivore::Herbivore() : Animal{} {}
Herbivore::Herbivore(int x, int y, char id, int maxEnergy) 
    : Animal{x, y, id, maxEnergy} {}