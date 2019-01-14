#include "headers/wall.h"
#include <QVector>
#include <QPolygonF>


Wall::Wall(QVector<QPointF> points,QGraphicsItem * parent): QGraphicsPolygonItem(QPolygonF(points),parent){

}// END OF constructor
