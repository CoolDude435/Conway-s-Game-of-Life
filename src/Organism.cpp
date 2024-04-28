#include "Organism.h"

Organism::Organism() 
    : Entity{}, m_id{} {}
Organism::Organism(int x, int y, char id) 
    : Entity{x,y}, m_id{id} {}
int Organism::getID() { return m_id; }
