#ifndef LEVEL3_H
#define LEVEL3_H

#include <QGraphicsScene>
#include "headers/wall.h"
#include "headers/door.h"
#include "headers/exampaper.h"
#include "headers/profesor.h"
#include "headers/stairs.h"

class Level3 : public QGraphicsScene{

public:
    Level3();
    Door* createDoors(qreal x,qreal y, qreal w, qreal h, bool lock);

    Wall *wall1, *wall2, *wall3;

    Door *door1, *door2, *door3, *door4, *door5, *door6;

    Stairs *stairs1, *stairs2;

    Profesor *profesor1, *profesor2;

    ExamPaper *paper1, *paper2, *paper3;

};// END OF class

#endif // LEVEL3_H
