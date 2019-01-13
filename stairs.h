#ifndef STAIRS_H
#define STAIRS_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Stairs : public QGraphicsRectItem{

public:
    Stairs(int x,int y, int width, int height, QGraphicsItem * parent = 0);

    void setWalk(bool w);
    bool getWalk();

private:
    bool walk; // can you walk on the stairs

}; // END OF class

#endif // STAIRS_H
