#include "tips.h"
#include <QFont>

Tips::Tips(QString text, QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText( QString("Tips: ") + text );
    setDefaultTextColor(Qt::blue);
    setFont( QFont( "helvetica", 16 ) );
    setPos(300, 5);

}// END OF constructor

QString Tips::getText() { return text; }

void Tips::setText(QString _text){
    text = _text;
    setPlainText( QString("Tips: ") + text );
}
