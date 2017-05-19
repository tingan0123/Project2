#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPointF>

class Bullet:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(int attack_range, QGraphicsItem * parent=0);
    void setAttack(int value);
    void setOwner(bool value);
    bool getOwner();
    void setOrigin(QPointF origin);
public slots:
    void move();
private:
    int attack;
    bool owner;
    QPointF origin;
};

#endif // BULLET_H
