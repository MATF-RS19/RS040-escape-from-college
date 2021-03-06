#include "headers/game.h"
#include <QGraphicsPixmapItem>
#include <QDebug>
#include "headers/player.h"
#include "headers/tips.h"
#include "headers/score.h"

Tips *tips;
Score *score;

Player *player;

Game::Game(): QGraphicsView(){

    index = 1; // level1 first

    setFixedSize(800, 600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Upper text stuff -------------------------------------------------------------
    tips = new Tips("Everything here is made-up!");
    qDebug() << "Created tips";

    score = new Score();
    qDebug() << "Created score";
    // ------------------------------------------------------------------------------

    // Player stuff -----------------------------------------------------------------
    player = new Player();
    qDebug() << "Created player";

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // ------------------------------------------------------------------------------

    changeLevel();

    show();
}// END OF constructor

void Game::changeLevel(){
    switch(index){
        case 1:
            level1 = new Level1();
            setScene(level1);
            break;
        case 2:
            level1->clearScene();
            level2 = new Level2();
            qDebug() << "level 2 initialized";
            setScene(level2);
            qDebug() << "We set level2";
            break;

        case 3:
            level2->clearScene();
            level3 = new Level3();
            setScene(level3);
            break;

    }
}

















