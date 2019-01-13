#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QString>
#include "door.h"
#include "level1.h"
#include "level2.h"

class Game : public QGraphicsView {

public:
    Game();
    void changeLevel();

    Level1 *level1;
    Level2 *level2;
    //Level3 *level3;

    int index; // level counter
};

#endif // GAME_H
