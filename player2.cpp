#include "player2.h"
#include "knight.h"
#include <game.h>
#include <QTimer>
#include <card.h>

extern Game *game;

Player2::Player2(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    timer->start(1000);
}

void Player2::spawn()
{
    Card *first = game->player_card2[0];
    int cardMana = game->player_card2[0]->getMana();
    game->cardToPlace2 = first;

    if(game->mana1->getMana() >= cardMana ){
        game->mana1->setMana(game->mana1->getMana() - cardMana);
        game->mana1->drawMana();
        QGraphicsItem *item;
        if(first->getId() == 1){
            item = new Knight(0);
        }
        else if(first->getId() == 2){
            item = new Assassin(0);
        }
        else if(first->getId() == 3){
            item = new Priest(0);
        }
        else if(first->getId() == 4){
            item = new Samurai(0);
        }

        item->setPos(210, 250);
        game->scene->addItem(item);
        game->player_card2.removeAll(game->cardToPlace2);
        game->createNewCard(0);
    }
}


