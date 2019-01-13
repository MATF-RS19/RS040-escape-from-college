#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>

class Player : public QGraphicsPixmapItem{

public:
    Player(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent * event);

    bool getGender();
    void setGender( bool gen );

    bool getKey();
    void setKey(bool k);

private:
    bool gender; // true -> male | false -> female | else -> unidentified
    bool key;
    int collide(); // check if player is colliding with wall/locked doors

};// END OF class

#endif // PLAYER_H
