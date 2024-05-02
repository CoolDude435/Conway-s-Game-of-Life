#pragma once

#include "Animal.h"
#include "Herbivore.h"

class Omnivore : public Animal
{
    private:

    public:
        Omnivore();
        Omnivore(int x, int y, char id, int maxEnergy);
        Omnivore* clone();
        SpeciesType getSpeciesType() override;
        bool canConsume(Animal* animal);
        void eat(Herbivore* herbivore);

};