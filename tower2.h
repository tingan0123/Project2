#ifndef TOWER2_H
#define TOWER2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Tower2:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower2(QGraphicsItem * parent=0);
    int getHealth();
    void decreaseHealth(int value);
    int getattack();
    void setOwner(bool ownerId);
    bool getOwner();
    void setOrigin(QPointF origin);
public slots:
    void attack_target();
private:
    QGraphicsPolygonItem * attack_area;
    QPointF attack_dest;
    int health;
    int attack;
    bool owner;
    QPointF origin;

};

#endif // TOWER2_H
