#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene();

public slots:
    void advance();

private:
    int ticTacTime;
};
#endif // SCENE_H
