#include "mainwindow.h"

#include <QApplication>
#include "analogclock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    AnalogClock* clock = new AnalogClock(&w);

    w.show();
    return a.exec();
}
