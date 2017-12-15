#include "Tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>

Tower::Tower(QGraphicsItem* parent){
    setPixmap(QPixmap(":/images/tower.png"));

    //create point vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
           << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);
    const int SCALE = 200;
    for(size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE;
    }

    //set the enemy range (polygon):
    QPolygonF polygon(points);
    attack_area = new QGraphicsPolygonItem(polygon, this);

    //re-center:
    QPointF polygon_center(1.5,1.5);
    polygon_center *= SCALE;
    polygon_center = mapToScene(polygon_center);
    QPointF tower_center(x()+38, y()+38);
    QLineF line(polygon_center, tower_center);
    attack_area->setPos(x()+line.dx(), y()+line.dy());
}
