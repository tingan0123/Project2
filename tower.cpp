#include "tower.h"
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
#include <QList>
#include <QTimer>

extern Game * game;

Tower::Tower(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/castle.png"));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(attack_target()));
    timer->start(1000);

    health = 5000;
    attack = 50;
}

int Tower::getHealth()
{
    return health;
}

void Tower::decreaseHealth(int value)
{
    health = health - value;
}

int Tower::getattack()
{
    return attack;
}

void Tower::attack_target(){
    Bullet * bullet = new Bullet(200);
    bullet->setPos(x()-50,y()-50);
    bullet->setOwner(owner);
    bullet->setAttack(50);
    bullet->setOrigin(origin);
    game->scene->addItem(bullet);
}

void Tower::setOwner(bool ownerId){
    owner = ownerId;
}

bool Tower::getOwner()
{
    return owner;
}

void Tower::setOrigin(QPointF origin)
{
    this->origin = origin;
}
