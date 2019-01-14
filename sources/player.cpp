#include "headers/player.h"
#include "headers/stairs.h"
#include "headers/wall.h"
#include "headers/door.h"
#include "headers/exampaper.h"
#include "headers/game.h"
#include "headers/score.h"
#include "headers/tips.h"
#include "headers/profesor.h"
#include "headers/meni.h"
#include <QList>
#include <QPointF>
#include <stdlib.h>
#include <QDebug>

extern Game * game;
extern Tips * tips;
extern Score * score;
extern Meni * pocetak;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    gender = pocetak->gender;
    key = false;
    if( gender == true )
        setPixmap(QPixmap(":/images/images/maleRight.png"));
    else
        setPixmap(QPixmap(":/images/images/femaleRight.png"));
    setPos(70, 405);
    setScale(1.3);

}// END OF constructor

void Player::keyPressEvent(QKeyEvent *event){

    if( event->key() == Qt::Key_W ){
        if( gender == true )
            setPixmap(QPixmap(":/images/images/maleUp.png"));
        else
            setPixmap(QPixmap(":/images/images/femaleUp.png"));

        setPos( x(), y() - 3 );
        if( collide() == 1 )
            setPos( x(), y() + 3 );
        else
        tips->setText("Everything here is made-up!");

    }
    else if( event->key() == Qt::Key_S ){

        if( gender == true )
            setPixmap(QPixmap(":/images/images/maleDown.png"));
        else
            setPixmap(QPixmap(":/images/images/femaleDown.png"));

        setPos( x(), y() + 3 );
        if( collide() == 1 )
            setPos( x(), y() - 3 );
        else
        tips->setText("Everything here is made-up!");

    }
    else if( event->key() == Qt::Key_A ){

        if( gender == true )
            setPixmap(QPixmap(":/images/images/maleLeft.png"));
        else
            setPixmap(QPixmap(":/images/images/femaleLeft.png"));

        setPos( x() - 3, y() );
        if( collide() == 1 )
            setPos( x() + 3, y() );
        else
        tips->setText("Everything here is made-up!");

    }
    else if( event->key() == Qt::Key_D ){

        if( gender == true )
            setPixmap(QPixmap(":/images/images/maleRight.png"));
        else
            setPixmap(QPixmap(":/images/images/femaleRight.png"));

        setPos( x() + 3, y() );
        if( collide() == 1 )
            setPos( x() - 3, y() );
        else if( collide() == 4 ){
            clearFocus();
            game->level3->profesor1->setFlag(QGraphicsItem::ItemIsFocusable);
            game->level3->profesor1->setFocus();
            game->level3->profesor1->finishGame = true;
        }
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
    else if( event->key() == Qt::Key_Escape ){
        exit(0);
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
 * 4 -> Finished the game
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

            if( game->index == 1 && getKey() == false ){
                tips->setPlainText("Collect the scripts first, remember?");
                return 1;
            }
            if( game->index == 2 && ((Stairs*)colliding_items[i])->getWalk() == false ){
                tips->setPlainText("That's dangerous!");
                return 1;
            }
            if( game->index == 3 && ((Stairs*)colliding_items[i])->getWalk() == true ){
                tips->setPlainText("You made it little thief! Press Esc");
                return 4;
            }
            if( game->index == 3 && ((Stairs*)colliding_items[i])->getWalk() == false ){
                tips->setPlainText("You made it this far, just 3 more!");
                return 1;
            }

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

            if( ((ExamPaper*)colliding_items[i])->getIndex() == 3 &&
                game->index == 1 )
                    game->level1->stairs->setWalk(true);

            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            score->incrementScore();
            if( score->getScore() == 3 )
                setKey(true);

        }
        // --------------------------------------------------------------------------

    }// END OF for

    return 2;

}// END OF collide













