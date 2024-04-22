#pragma once

#include "Entity.h"

class Organism : public Entity
{
    private:
        char m_id{};
    public:
        Organism();
        Organism(int x, int y, int id);
        int getID();
        virtual Organism* clone();
};