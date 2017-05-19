#include "tower2.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include "bullet.h"
#include <QPointF>
#include <QLineF>
#include "game.h"
#include <QTimer>
#include <QGraphicsRectItem>


extern Game * game;

Tower2::Tower2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/castle2.png"));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(attack_target()));
    timer->start(1000);

    health = 4000;
}

int Tower2::getHealth()
{
    return health;
}

void Tower2::decreaseHealth(int value)
{
    health = health - value;
}

int Tower2::getattack()
{
    return attack;
}

void Tower2::setOwner(bool ownerId)
{
    owner = ownerId;
}

bool Tower2::getOwner()
{
    return owner;
}

void Tower2::setOrigin(QPointF origin)
{
    this->origin = origin;
}

void Tower2::attack_target(){

    Bullet * bullet = new Bullet(180);
    bullet->setPos(x()-50,y()-50);
    bullet->setOwner(owner);
    bullet->setAttack(40);
    game->scene->addItem(bullet);

}
