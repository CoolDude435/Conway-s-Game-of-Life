#pragma once
#include "Animal.h"

class Carnivore : public Animal
{
    private:

    public:
        Carnivore();
        Carnivore(int x, int y, char id, int maxEnergy);
};