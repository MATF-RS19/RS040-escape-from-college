#ifndef LEVEL2_H
#define LEVEL2_H

#include <QGraphicsScene>
#include "door.h"
#include "wall.h"
#include "stairs.h"
#include "exampaper.h"
#include "profesor.h"

class Level2 : public QGraphicsScene{

public:
    Level2();
    Door* createDoors(qreal x,qreal y, qreal w, qreal h, bool lock);

    Wall *wall1, *wall2, *wall3, *wall4, *wall5;

    Door *door1, *door2, *door3, *door4, *door5, *door6, *door7, *door8, *door9,
         *door10, *door11, *door12;

    Stairs *stairs1, *stairs2;

    ExamPaper *paper1, *paper2, *paper3;

    Profesor *profesor1, *profesor2;


}; // END OF class

#endif // LEVEL2_H
