#pragma once
#include "Organism.h"

class Plant : public Organism
{
    private:
        int m_regrowCoef;
        int m_energyPts;
        int m_regrowTimer;
        bool m_isEaten;

    public:
        Plant();
        Plant(int x, int y, char id, int regrowCoef, int energyPts);
        int getRegrowCoef();
        int getEnergyPts();
        int getRegrowTimer();
        bool isEaten();
        Plant* clone();
};