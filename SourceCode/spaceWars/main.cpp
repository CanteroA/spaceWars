#include <iostream>
#include "basicGraphic/basicgraphic.h"
#include "graphicchar.h"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    graphicChar c1(point(1, 3), 17, BG_GREEN);
    graphicChar c2(point(2, 2), '/', BG_GREEN);
    graphicChar c3(point(2, 3), '<', BG_RED);
    graphicChar c4(point(2, 4), '\\', BG_GREEN);
    graphicChar c5(point(3, 2), '<', BG_GREEN);
    graphicChar c6(point(3, 3), 2 , BG_WHITE);
    graphicChar c7(point(3, 4), '<', BG_GREEN);
    graphicChar c8(point(4, 2), '<', BG_GREEN);
    graphicChar c9(point(4, 3), 'K', BG_CYAN);
    graphicChar c10(point(4, 4), '<', BG_GREEN);
    graphicChar c11(point(5, 2), '-', BG_GREEN);
    graphicChar c12(point(5, 3),219 , BG_WHITE);
    graphicChar c13(point(5, 4), '-', BG_GREEN);
    graphicChar c14(point(6, 2), '-', BG_GREEN);
    graphicChar c15(point(6, 3), 219, BG_WHITE);
    graphicChar c16(point(6, 4), '-', BG_GREEN);
    graphicChar c17(point(7, 1), 187, BG_RED);
    graphicChar c18(point(7, 2), '|', BG_GREEN);
    graphicChar c19(point(7, 3), '|', BG_GREEN);
    graphicChar c20(point(7, 4), '|', BG_GREEN);
    graphicChar c21(point(7, 5), 188, BG_RED);
    graphicChar c22(point(8, 2), '<', BG_YELLOW);
    graphicChar c23(point(8, 4), '<', BG_YELLOW);

    point off(40, 5);
    c1.paint(off);
    c2.paint(off);
    c3.paint(off);
    c4.paint(off);
    c5.paint(off);
    c6.paint(off);
    c7.paint(off);
    c8.paint(off);
    c9.paint(off);
    c10.paint(off);
    c11.paint(off);
    c12.paint(off);
    c13.paint(off);
    c14.paint(off);
    c15.paint(off);
    c16.paint(off);
    c17.paint(off);
    c18.paint(off);
    c19.paint(off);
    c20.paint(off);
    c21.paint(off);
    c22.paint(off);
    c23.paint(off);







    bg::gotoxy(0, 40);
    bg::setColor();
    return 0;

}
