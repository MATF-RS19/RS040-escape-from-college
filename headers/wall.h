#ifndef WALL_H
#define WALL_H

#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>

class Wall: public QGraphicsPolygonItem{

public:
    Wall(QVector<QPointF> points,QGraphicsItem * parent=0);

}; // END OF class

#endif // WALL_H
