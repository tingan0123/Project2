#ifndef PRIEST_H
#define PRIEST_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Priest:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Priest(bool owner, QGraphicsItem * parent=0);
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

#endif // PRIEST_H
