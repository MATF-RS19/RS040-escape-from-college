#include "profesor.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "player.h"
#include "tips.h"
#include <QGraphicsItem>


extern Player * player;
extern Tips * tips;

Profesor::Profesor(QString debljina,QString name,int iks,int ip,int iks1,int ip1, QGraphicsItem * parent):ime_prezime(name),X(iks),Y(ip),X1(iks1),Y1(ip1), QGraphicsPixmapItem(parent){

    setPos(iks,ip);
    setScale(1.5);
    QTimer *timer= new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    if( debljina == "debeo" )
        timer->start(30);
    else timer->start(20);

}

void Profesor::keyPressEvent(QKeyEvent *event){

    if( event->key() == Qt::Key_Escape ){
        if( collide() == true )
            exit(0);
        }

}// END OF keyPressEvent

void Profesor::setName(QString name){
    ime_prezime = name;
}

void Profesor::move(){

    if( collide() == true ){}
    else{
    if(X<X1 && Y == Y1){
        if (idemDesno){

            if (pos().x() <= X1-2){
                setPixmap(QPixmap(":/images/profRight.png"));
                setPos(x()+2,y());
            }else{
                idemDesno= false;
                setPixmap(QPixmap(":/images/profLeft.png"));
                setPos(x()-2,y());
            }
         }
         if (!idemDesno){
            if(pos().x() >= X+2){
                setPixmap(QPixmap(":/images/profLeft.png"));
                setPos(x()-2,y());
            }else{
                idemDesno=true;
                setPixmap(QPixmap(":/images/profRight.png"));
                setPos(x()+2,y());
            }
        }
    }else if(Y<Y1 && X==X1){

        if(idemDole){
            if(pos().y() <=Y1-2){
                setPixmap(QPixmap(":/images/profDown.png"));
                setPos(x(),y()+2);
            }else{
                idemDole=false;
                setPixmap(QPixmap(":/images/profUp.png"));
                setPos(x(),y()-2);
            }
        }
        if(!idemDole){
            if(pos().y() >=Y+2){
                setPixmap(QPixmap(":/images/profUp.png"));
                setPos(x(),y()-2);
            }else{
                idemDole=true;
                setPixmap(QPixmap(":/images/profDown.png"));
                setPos(x(),y()+2);
            }

        }
    }
    }// END OF else
}// END OF move()

bool Profesor::collide(){

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0; i < colliding_items.size(); ++i){

        // Profesor collides with Player --------------------------------------------
        if( typeid(*(colliding_items[i])) == typeid(Player) ){
            player->clearFocus();
            setFlag(QGraphicsItem::ItemIsFocusable);
            setFocus();
            tips->setPlainText("Profesor " + ime_prezime + " caught you! Press Esc to exit");
            return true;

        }
        // --------------------------------------------------------------------------

    }// END OF for
    return false;

}// END OF collide















