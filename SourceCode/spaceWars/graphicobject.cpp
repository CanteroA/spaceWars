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
        if(newPos.x() + _edgeRight >= _fieldLimitRight)
            inside = false;
        break;
    case DIR_LEFT:
        if(newPos.x() <= _fieldLimitLeft)
            inside = false;
        break;
    case DIR_UP:
        if(newPos.y() <= _fieldLimitTop)
            inside = false;
        break;
    case DIR_DOWN:
        if(newPos.y() + _edgeDown >= _fieldLimitDown)
            inside = false;
        break;
    default:
        return -1;
        break;
    }
    if(inside = true)
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

}

int graphicObject::checkHit(QList<point> points)
{

}


