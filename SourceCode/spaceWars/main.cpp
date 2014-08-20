#include <iostream>
#include "basicGraphic/basicgraphic.h"
#include "graphicchar.h"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    graphicChar c1(point(4, 0), '/', BG_GREEN);
    graphicChar c2(point(4, 3), '\\', BG_GREEN);
    point off(40, 5);
    c1.paint(off);
    c2.paint(off);







    bg::gotoxy(0, 40);
    bg::setColor();
    return 0;

}
