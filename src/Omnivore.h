#pragma once

#include "Animal.h"
#include "Herbivore.h"

class Omnivore : public Animal
{
    private:

    public:
        Omnivore();
        Omnivore(int x, int y, char id, int maxEnergy);
        Omnivore* clone() const;
        SpeciesType getSpeciesType() override;
        bool canConsume(Animal* animal) const;
        void eat(Herbivore* herbivore);

};