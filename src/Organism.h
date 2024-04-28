#pragma once

#include "Entity.h"
#include "enums.h"

class Organism : public Entity
{
    private:
        char m_id{};
    public:
        Organism();
        Organism(int x, int y, char id);
        int getID();
        virtual Organism* clone() = 0;
        virtual SpeciesType getSpeciesType() = 0;
};