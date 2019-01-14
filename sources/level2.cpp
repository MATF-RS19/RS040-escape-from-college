#include "headers/level2.h"
#include "headers/game.h"
#include "headers/player.h"
#include "headers/tips.h"
#include "headers/meni.h"
#include "headers/score.h"
#include "QDebug"

extern Player * player;
extern Score * score;
extern Tips * tips;
extern Game * game;
extern Meni * pocetak;

Level2::Level2(){

    setSceneRect(0, 0, 800, 600);

    // Placing background picture ----------------------------------------------------
    background = new QGraphicsPixmapItem();
    background->setPixmap(QPixmap(":/images/images/2nd.jpg"));
    background->setPos(0,0);
    addItem(background);
    // -------------------------------------------------------------------------------

    // Placing the walls -------------------------------------------------------------
    QVector<QPointF> points;
    points << QPoint(0,48) << QPoint(800,48) << QPoint(800,600) << QPoint(0,600)
           << QPoint(0,416) << QPoint(50,416) << QPoint(50,577) << QPoint(250,577)
           << QPoint(250,531) << QPoint(375,531) << QPoint(375,577) << QPoint(650,577)
           << QPoint(650,439) << QPoint(450,439) << QPoint(450,393) << QPoint(525,393)
           << QPoint(525,416) << QPoint(650,416) << QPoint(650,232) << QPoint(625,232)
           << QPoint(625,140) << QPoint(675,140) << QPoint(675,186) << QPoint(775,186)
           << QPoint(775,71) << QPoint(675,71) << QPoint(675,94) << QPoint(275,94)
           << QPoint(275,71) << QPoint(150,71) << QPoint(150,94) << QPoint(50,94)
           << QPoint(50,370) << QPoint(0,370);
    wall1 = new Wall(points);
    addItem(wall1);

    points.clear();
    points << QPoint(100,278) << QPoint(250,278) << QPoint(250,301) << QPoint(200,301)
           << QPoint(200,393) << QPoint(275,393) << QPoint(275,485) << QPoint(250,485)
           << QPoint(250,462) << QPoint(100,462);
    wall2 = new Wall(points);
    addItem(wall2);

    points.clear();
    points << QPoint(100,140) << QPoint(150,140) << QPoint(150,209) << QPoint(275,209)
           << QPoint(275,140) << QPoint(325,140) << QPoint(325,186) << QPoint(375,186)
           << QPoint(375,140) << QPoint(400,140) << QPoint(400,232) << QPoint(100,232);
    wall3 = new Wall(points);
    addItem(wall3);

    points.clear();
    points << QPoint(450,140) << QPoint(500,140) << QPoint(500,186) << QPoint(550,186)
           << QPoint(550,140) << QPoint(575,140) << QPoint(575,232) << QPoint(450,232);
    wall4 = new Wall(points);
    addItem(wall4);

    points.clear();
    points << QPoint(300,278) << QPoint(525,278) << QPoint(525,347) << QPoint(400,347)
           << QPoint(400,439) << QPoint(375,439) << QPoint(375,485) << QPoint(325,485)
           << QPoint(325,393) << QPoint(375,393) << QPoint(375,301) << QPoint(300,301);
    wall5 = new Wall(points);
    addItem(wall5);
    points.clear();

    points << QPoint(0, 370) << QPoint(1, 370) << QPoint(1, 416) << QPoint(0, 416);
    Wall *wall6 = new Wall(points);
    addItem(wall6);
    // ------------------------------------------------------------------------------

    // Placing the doors ------------------------------------------------------------
    door1 = createDoors(135,94,15,46,true); // locked doors
    door2 = createDoors(510,232,15,46,true);
    door3 = createDoors(400,424,50,15,true);
    door4 = createDoors(360,485,15,46,true);
    door4->setUnlockable(true); // only doors that can be unlocked by the key

    door5 = createDoors(275,94,15,46,false); // unlocked doors
    door6 = createDoors(660,94,15,46,false);
    door7 = createDoors(575,217,50,15,false);
    door8 = createDoors(250,278,50,15,false);
    door9 = createDoors(510,347,15,46,false);
    door10 = createDoors(275,393,50,15,false);
    door11 = createDoors(50,447,50,15,false);
    door12 = createDoors(250,485,15,46,false);
    // ------------------------------------------------------------------------------

    // Stairs stuff -----------------------------------------------------------------
    stairs1 = new Stairs( 550,439,100,69 );
    stairs2 = new Stairs( 550,508,100,69 );

    stairs1->setWalk(false);

    addItem(stairs1);
    addItem(stairs2);
    // ------------------------------------------------------------------------------

    // Profesor stuff ---------------------------------------------------------------
    profesor1 = new Profesor("mrsav", "", 100, 245, 380, 245 );
    profesor2 = new Profesor("debeo", "", 300, 102, 545, 102 );

    profesor1->setName(pocetak->name3);
    profesor2->setName(pocetak->name4);

    addItem(profesor1);
    addItem(profesor2);
    // ------------------------------------------------------------------------------

    // Scripts stuff ----------------------------------------------------------------
    paper1 = new ExamPaper(156,173, 1);
    paper2 = new ExamPaper(739,81, 2);
    paper3 = new ExamPaper(406,356, 3);

    addItem(paper1);
    addItem(paper2);
    addItem(paper3);
    // ------------------------------------------------------------------------------
    qDebug() << "Level2: Everything created for map";

    // Stuff from Game class --------------------------------------------------------
    tips = new Tips("Everything here is made-up!");
    addItem(tips);
    qDebug() << "Level2: Tips created!";

    score = new Score();
    addItem(score);
    qDebug() << "Level2: Score created!";

    player = new Player();
    player->setPos( 10 , 380 );

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    addItem(player);
    qDebug() << "Level2: Player created!";
    // ------------------------------------------------------------------------------

}// END OF constructor

Door *Level2::createDoors(qreal x, qreal y, qreal w, qreal h, bool lock){
    Door * temp = new Door();
    temp->setRect(x,y,w,h);
    temp->setLock(lock);
    addItem(temp);
    return temp;
}

void Level2::clearScene(){
    removeItem(background); delete background;
    removeItem(wall1);      delete wall1;
    removeItem(wall2);      delete wall2;
    removeItem(wall3);      delete wall3;
    removeItem(wall4);      delete wall4;
    removeItem(wall5);      delete wall5;
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
    removeItem(door11);     delete door11;
    removeItem(door12);     delete door12;
    removeItem(stairs1);    delete stairs1;
    removeItem(stairs2);    delete stairs2;
    removeItem(profesor1);  delete profesor1;
    removeItem(profesor2);  delete profesor2;
    removeItem(tips);       delete tips;
    removeItem(score);      delete score;
    removeItem(player);     delete player;

}
