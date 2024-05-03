#pragma once

#include "enums.h"

class Organism
{
    private:
        int m_x{};
        int m_y{};
        char m_id{};
    public:
        Organism();
        Organism(int x, int y, char id);
        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);
        char getID() const;
        virtual bool isDead() = 0;
        virtual SpeciesType getSpeciesType() = 0;
};