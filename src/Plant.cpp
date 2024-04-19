#include "Plant.h"

Plant::Plant()
    : Organism{}, m_regrowCoef{}, m_energyPts{}, m_regrowTimer{}, m_isEaten{} {}
Plant::Plant(int x, int y, char id, int regrowCoef, int energyPts)
    : Organism{x,y,id}, m_regrowCoef{regrowCoef}, m_energyPts{energyPts}, m_regrowTimer{0}, m_isEaten{false} {}

int Plant::getRegrowCoef() { return m_regrowCoef; }
int Plant::getEnergyPts() { return m_energyPts; }
int Plant::getRegrowTimer() { return m_regrowTimer; }
bool Plant::isEaten() { return m_isEaten; }