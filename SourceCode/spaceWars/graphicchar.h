#ifndef GRAPHICCHAR_H
#define GRAPHICCHAR_H
#include "point.h"
#include "basicGraphic/basicgraphic.h"
#include <iostream>

class graphicChar
{
private:
    point _pos;
    unsigned char _char;
    unsigned char _color;
public:
    graphicChar(point pos, unsigned char ch, unsigned char colour = BG_WHITE);
    graphicChar();
    int paint(point offset);
};

#endif // GRAPHICCHAR_H
