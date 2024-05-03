#include "Organism.h"

Organism::Organism() 
    : m_x{}, m_y{}, m_id{} {}
Organism::Organism(int x, int y, char id) 
    : m_x{x}, m_y{y}, m_id{id} {}

int Organism::getX() const { return m_x; }
int Organism::getY() const { return m_y; }
void Organism::setX(int x) { m_x = x; }
void Organism::setY(int y) { m_y = y; } 

char Organism::getID() const { return m_id; }
