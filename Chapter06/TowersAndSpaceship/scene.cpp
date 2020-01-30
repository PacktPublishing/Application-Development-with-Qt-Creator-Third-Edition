#include "scene.h"
#include "mobileunit.h"
#include "simpletower.h"
#include <QDebug>

Scene::Scene(): QGraphicsScene(), ticTacTime(0)
{
    SimpleTower * simpleTower = new SimpleTower();
    simpleTower->setPos(200.0, 100.0);
    addItem(simpleTower);

    simpleTower = new SimpleTower();
    simpleTower->setPos(200.0, 180.0);
    addItem(simpleTower);

    simpleTower = new SimpleTower();
    simpleTower->setPos(200.0, 260.0);
    addItem(simpleTower);

    simpleTower = new SimpleTower();
    simpleTower->setPos(250.0, 050.0);
    addItem(simpleTower);

    simpleTower = new SimpleTower();
    simpleTower->setPos(250.0, 310.0);
    addItem(simpleTower);

    simpleTower = new SimpleTower();
    simpleTower->setPos(300.0, 110.0);
    addItem(simpleTower);

    simpleTower = new SimpleTower();
    simpleTower->setPos(300.0, 250.0);
    addItem(simpleTower);

    simpleTower = new SimpleTower();
    simpleTower->setPos(350.0, 180.0);
    addItem(simpleTower);
}

void Scene::advance()
{
    ticTacTime++;

    // delete killed objects
    QGraphicsItem* item = nullptr;
    MobileUnit* unit = nullptr;
    int i = 0;

    while (i < items().count())
    {
        item = items().at(i);
        unit = dynamic_cast<MobileUnit*>(item);
        if ((unit != nullptr) && (unit->getIsFinished() == true))
        {
            removeItem(item);
            delete unit;
        }
        else
            ++i;
    }

    // Add new units every 20 tictacs
    if (ticTacTime % 20 == 0)
    {
        // qDebug() << "add unit";
        MobileUnit* mobileUnit= new MobileUnit();
        qreal h = static_cast<qreal>(qrand() % static_cast<int>(height()));
        mobileUnit->setPos(width(), h);
        addItem(mobileUnit);
    }

    QGraphicsScene::advance();
    update();
}
