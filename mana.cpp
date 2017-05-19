#include "mana.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "game.h"
#include <QGraphicsPixmapItem>
#include "bullet2.h"
#include <QPointF>
#include "card.h"

extern Game * game;

Mana::Mana(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    mana = 7;
    setPixmap(QPixmap(":images/mana7.png"));
    //setRect(0, 0, 10, 10);
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(increaseMana()));
    timer->start(1000);

}

int Mana::getMana()
{
    return mana;
}

void Mana::setMana(int value)
{
    mana = value;
}

void Mana::drawMana()
{
    switch(mana){
        case 1:
            setPixmap(QPixmap(":images/mana1.png"));
            break;
        case 2:
            setPixmap(QPixmap(":images/mana2.png"));
            break;
        case 3:
            setPixmap(QPixmap(":images/mana3.png"));
            break;
        case 4:
            setPixmap(QPixmap(":images/mana4.png"));
            break;
        case 5:
            setPixmap(QPixmap(":images/mana5.png"));
            break;
        case 6:
            setPixmap(QPixmap(":images/mana6.png"));
            break;
        case 7:
            setPixmap(QPixmap(":images/mana7.png"));
            break;
        case 8:
            setPixmap(QPixmap(":images/mana8.png"));
            break;
        case 9:
            setPixmap(QPixmap(":images/mana9.png"));
            break;
        case 10:
            setPixmap(QPixmap(":images/mana10.png"));
            break;
        case 0:
            setPixmap(QPixmap(":images/mana0.png"));
            break;
    }
}

void Mana::increaseMana()
{
    if(mana < 10)
        mana++;
    switch(mana){
        case 1:
            setPixmap(QPixmap(":images/mana1.png"));
            break;
        case 2:
            setPixmap(QPixmap(":images/mana2.png"));
            break;
        case 3:
            setPixmap(QPixmap(":images/mana3.png"));
            break;
        case 4:
            setPixmap(QPixmap(":images/mana4.png"));
            break;
        case 5:
            setPixmap(QPixmap(":images/mana5.png"));
            break;
        case 6:
            setPixmap(QPixmap(":images/mana6.png"));
            break;
        case 7:
            setPixmap(QPixmap(":images/mana7.png"));
            break;
        case 8:
            setPixmap(QPixmap(":images/mana8.png"));
            break;
        case 9:
            setPixmap(QPixmap(":images/mana9.png"));
            break;
        case 10:
            setPixmap(QPixmap(":images/mana10.png"));
            break;
        case 0:
            setPixmap(QPixmap(":images/mana0.png"));
            break;



    }
}


