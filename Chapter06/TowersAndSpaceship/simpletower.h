#ifndef SIMPLETOWER_H
#define SIMPLETOWER_H

#include <QtCore>
#include <QGraphicsRectItem>

class MobileUnit;

class SimpleTower : public QGraphicsRectItem
{
public:
    SimpleTower();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget* widget);
    void advance(int phase);
private:
    void searchTarget();
    void shoot();
private:
    qreal detectionDistance;
    QTime time;
    int reloadTime;
    bool shootIsActive;
    MobileUnit* target;
    QImage towerImage;
};
#endif // SIMPLETOWER_H
