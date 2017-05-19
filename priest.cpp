#include "priest.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "game.h"
#include <QGraphicsPixmapItem>
#include "bullet2.h"
#include "card.h"

extern Game * game;

Priest::Priest(bool owner, QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":images/priest.png"));

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(1000);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(attack_target()));
    timer->start(1000);

    health = 700;

    setOwner(owner);
    //attack_dest = QPointF(x()+50,y());
}

int Priest::getHealth()
{
    return health;
}

void Priest::decreaseHealth(int value)
{
    health = health - value;
}

int Priest::getAttack()
{
    return attack;
}

void Priest::setOwner(bool ownerId)
{
    owner = ownerId;
}

bool Priest::getOwner()
{
    return owner;
}

int Priest::getDirection()
{
    return direction;
}

void Priest::setDirection(int value)
{
    direction = value;
}


void Priest::move(){
    int STEP_SIZE = 20;

    int dir = 1;
    if(owner == 1)
        dir = 1;
    else
        dir = -1;

    double dy = 0;
    double dx = STEP_SIZE;

    if(owner == 1){
        if ((250-40 <= y()) && (y() <= 350+40) && (x()-dx <200)){
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

void Priest::attack_target(){

    Bullet2 * bullet2 = new Bullet2(140);
    bullet2->setPos(x() - 50,y() - 50);
    bullet2->setAttack(50);
    bullet2->setOwner(owner);
    game->scene->addItem(bullet2);


}
