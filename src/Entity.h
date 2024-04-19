#pragma once

class Entity
{
    private:
        //Stores x and y coordinates of the Entity on the map
        int m_x{};
        int m_y{};

    public:
        Entity();
        Entity(int x, int y);
        int getX();
        int getY();
    protected:
        void setX(int x);
        void setY(int y);
};
