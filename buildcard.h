#ifndef BUILDCARD_H
#define BUILDCARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Buildcard: public QGraphicsPixmapItem{
public:
    Buildcard(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDCARD_H
