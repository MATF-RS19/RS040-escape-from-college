#ifndef DOOR_H
#define DOOR_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

class Door : public QGraphicsRectItem{

public:
    Door(QGraphicsItem * parent = 0);
    void setLock(bool lock);
    bool getLock();

    void setUnlockable( bool unlock );
    bool getUnlockable();

private:
    bool isLocked;
    bool unlockable;

};// END OF class

#endif // DOOR_H
