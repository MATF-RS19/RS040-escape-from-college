#include "player.h"
#include "stairs.h"
#include "wall.h"
#include "door.h"
#include "exampaper.h"
#include "game.h"
#include "score.h"
#include "tips.h"
#include "profesor.h"
#include "meni.h"
#include <QList>
#include <QPointF>
#include <stdlib.h>
#include <QDebug>

extern Game * game;
//extern Player * player;
extern Tips * tips;
extern Score * score;
extern Meni * pocetak;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    gender = pocetak->gender;
    key = false;
    if( gender == true )
        setPixmap(QPixmap(":/images/maleRight.png"));
    else
        setPixmap(QPixmap(":/images/femaleRight.png"));
    setPos(70, 405);
    setScale(1.3);

}// END OF constructor

void Player::keyPressEvent(QKeyEvent *event){

    if( event->key() == Qt::Key_W ){
        if( gender == true )
            setPixmap(QPixmap(":/images/maleUp.png"));
        else
            setPixmap(QPixmap(":/images/femaleUp.png"));

        setPos( x(), y() - 3 );
        if( collide() == 1 )
            setPos( x(), y() + 3 );
        else
        tips->setText("Everything here is made-up!");

    }
    else if( event->key() == Qt::Key_S ){

        if( gender == true )
            setPixmap(QPixmap(":/images/maleDown.png"));
        else
            setPixmap(QPixmap(":/images/femaleDown.png"));

        setPos( x(), y() + 3 );
        if( collide() == 1 )
            setPos( x(), y() - 3 );
        else
        tips->setText("Everything here is made-up!");

    }
    else if( event->key() == Qt::Key_A ){

        if( gender == true )
            setPixmap(QPixmap(":/images/maleLeft.png"));
        else
            setPixmap(QPixmap(":/images/femaleLeft.png"));

        setPos( x() - 3, y() );
        if( collide() == 1 )
            setPos( x() + 3, y() );
        else
        tips->setText("Everything here is made-up!");

    }
    else if( event->key() == Qt::Key_D ){

        if( gender == true )
            setPixmap(QPixmap(":/images/maleRight.png"));
        else
            setPixmap(QPixmap(":/images/femaleRight.png"));

        setPos( x() + 3, y() );
        if( collide() == 1 )
            setPos( x() - 3, y() );
        else
        tips->setText("Everything here is made-up!");
    }
    else if( event->key() == Qt::Key_Space ){
        if( collide() == 3 ){
            game->index++;
            tips->setPlainText("Congrats!");
            game->changeLevel();
            }
    }
}// END OF keyPressEvent

bool Player::getGender(){ return gender; }
void Player::setGender(bool gen) { gender = gen; }

bool Player::getKey(){ return key; }
void Player::setKey(bool k) { key = k; }

/*
 * returns:
 * 1 -> Player collides with locked doors or walls
 * 2 -> Player collides with something passable
 * 3 -> Player collides with stairs to proceed
*/
int Player::collide(){

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0; i < colliding_items.size(); ++i){

        // Player collide with walls ------------------------------------------------
        if (typeid(*(colliding_items[i])) == typeid(Wall))
            return 1;
        // --------------------------------------------------------------------------

        // Player collide with stairs -----------------------------------------------
        else if (typeid(*(colliding_items[i])) == typeid(Stairs)){

            if( ((Stairs*)colliding_items[i])->getWalk() == false ){
                tips->setPlainText("That's dangerous!");
                return 1;
            }
            else
                return 3;

        }
        // --------------------------------------------------------------------------

        // Player collide with locked doors -----------------------------------------
        else if( typeid(*(colliding_items[i])) == typeid(Door) &&
                 ((Door*)colliding_items[i])->getLock() == true ){

            if( ((Door*)colliding_items[i])->getUnlockable() == true){
                if( getKey() == true )
                    return 2;
                else {
                    tips->setText("Collect scripts first, then proceed to next floor");
                    return 1;
                }
            }
            else{
                tips->setText("Doors seem to be locked");
                return 1;
            }

        }
        // --------------------------------------------------------------------------

        // Player collide with exams ------------------------------------------------
        else if( typeid(*(colliding_items[i])) == typeid(ExamPaper) ){
            switch( ((ExamPaper*)colliding_items[i])->getIndex() ){
                case 1:
                    if( game->index == 1 ){
                        scene()->removeItem(game->level1->paper1);
                        delete game->level1->paper1;
                        break;
                    }
                    else if( game->index == 2 ){
                        scene()->removeItem(game->level2->paper1);
                        delete game->level2->paper1;
                        break;
                    }
                    /*
                    else{
                        scene()->removeItem(game->level3->paper1);
                        delete game->level3->paper1;
                        break;
                    }
                    */
                case 2:
                    if( game->index == 1 ){
                        scene()->removeItem(game->level1->paper2);
                        delete game->level1->paper2;
                        break;
                    }
                    else if( game->index == 2 ){
                        scene()->removeItem(game->level2->paper2);
                        delete game->level2->paper2;
                        break;
                    }
                    /*
                    else{
                        scene()->removeItem(game->level3->paper2);
                        delete game->level3->paper2;
                        break;
                    }
                    */
                case 3:
                    if( game->index == 1 ){
                        scene()->removeItem(game->level1->paper3);
                        delete game->level1->paper3;
                        game->level1->stairs->setWalk(true);
                        break;
                    }
                    else if( game->index == 2 ){
                        scene()->removeItem(game->level2->paper3);
                        delete game->level2->paper3;
                        break;
                    }
                    /*
                    else{
                        scene()->removeItem(game->level3->paper3);
                        delete game->level3->paper3;
                        break;
                    }
                    */
            }// END OF switch
            score->incrementScore();
            if( score->getScore() == 3 )
                setKey(true);
        }
        // --------------------------------------------------------------------------

    }// END OF for

    return 2;

}// END OF collide













