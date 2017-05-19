#include "bullet2.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "game.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "tower.h"
#include "tower2.h"

extern Game * game;

Bullet2::Bullet2(int attack_range, QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    //setPixmap(QPixmap(":images/bullet.png"));
    //setRect(0,0,attack_range, attack_range);

    if(attack_range == 100){
        setPixmap(QPixmap(":images/bullet100.png"));
    }
    else if(attack_range == 140){
        setPixmap(QPixmap(":images/bullet140.png"));
    }
    else if(attack_range == 80){
        setPixmap(QPixmap(":images/bullet80.png"));
    }
    else if(attack_range == 40){
        setPixmap(QPixmap(":images/bullet40.png"));
    }

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(1000);
}

void Bullet2::setAttack(int value)
{
    attack = value;
}


void Bullet2::move(){
    int STEP_SIZE = 10;
    double theta = rotation();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Tower)){
            Tower* item = static_cast<Tower*>(colliding_items[i]);
            if(item->getOwner() != owner){
                item->decreaseHealth(attack);
                if(item->getHealth() < 0){
                    scene()->removeItem(colliding_items[i]);
                    scene()->removeItem(this);

                    delete colliding_items[i];
                }
            }
        }
        else if(typeid(*(colliding_items[i])) == typeid(Tower2)){
            Tower2* item = static_cast<Tower2*>(colliding_items[i]);
            if(item->getOwner() != owner){
            item->decreaseHealth(attack);
            if(item->getHealth() < 0){
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);

                delete colliding_items[i];
               }
           }
        }
    }
    delete this;
    return;
}

void Bullet2::setOwner(bool value)
{
    owner = value;
}

bool Bullet2::getOwner()
{
    return owner;
}

