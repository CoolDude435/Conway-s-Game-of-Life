#include "Carnivore.h"

Carnivore::Carnivore() : Animal{} {}
Carnivore::Carnivore(int x, int y, char id, int maxEnergy) 
    : Animal{x, y, id, maxEnergy} {}