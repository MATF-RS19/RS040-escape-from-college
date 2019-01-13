#ifndef MENI_H
#define MENI_H
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>
#include <QGraphicsView>
#include <QObject>
#include <QWidget>

class Meni: public QGraphicsView{
    Q_OBJECT
public:
    Meni();
    // profesor names
    QString name1 = "Snape";
    QString name2 = "McGonagall";
    QString name3 = "Dumbledore";
    QString name4 = "Flitwick";
    QString name5 = "Hagrid";
    QString name6 = "Filch";
    QString playerName = "John Doe";
    bool gender; // true -> male, false -> female
    QWidget* window;

public slots:
    void customizee();
    void dodajIgraca();
private:
    QGraphicsScene *scene;
    QPushButton *start;
    QPushButton *customize;

    QLineEdit *name;

    QRadioButton *male;
    QRadioButton *female;

};

#endif // MENI_H
