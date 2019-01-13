#include "customize.h"
#include "game.h"
#include "meni.h"
#include <QLabel>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsPixmapItem>

extern Meni * pocetak;
extern Game * game;

Customize::Customize(QWidget * parent):QGraphicsScene(parent){

    setSceneRect(0, 0, 800, 600);

    QWidget * window = new QWidget();

    //dugme--------------------------
    start = new QPushButton("START");
    connect(start,SIGNAL(clicked()),this,SLOT(imeProfesora()));
    //-------------------------------

    // Background stuff -------------------------------------------------------------
    QGraphicsPixmapItem * background = new QGraphicsPixmapItem();
    background->setPixmap(QPixmap(":/images/menuBackground.jpg"));
    background->setPos(0,0);
    addItem(background);
    // ------------------------------------------------------------------------------

    //za ucitavanje imena-------------------------
    name1 = new QLineEdit("Snape");
    name2 = new QLineEdit("McGonagall");
    name3  = new QLineEdit("Dumbledore");
    name4  = new QLineEdit("Flitwick");
    name5  = new QLineEdit("Hagrid");
    name6  = new QLineEdit("Filch");


    QLabel *label1 = new QLabel("Profesor 1:");
    QLabel *label2 = new QLabel("Profesor 2:");
    QLabel *label3 = new QLabel("Profesor 3:");
    QLabel *label4 = new QLabel("Profesor 4:");
    QLabel *label5 = new QLabel("Profesor 5:");
    QLabel *label6 = new QLabel("Profesor 6:");
    //--------------------------------------------

    //pakovanje ------------------------
    QVBoxLayout *vbox = new QVBoxLayout();

    QHBoxLayout *h1 = new QHBoxLayout();
    h1->addWidget(label1);
    h1->addWidget(name1);
    vbox->addItem(h1);

    QHBoxLayout *h2 = new QHBoxLayout();
    h2->addWidget(label2);
    h2->addWidget(name2);
    vbox->addItem(h2);

    QHBoxLayout *h3 = new QHBoxLayout();
    h3->addWidget(label3);
    h3->addWidget(name3);
    vbox->addItem(h3);

    QHBoxLayout *h4 = new QHBoxLayout();
    h4->addWidget(label4);
    h4->addWidget(name4);
    vbox->addItem(h4);

    QHBoxLayout *h5 = new QHBoxLayout();
    h5->addWidget(label5);
    h5->addWidget(name5);
    vbox->addItem(h5);

    QHBoxLayout *h6 = new QHBoxLayout();
    h6->addWidget(label6);
    h6->addWidget(name6);
    vbox->addItem(h6);

    vbox->addWidget(start);

    window->setLayout(vbox);
    window->resize(400,400);
    window->move(200,100);
    window->setStyleSheet("background-color: rgba( 255, 255, 255, 10% );" );
    addWidget(window);
    //-------------------------------------------

}

void Customize::imeProfesora(){

    pocetak->name1 = name1->text();
    pocetak->name2 = name2->text();
    pocetak->name3 = name3->text();
    pocetak->name4 = name4->text();
    pocetak->name5 = name5->text();
    pocetak->name6 = name6->text();

    pocetak->hide();
    game = new Game();
}

