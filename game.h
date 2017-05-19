#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include "mana.h"
#include "knight.h"
#include "priest.h"
#include "assassin.h"
#include "samurai.h"
#include <QGraphicsPixmapItem>
#include "tower.h"
#include <QGraphicsScene>
#include "card.h"



class Game: public QGraphicsView{
public:
    Game();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void setCursor(QString filename);
    void createNewCard(bool player);
    void drawCards();
    void increase();

    QGraphicsScene * scene;
    Mana * mana1;
    Mana * mana2;
    Knight * knight;
    Priest * priest;
    Assassin * assassin;
    Samurai * samuai;
    QGraphicsPixmapItem * cursor;
    QGraphicsItem * build;
    QList<Card*> player_card1;
    QList<Card*> player_card2;
    QList<Card*> deckCard;
    Card* cardToPlace1, *cardToPlace2;
};

#endif // GAME_H
