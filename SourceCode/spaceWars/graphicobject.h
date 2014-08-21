#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H
#include "point.h"
#include "graphicchar.h"
#include "basicGraphic/basicgraphic.h"
#include "qlist.h"
class graphicObject
{
private:
    char _direction;
    point _pos;
    QList<graphicChar>_grapRight,_grapLeft ,_grapUp,_grapdown;
    float _speed;
    int _fieldLimitRight, _fieldLimitLeft, _fieldLimitDown, _fieldLimitTop;
    QList<point>hitAreaRight, hitAreaLeft, hitAreaDown, hitAreaUp;
    unsigned char _keyPosRight, _keyPosLeft, _keyPosUp, _keyPosDown;
    int _edgeRight, _edgeLeft, _edgeTop, _edgeDown;
    int _hitPower;
public:
    graphicObject();
    int paint();
    int tic(double time);
    int checkHit(point p);
    int checkHit(QList<point>points);
};

#endif // GRAPHICOBJECT_H
