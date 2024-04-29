#pragma once
#include "Animal.h"

class Herbivore : public Animal
{
    private:

    public:
        Herbivore();
        Herbivore(int x, int y, char id, int maxEnergy);
        Herbivore* clone();
        SpeciesType getSpeciesType() override;
        void takeTurn() override;
};