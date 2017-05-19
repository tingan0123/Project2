#include "buildcard.h"
#include <game.h>
#include "knight.h"
#include "samurai.h"
#include "priest.h"
#include "assassin.h"

extern Game * game;

Buildcard::Buildcard(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/samurai.png"));
}

void Buildcard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!game->build){
        game->build = new Card();
        game->setCursor(QString(":/images/samurai2.png"));
    }
}
