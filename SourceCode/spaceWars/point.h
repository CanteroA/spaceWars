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
    int x() const;
    int y() const;
};
bool operator==(const point& p1, const point& p2);

#endif // POINT_H
