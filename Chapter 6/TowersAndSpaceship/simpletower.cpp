#include <QPainter>
#include <QGraphicsScene>
#include "simpletower.h"
#include "mobileunit.h"

SimpleTower::SimpleTower(): QGraphicsRectItem()
, detectionDistance(100.0)
, time(0, 0)
, reloadTime(100)
, shootIsActive(false)
, target(nullptr)
, towerImage(QImage(":/lightTower.png"))
{
    setRect(-15.0, -15.0, 30.0, 30.0);
    time.start();
}

void SimpleTower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget* widget)
{
    painter->drawImage(-15, -15, towerImage);
    if ((target != nullptr) && (shootIsActive))
    {   // laser beam
        QPointF towerPoint = mapFromScene(pos());
        QPointF theTarget = mapFromScene(target->pos());
        painter->setPen(QPen(Qt::yellow,8.0,Qt::SolidLine));
        painter->drawLine(towerPoint.x(), towerPoint.y(), theTarget.x(), theTarget.y());
        painter->setPen(QPen(Qt::red,5.0,Qt::SolidLine));
        painter->drawLine(towerPoint.x(), towerPoint.y(), theTarget.x(), theTarget.y());
        painter->setPen(QPen(Qt::white,2.0,Qt::SolidLine));
        painter->drawLine(towerPoint.x(), towerPoint.y(), theTarget.x(), theTarget.y());
        shootIsActive = false;
    }
}

void SimpleTower::advance(int phase)
{
    if (phase == 0)
    {
        searchTarget();
        if ((target != nullptr) && (time.elapsed() > reloadTime))
            shoot();
    }
}

void SimpleTower::searchTarget()
{
    target = nullptr;
    QList<QGraphicsItem*> itemList = scene()->items();
    int i = itemList.count() - 1;
    qreal dx, dy, sqrDist;
    qreal sqrDetectionDist = detectionDistance * detectionDistance;
    MobileUnit* unit = nullptr;
    while((i >= 0) && (nullptr == target) )
    {
        QGraphicsItem * item = itemList.at(i);
        unit = dynamic_cast<MobileUnit*>(item);
        if ((unit != nullptr) && (unit->getLifePoints() > 0))
        {
            dx = unit->x() - x();
            dy = unit->y() - y();
            sqrDist = dx * dx + dy * dy;
            if (sqrDist < sqrDetectionDist)
                target=unit;
        }
        --i;
    }
}

void SimpleTower::shoot()
{
    shootIsActive=true;
    target->touched(3);
    time.restart();
}
