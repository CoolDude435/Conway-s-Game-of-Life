#include "Omnivore.h"

Omnivore::Omnivore() : Animal{} {}
Omnivore::Omnivore(int x, int y, char id, int maxEnergy) 
    : Animal{x, y, id, maxEnergy} {}