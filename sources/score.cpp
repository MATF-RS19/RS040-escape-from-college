#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){

    score = 0;
    setPlainText( QString("Scripts stolen: 0") );
    setFont( QFont("helvetica", 16) );
    setDefaultTextColor(Qt::blue);
    setPos(0,5);

}// END OF constructor

void Score::incrementScore() {
    setPlainText( QString("Scripts stolen: ") + QString::number(++score) );
}

int Score::getScore() { return score; }
