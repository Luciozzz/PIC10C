#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>

class Tower: public QGraphicsPixmapItem{
public:
    Tower(QGraphicsItem* parent = 0);
public slots:
    void rotate(const QPointF&);
private:
    QGraphicsPolygonItem* hit_area;
};

#endif // TOWER_H
