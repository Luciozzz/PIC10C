#include "Game.h"
#include <QGraphicsScene>
#include <QMouseEvent>
#include "Tower.h"
#include "Bullet.h"
#include <QKeyEvent>
#include <QtMath>

Game::Game(){
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,800);
    setScene(scene);

    //create a tower:
    t = new Tower();
    center = new QPoint(365, 369);
    t->setPos(center->x(), center->y());
    scene->addItem(t);

    setFixedSize(800, 800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Game::mousePressEvent(QMouseEvent *event){
    //create the bullet
    Bullet* bullet = new Bullet();

    //set start position to be at the center of tower:
    bullet->setPos(center->x()+35, center->y()+31);

    //set the angle according to the mouse click:

    QLineF line(QPointF(t->x()+35, t->y()+31),QPointF(event->x(), event->y()));
    int theta = line.angle()+90;

    bullet->setRotation(theta);
    scene->addItem(bullet);
}

void Game::keyPressEvent(QKeyEvent *key){
    if(key->key() == Qt::Key_W){
        center->setY(center->y()-10);
        t->setPos(center->x(), center->y());
    }else if(key->key() == Qt::Key_A){
        center->setX(center->x()-10);
        t->setPos(center->x(), center->y());
    }else if(key->key() == Qt::Key_S){
        center->setY(center->y()+10);
        t->setPos(center->x(), center->y());
    }else if(key->key() == Qt::Key_D){
        center->setX(center->x()+10);
        t->setPos(center->x(), center->y());
    }
}

