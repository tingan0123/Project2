#ifndef BULLET2_H
#define BULLET2_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Bullet2:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet2(int attack_range, QGraphicsItem * parent=0);
    void setAttack(int value);
    void setOwner(bool value);
    bool getOwner();
public slots:
    void move();
private:
    int attack;
    bool owner;
};

#endif // BULLET2_H
