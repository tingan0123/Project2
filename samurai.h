#ifndef SAMURAI_H
#define SAMURAI_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Samurai:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Samurai(bool owneer, QGraphicsItem * parent=0);
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
    int direction;
};

#endif // SAMURAI_H
