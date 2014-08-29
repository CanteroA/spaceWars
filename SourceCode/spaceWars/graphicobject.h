#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H
#include "point.h"
#include "graphicchar.h"
#include "basicGraphic/basicgraphic.h"
#include "qlist.h"
#define DIR_RIHT 0
#define DIR_LEFT 2
#define DIR_UP 1
#define DIR_DOWN 3


class graphicObject
{
private:
    char _direction;
    point _pos;
    QList<graphicChar>_grapRight,_grapLeft ,_grapUp,_grapDown;
    float _speed;
    int _fieldLimitRight, _fieldLimitLeft, _fieldLimitDown, _fieldLimitTop;
    QList<point>hitAreaRight, hitAreaLeft, hitAreaDown, hitAreaUp;
    unsigned char _keyPosRight, _keyPosLeft, _keyPosUp, _keyPosDown;
    int _edgeRight, _edgeLeft, _edgeTop, _edgeDown;
    int _hitPower;
public:
    //initialize all members
    graphicObject();
    int paint();
    int tic(double time); //Dado en milisegundos
    int checkHit(point p);
    int checkHit(QList<point>points);
    void setPos(int x, int y);
    void setSpeed(float speed);
    void setFieldLimits(int right, int left, int top, int down);
    bool setDir(char direction);
};

#endif // GRAPHICOBJECT_H
