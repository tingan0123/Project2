#ifndef MANA_H
#define MANA_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPointF>
#include <QGraphicsRectItem>
#include "card.h"


class Mana:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Mana(QGraphicsItem * parent=0);
    int getMana();
    void setMana(int value);
    void drawMana();
public slots:
    void increaseMana();
private:
    int mana;
};


#endif // MANA_H
