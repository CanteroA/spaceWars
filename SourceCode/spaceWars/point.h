#ifndef POINT_H
#define POINT_H


class point
{
private:
    int _posX;
    int _posY;
public:
    point(int x, int y);
    point();
    void setX(int x);
    void setY(int y);
    int x();
    int y();
};

#endif // POINT_H
