#include "headers/meni.h"
#include "headers/game.h"
#include "headers/customize.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsWidget>
#include <QGraphicsPixmapItem>

extern Game * game;

Meni::Meni(){
    scene = new QGraphicsScene(this);
    window = new QWidget();

    this->setWindowTitle("EscapeFromCollege");      //naslov

    scene->setSceneRect(0, 0, 800, 600);            //rezolucija

    // Background stuff -------------------------------------------------------------
    QGraphicsPixmapItem * background = new QGraphicsPixmapItem();
    background->setPixmap(QPixmap(":/images/images/menuBackground.jpg"));
    background->setPos(0,0);
    scene->addItem(background);
    // ------------------------------------------------------------------------------

    start = new QPushButton("START");
    connect(start,SIGNAL(clicked()),this,SLOT(dodajIgraca()));
    customize = new QPushButton("CUSTOMIZE PROFESORS");
    connect(customize,SIGNAL(clicked()),this,SLOT(customizee()));
    QVBoxLayout *vbox = new QVBoxLayout();

    QLabel *label = new QLabel("Name");
    name = new QLineEdit("John Doe");
    QHBoxLayout *hbox1 = new QHBoxLayout();
    hbox1->addWidget(label);
    hbox1->addWidget(name);
    vbox->addItem(hbox1);

    male = new QRadioButton("MALE");
    female = new QRadioButton("FEMALE");

    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->addWidget(male);
    hbox->addWidget(female);
    vbox->addItem(hbox);
    male->setChecked(1);

    // dugmici ----------------------
    vbox->addWidget(start);
    vbox->addWidget(customize);
    // ------------------------------

    window->setLayout(vbox);
    window->resize(400,400);
    window->move(200,100);
    window->setStyleSheet("background-color: rgba( 255, 255, 255, 10% );" );
    //window->setWindowOpacity(0.5);

    scene->addWidget(window);
    // -------------------------------


    //deo rezolucije -----------------------------------
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //---------------------------------------------------

    this->setScene(scene);
    this->show();

}// END OF constructor

void Meni::dodajIgraca(){

    playerName = name->text();
    if(male->isChecked())
        gender = true;
    else
        gender = false;

    hide();
    game = new Game();

}// END OF dodajIgraca

void Meni::customizee(){

    Customize *c = new Customize();
    setScene(c);
}
