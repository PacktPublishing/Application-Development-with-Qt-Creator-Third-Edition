#include "mobileunit.h"
#include <QPainter>
#include <QGraphicsScene>
#include <math.h>

MobileUnit::MobileUnit(): QGraphicsRectItem()
, lifePoints(10)
, alpha(0)
, dirX(1.0)
, dirY(0.0)
, speed(1.0)
, isFinished(false)
, isExploding(false)
, explosionDuration(500)
, redExplosion(0.0, 0.0, 20.0, 0.0, 0.0)
, time(0, 0)
, spacecraftImage(QImage(":/spacecraft00.png") )
{
    alpha = static_cast<qreal>(qrand() % 90 + 60);
    qreal speed = static_cast<qreal>(qrand()% 10 - 5);
    dirY = cos(alpha / 180.0 * M_PI );
    dirX = sin(alpha / 180.0 * M_PI);
    alpha = -alpha * 180.0 ;
    speed = 1.0 + speed * 0.1;
    setRect(-10.0, -10.0, 20.0, 20.0);
    time.start();

    redExplosion.setColorAt(0.0, Qt::white);
    redExplosion.setColorAt(0.2, QColor(255, 255, 100, 255));
    redExplosion.setColorAt(0.4, QColor(255, 80, 0, 200));
    redExplosion.setColorAt(1.0, QColor(255, 255, 255, 0));
}

void MobileUnit::paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setPen(Qt::NoPen);

    if (!isExploding)
    {
        painter->rotate(alpha);
        painter->drawImage(-15, -14, spacecraftImage);
    }
    else
    {
        painter->setBrush(QBrush(redExplosion));
        qreal explosionRadius = 8.0 + time.elapsed() / 50;
        painter->drawEllipse(-explosionRadius, -explosionRadius, 2.0 * explosionRadius, 2.0 * explosionRadius);
    }
}

void MobileUnit::advance(int phase)
{
    if (phase==0)
    {
        qreal xx = x(); qreal yy = y();
        if ( (xx < 0.0) || (xx > scene()->width() ) )
        {   // rebond
            dirX = -dirX;
            alpha = -alpha;
        }
        if ( (yy < 0.0) || (yy > scene()->height()))
        {   // rebond
            dirY = -dirY;
            alpha = 180 - alpha;
        }
        if (isExploding)
        {
            speed *= 0.98; // decrease speed
            if (time.elapsed() > explosionDuration)
                isFinished = true; // is dead
        }
        setPos(x() + dirX * speed, y() + dirY * speed);
    }
}

void MobileUnit::touched (int hurtPoints)
{
    lifePoints -= hurtPoints; // decrease life
    if (lifePoints < 0)
        lifePoints = 0;
    if (lifePoints == 0)
    {
        time.start();
        isExploding = true;
    }
}
