#ifndef CUSTOMIZE_H
#define CUSTOMIZE_H

#include <QPushButton>
#include <QLineEdit>
#include <QGraphicsScene>
#include <QObject>
#include <QWidget>

class Customize: public QGraphicsScene{
    Q_OBJECT
public:
    Customize(QWidget * parent = 0);

public slots:
    void imeProfesora();

private:
    QPushButton *start;

    QLineEdit *name1;
    QLineEdit *name2;
    QLineEdit *name3;
    QLineEdit *name4;
    QLineEdit *name5;
    QLineEdit *name6;
};


#endif // CUSTOMIZE_H
