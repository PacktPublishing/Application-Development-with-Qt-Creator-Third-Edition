#ifndef MOBILEUNIT_H
#define MOBILEUNIT_H

#include <QtCore>
#include <QGraphicsRectItem>
#include <QRadialGradient>

class MobileUnit : public QGraphicsRectItem
{
public:
    MobileUnit();
    inline int getLifePoints() { return lifePoints; }
    inline bool getIsFinished() const { return isFinished; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    void touched (int hurtPoints);
private:
    int lifePoints;
    qreal alpha;
    qreal dirX;
    qreal dirY;
    qreal speed;
    bool isFinished;
    bool isExploding;
    int explosionDuration;
    QRadialGradient redExplosion;
    QTime time;
    QImage spacecraftImage;
};

#endif // MOBILEUNIT_H
