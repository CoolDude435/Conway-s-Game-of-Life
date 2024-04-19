#pragma once
#include "Organism.h"

class Animal : public Organism
{
    private:
        int m_energy;
        int m_maxEnergy;

    public:
        Animal();
        Animal(int x, int y, char id, int maxEnergy);
        int getEnergy();
        int getMaxEnergy();
        bool moveNorth();
        bool moveSouth();
        bool moveWest();
        bool moveEast();
};