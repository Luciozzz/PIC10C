#include "Game.h"
#include <QGraphicsScene>
#include <QMouseEvent>
#include "Tower.h"
#include "Bullet.h"
#include <QKeyEvent>
#include <QtMath>
#include <QList>
#include <QPushButton>
#include "Enemy.h"
#include "Tower.h"
#include <algorithm>
#include <QTime>
#include <QCoreApplication>

Game::Game(){
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,800);
    setScene(scene);

//    //choose difficulty:
//    QPushButton* easy = new QPushButton();
//    easy->setText("EASY");

    //create a tower:
    t = new Tower();
    center = new QPoint(365, 600);
    t->setPos(center->x(), center->y());
    scene->addItem(t);

    setFixedSize(800, 800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create an enemy list:
    Enemy* e1 = new Enemy();
    Enemy* e2 = new Enemy();
    Enemy* e3 = new Enemy();
    Enemy* e4 = new Enemy();
    Enemy* e5 = new Enemy();
    Enemy* e6 = new Enemy();
    Enemy* e7 = new Enemy();
    Enemy* e8 = new Enemy();
    Enemy* e9 = new Enemy();
    Enemy* e10 = new Enemy();
    e1->setPos(0,0);
    e2->setPos(80,0);
    e3->setPos(160,0);
    e4->setPos(240,0);
    e5->setPos(320,0);
    e6->setPos(400,0);
    e7->setPos(480,0);
    e8->setPos(560,0);
    e9->setPos(640,0);
    e10->setPos(720,0);

    //medium difficulty
    e1->setSpeed(2);
    e2->setSpeed(1);
    e3->setSpeed(1.3);
    e4->setSpeed(1.7);
    e5->setSpeed(1.6);
    e6->setSpeed(1.4);
    e7->setSpeed(0.9);
    e8->setSpeed(0.8);
    e9->setSpeed(1.2);
    e10->setSpeed(1.9);

    QList<Enemy*> enemy_list;
    enemy_list << e1 << e2 << e3 << e4 << e5 << e6 << e7 << e8 << e9 << e10;

//    QList<int> distribution;
//    distribution << 0<<80<<160<<240<<320<<400<<480<<560<<640<<720;

//    QList<int> speed;
//    distribution << 7<<6<<5<<8<<6<<9<<10<<12<<9<<7;

//    auto setup = [&enemy_list, distribution, speed](int i){
//        enemy_list[i]->setPos(distribution[i],0);
//        enemy_list[i]->setSpeed(speed[i]);
//    };

    for(int i = 0; i < enemy_list.size(); i++){
        //setup(i);
        scene->addItem(enemy_list[i]);
    }

}

void Game::mousePressEvent(QMouseEvent *event){
    if(!(t->got_hit)){
        //create the bullet
        Bullet* bullet = new Bullet();

        //set start position to be at the center of tower:
        bullet->setPos(center->x()+35, center->y()+31);

        //set the angle according to the mouse click:

        QLineF line(QPointF(t->x()+35, t->y()+31),QPointF(event->x(), event->y()));
        int theta = line.angle()+90;

        bullet->setRotation(theta);
        scene->addItem(bullet);
    }else{
        Bullet* bullet = new Bullet();

        //set start position to be at the center of tower:
        bullet->setPos(400, 400);
        scene->addItem(bullet);
    }
}

void Game::keyPressEvent(QKeyEvent *key){
    if(key->key() == Qt::Key_W){
        center->setY(center->y()-20);
        t->setPos(center->x(), center->y());
    }else if(key->key() == Qt::Key_A){
        center->setX(center->x()-20);
        t->setPos(center->x(), center->y());
    }else if(key->key() == Qt::Key_S){
        center->setY(center->y()+20);
        t->setPos(center->x(), center->y());
    }else if(key->key() == Qt::Key_D){
        center->setX(center->x()+20);
        t->setPos(center->x(), center->y());
    }
}

