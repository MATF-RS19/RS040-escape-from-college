#ifndef TIPS_H
#define TIPS_H

#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QString>


class Tips: public QGraphicsTextItem{

public:
    Tips( QString text, QGraphicsItem *parent = 0 );

    QString getText();
    void setText( QString _text );

private:
    QString text;

}; // END OF class

#endif // TIPS_H
