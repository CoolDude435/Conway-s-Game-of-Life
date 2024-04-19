#include "Organism.h"

Organism::Organism() 
    : Entity{}, m_id{} {}
Organism::Organism(int x, int y, int id) 
    : Entity{x,y}, m_id{id} {}
int Organism::getID() { return m_id; }