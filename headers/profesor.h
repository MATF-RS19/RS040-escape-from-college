#ifndef PROFESOR_H
#define PROFESOR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QString>
#include <QKeyEvent>

class Profesor: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Profesor(QString debljina,QString ime_prezime,int iks,int ip,int iks1,int ip1, QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);
    void setName(QString name);
    bool finishGame; // Player sends a signal through finishGame

public slots:
    void move();

private:
    QString debljina;
    QString ime_prezime;
    int X;
    int Y;
    int X1;
    int Y1;
    bool idemDesno = true;
    bool idemDole = true;

    bool collide();
};


#endif // PROFESOR_H
