#include "level1.h"
#include "player.h"
#include "tips.h"
#include "score.h"
#include "game.h"
#include "meni.h"
#include <QDebug>

extern Player * player;
extern Tips * tips;
extern Score * score;
extern Meni * pocetak;

Level1::Level1(){

    setSceneRect(0, 0, 800, 600);

    // Placing background picture ----------------------------------------------------
    background = new QGraphicsPixmapItem();
    background->setPixmap(QPixmap(":/images/1st.jpg"));
    background->setPos(0,0);
    addItem(background);
    // -------------------------------------------------------------------------------
    qDebug() << "Level1 : background set!";

    // Placing the walls -------------------------------------------------------------
    QVector<QPointF> points;
    points << QPoint(0,439) << QPoint(100,439) << QPoint(100,462) << QPoint(50,462)
           << QPoint(50,577) << QPoint(225,577) << QPoint(225,531) << QPoint(375,531)
           << QPoint(375,439) << QPoint(475,439) << QPoint(475,370) << QPoint(650,370)
           << QPoint(650,439) << QPoint(550,439) << QPoint(550,554) << QPoint(775,554)
           << QPoint(775,439) << QPoint(700,439) << QPoint(700,324) << QPoint(575,324)
           << QPoint(575,163) << QPoint(700,163) << QPoint(700,209) << QPoint(625,209)
           << QPoint(625,278) << QPoint(775,278) << QPoint(775,209) << QPoint(750,209)
           << QPoint(750,117) << QPoint(675,117) << QPoint(675,71) << QPoint(475,71)
           << QPoint(475,163) << QPoint(525,163) << QPoint(525,209) << QPoint(375,209)
           << QPoint(375,186) << QPoint(450,186) << QPoint(450,48) << QPoint(800,48)
           << QPoint(800,600) << QPoint(0,600);
    wall1 = new Wall(points);
    addItem(wall1);

    points.clear();
    points << QPoint(0,48) << QPoint(250,48) << QPoint(250,186) << QPoint(325,186)
           << QPoint(325,209) << QPoint(150,209) << QPoint(150,140) << QPoint(200,140)
           << QPoint(200,71) << QPoint(50,71) << QPoint(50,140) << QPoint(100,140)
           << QPoint(100,254) << QPoint(25,254) << QPoint(25,301) << QPoint(100,301)
           << QPoint(100,393) << QPoint(0,393);
    wall2 = new Wall(points);
    addItem(wall2);

    points.clear();
    points << QPoint(150,255) << QPoint(200,255) << QPoint(200,301) << QPoint(250,301)
           << QPoint(250,255) << QPoint(350,255) << QPoint(350,278) << QPoint(275,278)
           << QPoint(275,439) << QPoint(325,439) << QPoint(325,485) << QPoint(225,485)
           << QPoint(225,462) << QPoint(150,462);
    wall3 = new Wall(points);
    addItem(wall3);

    points.clear();
    points << QPoint(400,255) << QPoint(525,255) << QPoint(525,324) << QPoint(475,324)
           << QPoint(475,278) << QPoint(400,278);
    wall4 = new Wall(points);
    addItem(wall4);

    points.clear();
    // -------------------------------------------------------------------------------
    qDebug() << "Level1 : walls set!";

    // Placing the doors ------------------------------------------------------------
    door1 = createDoors(225,486,15,46,true); // locked doors
    door2 = createDoors(325,194,50,15,true);
    door3 = createDoors(350,255,50,15,true);
    door1->setUnlockable(true); // only doors that can be unlocked by the scripts

    door4 = createDoors(85,254,15,46,false);// unlocked doors
    door5 = createDoors(475,324,15,46,false);
    door6 = createDoors(100,140,50,15,false);
    door7 = createDoors(100,447,50,15,false);
    door8 = createDoors(325,439,50,15,false);
    door9 = createDoors(525,163,50,15,false);
    door10 = createDoors(650,424,50,15,false);
    // ------------------------------------------------------------------------------
    qDebug() << "Level1 : doors set!";

    // Stairs stuff -----------------------------------------------------------------
    stairs = new Stairs( 0,393,64,46 );
    stairs->setWalk(false); // so he can't go out before collecting scripts

    addItem(stairs);
    // ------------------------------------------------------------------------------
    qDebug() << "Level1 : stairs set!";

    // Scripts stuff ----------------------------------------------------------------
    paper1 = new ExamPaper(59,78, 1);
    paper2 = new ExamPaper(637,241, 2);
    paper3 = new ExamPaper(562,508, 3);

    addItem(paper1);
    addItem(paper2);
    addItem(paper3);
    // ------------------------------------------------------------------------------
    qDebug() << "Level1 : scripts set!";

    // Profesor stuff ---------------------------------------------------------------
    profesor1 = new Profesor("mrsav", "", 113,160, 113,420);
    profesor2 = new Profesor("debeo", "", 537,130, 537,340);

    profesor1->setName(pocetak->name1);
    profesor2->setName(pocetak->name2);

    addItem(profesor1);
    addItem(profesor2);
    // ------------------------------------------------------------------------------

    // Upper text stuff -------------------------------------------------------------
    addItem(tips);
    qDebug() << "Level1 : tips from game all ready!";

    //score = new Score(); // reset score
    addItem(score);
    qDebug() << "Level1 : score from game all ready!";
    // ------------------------------------------------------------------------------

    addItem(player);
    qDebug() << "Level1 : player from game all ready!";

}// END OF constructor

Door *Level1::createDoors(qreal x, qreal y, qreal w, qreal h, bool lock){
    Door * temp = new Door();
    temp->setRect(x,y,w,h);
    temp->setLock(lock);
    addItem(temp);
    return temp;

}

void Level1::clearScene(){

    removeItem(background); delete background;
    removeItem(wall1);      delete wall1;
    removeItem(wall2);      delete wall2;
    removeItem(wall3);      delete wall3;
    removeItem(wall4);      delete wall4;
    removeItem(door1);      delete door1;
    removeItem(door2);      delete door2;
    removeItem(door3);      delete door3;
    removeItem(door4);      delete door4;
    removeItem(door5);      delete door5;
    removeItem(door6);      delete door6;
    removeItem(door7);      delete door7;
    removeItem(door8);      delete door8;
    removeItem(door9);      delete door9;
    removeItem(door10);     delete door10;
    removeItem(stairs);     delete stairs;
    removeItem(tips);       delete tips;
    removeItem(score);      delete score;
    removeItem(player);     delete player;

}
