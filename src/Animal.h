#pragma once

#include "Organism.h"
#include "Plant.h"

class Animal : public Organism
{
    private:
        int m_energy;
        int m_maxEnergy;

    public:
        Animal();
        Animal(int x, int y, char id, int maxEnergy);
        int getEnergy() const;
        int getMaxEnergy() const;
        void setEnergy(int energy);
        bool canConsume(Plant* plant);
        void eat(Plant* plant);
        void moveTo(int x, int y);
        bool isDead() override;
};