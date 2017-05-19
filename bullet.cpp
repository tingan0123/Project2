#include "bullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "game.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

extern Game * game;

Bullet::Bullet(int attack_range, QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    //setPixmap(QPixmap(":images/bullet.png"));
    //setRect(0,0,attack_range,attack_range);
    if(attack_range == 200){
        setPixmap(QPixmap(":images/bullet200.png"));
    }
    else if(attack_range == 180){
        setPixmap(QPixmap(":images/bullet180.png"));
    }

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(1000);

}

void Bullet::setAttack(int value)
{
    attack = value;
}

void Bullet::setOwner(bool value)
{
    owner = value;
}

bool Bullet::getOwner()
{
    return owner;
}

void Bullet::setOrigin(QPointF origin)
{
    this->origin = origin;
}

void Bullet::move(){
    int STEP_SIZE = 10;
    double theta = rotation();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Knight)){
            Knight* item = static_cast<Knight*>(colliding_items[i]);
            if(item->getOwner() != owner){
                item->decreaseHealth(attack);
                if(item->getHealth() < 0){
                    scene()->removeItem(colliding_items[i]);
                    scene()->removeItem(this);

                    delete colliding_items[i];
                    delete this;
                    return;
                }
            }
        }
        else if(typeid(*(colliding_items[i])) == typeid(Assassin)){
                Assassin* item = static_cast<Assassin*>(colliding_items[i]);
                if(item->getOwner() != owner){
                    item->decreaseHealth(attack);
                    if(item->getHealth() < 0){
                        scene()->removeItem(colliding_items[i]);
                        scene()->removeItem(this);

                        delete colliding_items[i];
                        delete this;
                        return;
                    }
                }
        }
        else if(typeid(*(colliding_items[i])) == typeid(Priest)){
                Priest* item = static_cast<Priest*>(colliding_items[i]);
                if(item->getOwner() != owner){
                    item->decreaseHealth(attack);
                    if(item->getHealth() < 0){
                        scene()->removeItem(colliding_items[i]);
                        scene()->removeItem(this);

                        delete colliding_items[i];
                        delete this;
                        return;
                    }
                 }
        }
        else if(typeid(*(colliding_items[i])) == typeid(Samurai)){
                Samurai* item = static_cast<Samurai*>(colliding_items[i]);
                if(item->getOwner() != owner){
                    item->decreaseHealth(attack);
                    if(item->getHealth() < 0){
                        scene()->removeItem(colliding_items[i]);
                        scene()->removeItem(this);

                        delete colliding_items[i];
                        delete this;
                        return;
                }
            }
        }
    }
}

