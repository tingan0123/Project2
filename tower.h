#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Tower:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(QGraphicsItem * parent=0);
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

#endif // TOWER_H
