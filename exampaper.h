#ifndef EXAMPAPER_H
#define EXAMPAPER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class ExamPaper : public QGraphicsPixmapItem{

public:
    ExamPaper( int x, int y, int index, QGraphicsItem * parent = 0 );

    void setIndex(int _index);
    int getIndex();

private:
    int index;

};// END OF class

#endif // EXAMPAPER_H
