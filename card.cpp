#include "card.h"
#include "knight.h"
#include <game.h>


extern Game *game;

Card::Card(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{

}

void Card::setId(int value)
{
    id = value;
}

int Card::getId()
{
    return id;
}

void Card::setMana(int value)
{
    cardMana = value;
}

int Card::getMana()
{
    return cardMana;
}

void Card::setOwner(int value)
{
    owner = value;
}

int Card::getOwner()
{
    return owner;
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!game->build){
        if(id == 1){
            game->build = new Knight(1);
            //game->setCursor(QString(":/images/knight3.png"));
           }
        else if (id == 2){
            game->build = new Assassin(1);
            //game->setCursor(QString(":/images/assassin.png"));
        }
        else if (id == 3){
            game->build = new Priest(1);
            //game->setCursor(QString(":/images/priest.png"));
        }
        else if (id == 4){
            game->build = new Samurai(1);
            //game->setCursor(QString(":/images/samurai2.png"));
        }
    }
    game->cardToPlace1 = this;
}

