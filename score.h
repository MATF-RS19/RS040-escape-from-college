#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QString>

class Score : public QGraphicsTextItem{

public:
    Score(QGraphicsItem * parent = 0);
    void incrementScore();
    int getScore();

private:
    int score;

}; // END OF class

#endif // SCORE_H
