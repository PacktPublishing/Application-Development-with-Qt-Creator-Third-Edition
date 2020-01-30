#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsView>
#include "scene.h"
#include "simpletower.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Scene scene;
    scene.setSceneRect(0,0,640,360);
    QGraphicsView view(&scene);
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &scene, &Scene::advance);
    view.show();
    timer.start(10);
    return app.exec();
}
