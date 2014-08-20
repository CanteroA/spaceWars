#include "point.h"


point::point(int x, int y)
{
    _posX = x;
    _posY = y;
}

point::point()
{
    _posX = 0;
    _posY = 0;

}

void point::setX(int x)
{
    _posX = x;
}

void point::setY(int y)
{
    _posY = y;
}

int point::x()
{
    return _posX;
}

int point::y()
{
    return _posY;
}
