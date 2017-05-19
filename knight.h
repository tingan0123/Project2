#ifndef KNIGHT_H
#define KNIGHT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPointF>
#include <QGraphicsRectItem>
#include "card.h"


class Knight:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Knight(bool owner, QGraphicsItem * parent=0);
    int getHealth();
    void decreaseHealth(int value);
    int getAttack();
    void setOwner(bool ownerId);
    bool getOwner();
    int getDirection();
    void setDirection(int value);

public slots:
    void move();
    void attack_target();
private:
    int health;
    int attack;
    bool owner;
    int attack_range;
    int direction;

};

#endif // KNIGHT_H
