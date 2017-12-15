#include "Bullet.h"
#include <QPixmap>
#include <QTimer>
#include "qmath.h"

Bullet::Bullet(QGraphicsItem *parent){
    setPixmap(QPixmap(":/images/bullet.png"));

    //timer
    QTimer* move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(50);
}

void Bullet::move(){
    const int STEP_SIZE = 30;
    double angle = rotation();
    double dx = STEP_SIZE * qSin(qDegreesToRadians(angle));
    double dy = STEP_SIZE * qCos(qDegreesToRadians(angle));

    setPos(x()+dx, y()+dy);
}
