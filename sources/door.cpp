#include "headers/door.h"

Door::Door(QGraphicsItem *parent): QGraphicsRectItem(parent){
    unlockable = false;
    isLocked = false;
}// END OF constructor

void Door::setLock(bool lock){ isLocked = lock; }
bool Door::getLock(){ return isLocked; }

void Door::setUnlockable(bool unlock) { unlockable = unlock; }
bool Door::getUnlockable() { return unlockable; }


