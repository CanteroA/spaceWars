#include "point.h"


point::point(float x, float y)
{
    _posX = x;
    _posY = y;
}

point::point()
{
    _posX = 0;
    _posY = 0;

}

void point::setX(float x)
{
    _posX = x;
}

void point::setY(float y)
{
    _posY = y;
}

float point::x() const
{
    return _posX;
}

float point::y() const
{
    return _posY;
}

int point::xInit() const
{
    return (int) _posX;
}

int point::yInit() const
{
    return (int) _posY;
}



bool operator==(const point &p1, const point &p2)
{
    return (p1.x()==p2.x())&&(p1.y()==p2.y());
}
