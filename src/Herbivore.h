#pragma once
#include "Animal.h"

class Herbivore : public Animal
{
    private:

    public:
        Herbivore();
        Herbivore(int x, int y, char id, int maxEnergy);
        Herbivore* clone() const;
        SpeciesType getSpeciesType() override;
        void wasEaten();
};