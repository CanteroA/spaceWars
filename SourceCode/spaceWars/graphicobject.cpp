#include "graphicobject.h"

graphicObject::graphicObject()
{
    _direction = 0;
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
    _grapdown.append(graphicChar(point(0,0), '?'));
    _grapdown.append(graphicChar(point(0,1), 'V'));

    //Inicializar la velocidad en 0
    _speed = 0;

    //Definir la medida de los universos

    _fieldLimitDown = 0;
    _fieldLimitLeft = 0;
    _fieldLimitRight = 0;
    _fieldLimitTop = 0;


    ///Definir el Hit Area
    ///Definir el el edgeLimit que es el límite de la nave









}

int graphicObject::paint()
{

}

int graphicObject::tic(double time)
{

}

int graphicObject::checkHit(point p)
{

}

int graphicObject::checkHit(QList<point> points)
{

}


