#include "Game.h"
#include <QGraphicsScene>
#include "Tower.h"
#include "Bullet.h"

Game::Game(){
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,800);
    setScene(scene);

    //create a tower:
    Tower* t = new Tower();
    scene->addItem(t);

    setFixedSize(800, 800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Game::mousePressEvent(QMouseEvent *event){
    //create the bullet
    Bullet* bullet = new Bullet();
    bullet->setPos(event->pos());
    bullet->setRotation(40);
    scene->addItem(bullet);
}
