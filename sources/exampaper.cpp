#include "headers/exampaper.h"

ExamPaper::ExamPaper(int x, int y, int _index, QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setIndex(_index);
    setPixmap(QPixmap(":/images/images/script.png"));
    setPos(x,y);

}// END OF constructor

void ExamPaper::setIndex(int _index){ index = _index; }

int ExamPaper::getIndex() { return index; }

