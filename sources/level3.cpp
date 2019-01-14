#include "headers/level3.h"
#include "headers/game.h"
#include "headers/player.h"
#include "headers/tips.h"
#include "headers/meni.h"
#include "headers/score.h"

extern Player * player;
extern Score * score;
extern Tips * tips;
extern Game * game;
extern Meni * pocetak;

Level3::Level3(){

    setSceneRect(0, 0, 800, 600);

    // Placing background picture ----------------------------------------------------
    QGraphicsPixmapItem * background = new QGraphicsPixmapItem();
    background->setPixmap(QPixmap(":/images/images/3rd.jpg"));
    background->setPos(0,0);
    addItem(background);
    // -------------------------------------------------------------------------------

    // Placing the walls -------------------------------------------------------------
    QVector<QPointF> points;
    points << QPoint(0,48) << QPoint(800,48) << QPoint(800,117) << QPoint(325,117)
           << QPoint(325,71) << QPoint(275,71) << QPoint(275,117) << QPoint(50,117)
           << QPoint(50,416) << QPoint(250,416) << QPoint(250,439) << QPoint(125,439)
           << QPoint(125,554) << QPoint(400,554) << QPoint(400,531) << QPoint(425,531)
           << QPoint(425,554) << QPoint(575,554) << QPoint(575,462) << QPoint(425,462)
           << QPoint(425,485) << QPoint(400,485) << QPoint(400,439) << QPoint(300,439)
           << QPoint(300,416) << QPoint(800,416) << QPoint(800,600) << QPoint(0,600);
    wall1 = new Wall(points);
    addItem(wall1);

    points.clear();
    points << QPoint(550,163) << QPoint(800,163) << QPoint(800,370) << QPoint(550,370)
           << QPoint(550,301) << QPoint(575,301) << QPoint(575,324) << QPoint(750,324)
           << QPoint(750,209) << QPoint(575,209) << QPoint(575,255) << QPoint(550,255);
    wall2 = new Wall(points);
    addItem(wall2);

    points.clear();
    points << QPoint(100,163) << QPoint(200,163) << QPoint(200,186) << QPoint(150,186)
           << QPoint(150,278) << QPoint(325,278) << QPoint(325,255) << QPoint(350,255)
           << QPoint(350,301) << QPoint(425,301) << QPoint(425,186) << QPoint(350,186)
           << QPoint(350,209) << QPoint(325,209) << QPoint(325,186) << QPoint(250,186)
           << QPoint(250,163) << QPoint(500,163) << QPoint(500,370) << QPoint(100,370);
    wall3 = new Wall(points);
    addItem(wall3);

    points.clear();
    points << QPoint(799,117) << QPoint(800,117) << QPoint(800,163) << QPoint(799,163);
    Wall *wall4 = new Wall(points);
    addItem(wall4);
    // --------------------------------------------------------------------------------

    // Placing the doors ------------------------------------------------------------
    door1 = createDoors(700,117,15,46,true); // locked doors
    door1->setUnlockable(true); // only doors that can be unlocked by the key

    door2 = createDoors(200,163,50,15,false); // unlocked doors
    door3 = createDoors(325,209,15,46,false);
    door4 = createDoors(550,255,15,46,false);
    door5 = createDoors(250,416,50,15,false);
    door6 = createDoors(400,485,15,46,false);
    // --------------------------------------------------------------------------------

    // Stairs stuff -----------------------------------------------------------------
    stairs1 = new Stairs( 736,370, 64,46 );
    stairs2 = new Stairs( 715,117, 84,46 );

    stairs1->setWalk(false);

    addItem(stairs1);
    addItem(stairs2);
    // ------------------------------------------------------------------------------

    // Profesor stuff ---------------------------------------------------------------
    profesor1 = new Profesor("mrsav", "", 100, 130, 500, 130 );
    profesor2 = new Profesor("debeo", "", 100, 383, 500, 383 );

    profesor1->setName(pocetak->name5);
    profesor2->setName(pocetak->name6);

    addItem(profesor1);
    addItem(profesor2);
    // ------------------------------------------------------------------------------

    // Scripts stuff ----------------------------------------------------------------
    paper1 = new ExamPaper(392,206, 1);
    paper2 = new ExamPaper(710,221, 2);
    paper3 = new ExamPaper(537,495, 3);

    addItem(paper1);
    addItem(paper2);
    addItem(paper3);
    // ------------------------------------------------------------------------------

    // Stuff from Game class --------------------------------------------------------
    tips = new Tips("Everything here is made-up!");
    addItem(tips);

    score = new Score();
    addItem(score);

    player = new Player();
    player->setPos( 690 , 383 );

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    addItem(player);
    // ------------------------------------------------------------------------------

}// END OF constructor

Door *Level3::createDoors(qreal x, qreal y, qreal w, qreal h, bool lock){
    Door * temp = new Door();
    temp->setRect(x,y,w,h);
    temp->setLock(lock);
    addItem(temp);
    return temp;
}
