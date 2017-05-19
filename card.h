#ifndef CARD_H
#define CARD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>


class Card: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
     Card(QGraphicsItem * parent=0);
     void mousePressEvent(QGraphicsSceneMouseEvent *event);
     void setId(int value);
     int getId();
     void setMana(int value);
     int getMana();
     void setOwner(int valiue);
     int getOwner();
private:
     int id;
     int cardMana;
     int owner;
};

#endif // CARD_H
