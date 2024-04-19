#include "Entity.h"

Entity::Entity() 
    : m_x{}, m_y{} {}
Entity::Entity(int x, int y) 
    : m_x{x}, m_y{y} {};

int Entity::getX() { return m_x; }
int Entity::getY() { return m_y; }

void Entity::setX(int x) { m_x=x; }
void Entity::setY(int y) { m_y=y; }
