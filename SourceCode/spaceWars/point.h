#ifndef POINT_H
#define POINT_H


class point
{
private:
    float _posX;
    float _posY;
public:
    point(float x, float y);
    point();
    void setX(float x);
    void setY(float y);
    float x() const;
    float y() const;
    int xInit() const;
    int yInit() const;
};
bool operator==(const point& p1, const point& p2);

#endif // POINT_H
