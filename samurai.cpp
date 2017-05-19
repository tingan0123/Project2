#include "samurai.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "game.h"
#include <QGraphicsPixmapItem>
#include "bullet2.h"
#include "card.h"

extern Game * game;

Samurai::Samurai(bool owner, QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":images/samurai2.png"));
    //setRect(0, 0, 30, 30);

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(1000);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(attack_target()));
    timer->start(1000);

    health = 2500;

    setOwner(owner);

    //attack_dest = QPointF(x()+50,y());
}

int Samurai::getHealth()
{
    return health;
}

void Samurai::decreaseHealth(int value)
{
    health = health - value;
}

int Samurai::getAttack()
{
    return attack;
}

void Samurai::setOwner(bool ownerId)
{
    owner = ownerId;
}

bool Samurai::getOwner()
{
    return owner;
}

int Samurai::getDirection()
{
    return direction;
}

void Samurai::setDirection(int value)
{
    direction = value;
}


void Samurai::move(){
    int STEP_SIZE = 10;

    int dir = 1;
    if(owner == 1)
        dir = 1;
    else
        dir = -1;

    double dy = 0;
    double dx = STEP_SIZE;

    if(owner == 1){
        if ((250-40 <= y()) && (y() <= 350+40) && (x()-dx < 200)){
            setPos( 200, y()+dy);
        }
        else if ((100-40 <= y()) && (y() <= 180+40) && (x()-dx <280)){
            setPos( 280, y()+dy);
        }
        else if ((420-40 <= y()) && (y() <= 500+40) && (x()-dx < 280)){
            setPos( 280, y()+dy);
        }
        else{
            setPos(x() - dir*dx, y()+dy);
        }
    }
    else{
        if ((250-40 <= y()) && (y()<=350+40) && (x()+40+dx > 600)){
            setPos( 600-40, y()+dy);
        }

        else if ((100-40 <= y()) && (y() <=180+40) && (x()+40+dx > 520)){
            setPos( 520-40, y()+dy);
        }

        else if ((420-40 <= y()) && (y() <= 500+40) && (x()+40+dx > 520)){
            setPos( 520-40, y()+dy);
        }
        else{
            setPos(x() - dir*dx, y()+dy);
        }
    }
}

void Samurai::attack_target(){

    Bullet2 * bullet2 = new Bullet2(80);
    bullet2->setPos(x() - 20,y() - 20);
    bullet2->setAttack(100);
    bullet2->setOwner(owner);
    game->scene->addItem(bullet2);

}
