#include <QApplication>
#include "headers/game.h"
#include "headers/meni.h"

Game * game;
Meni * pocetak;

int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    pocetak = new Meni();
    //game = new Game();

    return a.exec();
}
