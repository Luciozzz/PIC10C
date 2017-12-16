#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>

class Tower: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(QGraphicsItem* parent = 0);
    bool got_hit = false;
public slots:
    void rotate(const QPointF&);
    void check_if_hit();
private:
    QGraphicsPolygonItem* hit_area;
};

#endif // TOWER_H
