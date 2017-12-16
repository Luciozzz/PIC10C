#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QKeyEvent>
#include "Tower.h"


class Game: public QGraphicsView{
public:
    Game();

    void mousePressEvent(QMouseEvent* event);
    void keyPressEvent(QKeyEvent *key);

    QGraphicsScene* scene;
    Tower* t;
    QPoint* center;

};

#endif // GAME_H
