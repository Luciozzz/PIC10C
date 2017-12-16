#include "Tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>

Tower::Tower(QGraphicsItem* parent){
    setPixmap(QPixmap(":/images/tower.png"));

    //create point vector
    QVector<QPointF> points;
    points << QPointF(1,0) << QPointF(3,0) << QPointF(4,1.732)
           << QPointF(3,3.464) << QPointF(1,3.464) << QPointF(0,1.732);
    const int SCALE = 13;
    for(size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE;
    }

    //set the hit range (polygon):
    QPolygonF polygon(points);
    hit_area = new QGraphicsPolygonItem(polygon, this);

    //re-center:
    QPointF polygon_center(2.2,2.2);
    polygon_center *= SCALE;
    polygon_center = mapToScene(polygon_center);
    QPointF tower_center(x()+38, y()+38);
    QLineF line(polygon_center, tower_center);
    hit_area->setPos(x()+line.dx(), y()+line.dy());
}

void Tower::rotate(const QPointF& mouse){
    return;
}
