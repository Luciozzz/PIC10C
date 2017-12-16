#include "Enemy.h"
#include "Tower.h"
#include "Game.h"
#include <QPixmap>
#include <QTimer>
#include <QtMath>

Enemy::Enemy(QGraphicsItem *parent){
    setPixmap(QPixmap(":/images/enemy1.png"));

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move_forward()));
    timer->start(150);
}

void Enemy::setSpeed(int s){
    speed = s;
}

void Enemy::move_forward(){
    const int STEP_SIZE = speed;
    double angle = rotation();
    double dx = STEP_SIZE * qSin(qDegreesToRadians(angle));
    double dy = STEP_SIZE * qCos(qDegreesToRadians(angle));

    setPos(x()+dx, y()+dy);
}
