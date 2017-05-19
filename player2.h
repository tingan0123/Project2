#ifndef PLAYER2_H
#define PLAYER2_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "knight.h"
#include "priest.h"
#include "assassin.h"
#include "samurai.h"


class Player2: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
 Player2(QGraphicsItem * parent=0);

public slots:
    void spawn();
private:
    Knight *knight;
    Priest *priest;
    Assassin *assassin;
    Samurai *samurai;
};



#endif // PLAYER2_H
