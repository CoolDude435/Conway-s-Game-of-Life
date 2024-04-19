#pragma once
#include "Animal.h"

class Omnivore : public Animal
{
    private:

    public:
        Omnivore();
        Omnivore(int x, int y, char id, int maxEnergy);
};