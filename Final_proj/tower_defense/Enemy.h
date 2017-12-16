#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include "Tower.h"

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem* parent = 0);
    void setSpeed(int s);
public slots:
    void move_forward();
private:
    int speed = 5;
};

#endif // ENEMY_H
