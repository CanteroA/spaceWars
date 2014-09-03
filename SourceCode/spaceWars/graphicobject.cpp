#include "graphicobject.h"

graphicObject::graphicObject()
{
    _direction = DIR_RIHT;
    _pos=point(0,0);
    //Creamos gráfico cuando la posición es para la derecha
    _grapRight.append(graphicChar(point(0,0), '?'));
    _grapRight.append(graphicChar(point(1,0), '>'));

    //Creamos gráfico cuando la posición es para la izquierda
    _grapLeft.append(graphicChar(point(0,0), '<'));
    _grapLeft.append(graphicChar(point(1,0), '?'));

    //Creamos gráfico cuando la posición es para arriba
    _grapUp.append(graphicChar(point(0,0), '^'));
    _grapUp.append(graphicChar(point(0,1), '?'));

    //Creamos gráfico cuando la posición es para abajo
    _grapDown.append(graphicChar(point(0,0), '?'));
    _grapDown.append(graphicChar(point(0,1), 'V'));

    //Inicializar la velocidad en 0
    _speed = 0;

    //Definir la medida de los universos
    _fieldLimitDown = 0;
    _fieldLimitLeft = 0;
    _fieldLimitRight = 0;
    _fieldLimitTop = 0;

    //Looking for hit area for the objects

    hitAreaRight.append(point(0,0));
    hitAreaRight.append(point(1,0));
    hitAreaLeft.append(point(0,0));
    hitAreaLeft.append(point(1,0));
    hitAreaDown.append(point(0,0));
    hitAreaDown.append(point(0,1));
    hitAreaUp.append(point(0,0));
    hitAreaUp.append(point(0,1));

    _edgeRight = 1;
    _edgeLeft = 0;
    _edgeTop = 0;
    _edgeDown = 0;

    ///Valores para la derecha

    _hitPower = 1;

}

///Definir el Hit Area
///Definir el el edgeLimit que es el límite de la nave


int graphicObject::paint()
{
    switch(_direction)
    {
    case DIR_RIHT:
        for(int i = 0; i<_grapRight.size();i++)
            _grapRight[i].paint(_pos);
        break;
    case DIR_LEFT:
        for(int i = 0; i<_grapLeft.size();i++)
            _grapLeft[i].paint(_pos);
        break;
    case DIR_UP:
        for(int i = 0; i<_grapUp.size();i++)
            _grapUp[i].paint(_pos);
        break;
    case DIR_DOWN:
        for(int i = 0; i<_grapDown.size();i++)
            _grapDown[i].paint(_pos);
        break;

    default:
        return -1;
        ///Dirección no válida
    }
    return 0;
    /// Buen trabajo de número
}
//Verifica que el objeto no se pase de las margenes
int graphicObject::tic(double time)
{
    point newPos;
    //Intento moverme
    switch (_direction) {
    case DIR_RIHT:
        newPos = point(_pos.x()+ _speed*time, _pos.y());
        break;
    case DIR_LEFT:
        newPos = point(_pos.x()- _speed*time, _pos.y());
        break;
    case DIR_UP:
        newPos = point(_pos.x(), _pos.y()- _speed*time);
        break;

    case DIR_DOWN:
        newPos = point(_pos.x(), _pos.y()+ _speed*time);
        break;

    default:
        return -1;
        break;
    }

    //Verificar si está dentro del universo
    bool inside=true;
    switch (_direction) {
    case DIR_RIHT:
        if(newPos.xInit() + _edgeRight >= _fieldLimitRight)
            inside = false;
        break;
    case DIR_LEFT:
        if(newPos.xInit() <= _fieldLimitLeft)
            inside = false;
        break;
    case DIR_UP:
        if(newPos.yInit() <= _fieldLimitTop)
            inside = false;
        break;
    case DIR_DOWN:
        if(newPos.yInit() + _edgeDown >= _fieldLimitDown)
            inside = false;
        break;
    default:
        return -1;
        break;
    }
    if(inside == true)
    {
        _pos = newPos;                //Si la nave está dentro
    }
    else
    {
        _speed=0;                    //Si la nave se salió
        //Detengo la nave
        switch (_direction) {
        //La llevo al límite
        case DIR_RIHT:
            _pos.setX(_fieldLimitRight-_edgeRight-1);
            break;
        case DIR_DOWN:
            _pos.setY(_fieldLimitDown-_edgeDown-1);
            break;
        case DIR_LEFT:
            _pos.setX(_fieldLimitLeft + 1);
            break;
        case DIR_UP:
            _pos.setY(_fieldLimitTop + 1);
            break;

        default:
            break;
        }

    }

}

int graphicObject::checkHit(point p)
{
    p.setX(p.x()-_pos.x());
    p.setY(p.y()-_pos.y());
    QList<point>* currentHitArea;
    switch (_direction) {
    case DIR_RIHT:
        currentHitArea = & hitAreaRight;
        break;
    case DIR_LEFT:
        currentHitArea = &hitAreaLeft;
        break;
    case DIR_UP:
        currentHitArea= & hitAreaUp;
        break;
    case DIR_DOWN:
        currentHitArea =&hitAreaDown;
        break;
  }
    for(int i=0; i<currentHitArea->size(); i++)
  {
        if(p==currentHitArea->at(i))
            return 1;
    }
    return 0;
}


//Check point by point
int graphicObject::checkHit(QList<point> points)
{
    int countPoints = 0;
    for(int i=0;0<points.size();i++)
        countPoints += checkHit(points[i]); //count = count+2
    return countPoints;

}

void graphicObject::setPos(int x, int y)
{
    _pos.setX(x);
    _pos.setY(y);
}

void graphicObject::setSpeed(float speed)
{
    _speed = speed;
}

void graphicObject::setFieldLimits(int right, int left, int top, int down)
{
    _fieldLimitDown = down;
    _fieldLimitLeft = left;
    _fieldLimitRight = right;
    _fieldLimitTop = top;
}

bool graphicObject::setDir(char direction)
{
    if (direction > 3 || direction < 0)                             //Validar si está la dirección en los rangos
        return false;
    _direction = direction;

    //Referencia del hit area
    QList<point>* currentHitArea;
    switch (_direction) {
    case DIR_RIHT:
        currentHitArea = & hitAreaRight;
        break;
    case DIR_LEFT:
        currentHitArea = &hitAreaLeft;
        break;
    case DIR_UP:
        currentHitArea= & hitAreaUp;
        break;
    case DIR_DOWN:
        currentHitArea =&hitAreaDown;
        break;
  }

    if (currentHitArea->size() == 0)
        return false;

    int maxX = currentHitArea->at(0).x();
    int minX = currentHitArea->at(0).x();
    int maxY = currentHitArea->at(0).y();
    int minY = currentHitArea->at(0).y();

    for (int i = 0; i<currentHitArea->size(); i++)
    {
        if(currentHitArea->at(i).x())
            maxX = currentHitArea->at(i).x();

        if(currentHitArea->at(i).x())
            minX = currentHitArea->at(i).x();


        if(currentHitArea->at(i).y())
            maxY = currentHitArea->at(i).y();

        if(currentHitArea->at(i).y())
            minY = currentHitArea->at(i).y();
    }
          _edgeDown = minY;
          _edgeLeft = minX;
          _edgeRight = maxX;
          _edgeTop = maxY;


}


