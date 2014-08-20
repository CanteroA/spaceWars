#include "graphicchar.h"

graphicChar::graphicChar(point pos, unsigned char ch, unsigned char colour)
{
    _pos = pos;
    _char = ch;
    _color = colour;




}

graphicChar::graphicChar()
{
    graphicChar(point(),'-', BG_GREEN);

}

int graphicChar::paint(point offset)
{
    int x = offset.x()+ _pos.x();
    int y = offset.y()+_pos.y();
    bg::gotoxy(x, y);
    bg::setColor(_color);
    std::cout <<_char;
}
