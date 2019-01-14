#include "headers/stairs.h"


Stairs::Stairs(int x,int y, int width, int height, QGraphicsItem *parent): QGraphicsRectItem(parent){

    setRect(0,0,width,height);
    setPos(x,y);
    walk = true;

}// END OF constructor

void Stairs::setWalk(bool w) { walk = w; }

bool Stairs::getWalk() { return walk; }
