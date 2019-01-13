#ifndef LEVEL1_H
#define LEVEL1_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "wall.h"
#include "door.h"
#include "profesor.h"
#include "stairs.h"
#include "exampaper.h"

class Level1 : public QGraphicsScene{

public:
    Level1();
    Door* createDoors(qreal x, qreal y, qreal w, qreal h, bool lock);

    void clearScene(); // when level2 starts clears everything from level 1

    QGraphicsPixmapItem * background;
    Wall *wall1, *wall2, *wall3, *wall4;
    Door *door1, *door2, *door3, *door4, *door5, *door6, *door7, *door8, *door9, *door10;
    Stairs * stairs;
    ExamPaper *paper1, *paper2, *paper3;
    Profesor *profesor1, *profesor2;

};// END OF class

#endif // LEVEL1_H
