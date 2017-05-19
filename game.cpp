#include "game.h"
#include <QGraphicsScene>
#include "tower.h"
#include "tower2.h"
#include "bullet.h"
#include "mana.h"
#include "knight.h"
#include "priest.h"
#include "assassin.h"
#include "samurai.h"
#include "buildcard.h"
#include <QTimer>
#include "card.h"
#include "player2.h"

Game::Game(): QGraphicsView(){
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1000,600);

    setScene(scene);

    Tower * t1 = new Tower();
    Tower * t2 = new Tower();
    Tower2 * t3 = new Tower2();
    Tower2 * t4 = new Tower2();
    Tower2 * t5 = new Tower2();
    Tower2 * t6 = new Tower2();

    t1->setPos(600,250);
    t1->setOrigin(QPointF(600,250));
    t2->setPos(100,250);
    t2->setOrigin(QPointF(100,250));
    t3->setPos(520,100);
    t3->setOrigin(QPointF(520,100));
    t4->setPos(200,100);
    t4->setOrigin(QPointF(200,100));
    t5->setPos(520,420);
    t5->setOrigin(QPointF(520,420));
    t6->setPos(200,420);
    t6->setOrigin(QPointF(200,420));

    t1->setOwner(1);
    t2->setOwner(0);
    t3->setOwner(1);
    t4->setOwner(0);
    t5->setOwner(1);
    t6->setOwner(0);

    scene->addItem(t1);
    scene->addItem(t2);
    scene->addItem(t3);
    scene->addItem(t4);
    scene->addItem(t5);
    scene->addItem(t6);

    setFixedSize(1000,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    mana1 = new Mana();
    mana1->setPos(mana1->x(),mana1->y()+25);
    scene->addItem(mana1);

    mana2 = new Mana();
    mana2->setPos(mana2->x()+700,mana2->y()+25);
    scene->addItem(mana2);


    deckCard.append(new Card());
    deckCard.append(new Card());

    for(size_t i=0;i<2;i++){
        createNewCard(0);
        createNewCard(1);
    }
    drawCards();

   Player2 *player2 = new Player2();
}

void Game::mousePressEvent(QMouseEvent *event){
    if (build){
        if(event->pos().x() < 600){
            int consume = cardToPlace1->getMana();
            if(consume <= mana2->getMana()){
                mana2->setMana(mana2->getMana() - consume);
                mana2->drawMana();
                scene->addItem(build);
                build->setPos(event->pos());
                player_card1.removeAll(cardToPlace1);
                cardToPlace1 = nullptr;
                cursor = nullptr;
                build = nullptr;
                createNewCard(1);
                drawCards();
             }
        }
    }
    else {
        QGraphicsView::mousePressEvent(event);
    }
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if (cursor){
        cursor->setPos(event->pos());
    }
}

void Game::setCursor(QString filename)
{
    if (cursor){
        scene->removeItem(cursor);
        delete cursor;
    }

   cursor = new QGraphicsPixmapItem();
   cursor->setPixmap(QPixmap(filename));
   scene->addItem(cursor);

}

void Game::createNewCard(bool player){
    int randNum = rand() % 4 + 1;
    Card * newCard = new Card();
    newCard->setId(randNum);
    newCard->setOwner(player);
    if(randNum == 1)
        newCard->setMana(5);
    else if (randNum == 2)
        newCard->setMana(4);
    else if (randNum == 3)
        newCard->setMana(3);
    else if (randNum == 4)
        newCard->setMana(9);
    if (player == 1)
        player_card1.append(newCard);
    else
        player_card2.append(newCard);
}

void Game::drawCards()
{
    for(size_t i=0;i<player_card1.size();i++){
        Card *item = player_card1[i];
        if(item->getId() == 1){
            item->setPixmap(QPixmap(":images/knight.png"));
            item->setPos(800, 150*(i+1));
            scene->addItem(item);
        }
        else if (item->getId() == 2){
            item->setPixmap(QPixmap(":images/assassin2.png"));
            item->setPos(800, 150*(i+1));
            scene->addItem(item);
        }
        else if (item->getId() == 3){
            item->setPixmap(QPixmap(":images/priest2.png"));
            item->setPos(800, 150*(i+1));
            scene->addItem(item);
        }
        else if (item->getId() == 4){
            item->setPixmap(QPixmap(":images/samurai.png"));
            item->setPos(800, 150*(i+1));
            scene->addItem(item);
        }
    }
}
