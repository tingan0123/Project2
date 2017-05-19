#include "knight.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "game.h"
#include <QGraphicsPixmapItem>
#include "bullet2.h"
#include <QPointF>
#include "card.h"

extern Game * game;

Knight::Knight(bool owner, QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":images/knight3.png"));
    //setRect(0, 0, 10, 10);

    health = 1500;
    attack_range = 3;

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(1000);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(attack_target()));
    timer->start(1000);

    setOwner(owner);
    //attack_dest = QPointF(x()+50,y());
}

int Knight::getHealth()
{
  return health;
}

void Knight::decreaseHealth(int value)
{
    health = health - value;
}

int Knight::getAttack()
{
    return attack;
}

void Knight::setOwner(bool ownerId)
{
    owner = ownerId;
}

bool Knight::getOwner()
{
    return owner;
}

int Knight::getDirection()
{
    return direction;
}

void Knight::setDirection(int value)
{
    direction = value;
}


void Knight::move(){
    int STEP_SIZE = 50;

    int dir = 1;
    if(owner == 1)
        dir = 1;
    else
        dir = -1;

    double dy = 0;
    double dx = STEP_SIZE;
    if(owner == 1){
        if ((250-40 <= y()) && (y()<=350+40) && (x()-dx <200)){
            setPos( 200, y()+dy);
        }

        else if ((100-40 <= y()) && (y() <=180+40) && (x()-dx <280)){
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

void Knight::attack_target(){
    Bullet2 * bullet2 = new Bullet2(100);
    bullet2->setPos(x()- 30,y() - 30);
    bullet2->setAttack(50);
    bullet2->setOwner(owner);
    game->scene->addItem(bullet2);

}
