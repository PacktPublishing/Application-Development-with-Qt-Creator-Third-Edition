#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QPainter>

class AnalogClock : public QWidget
{
    Q_OBJECT
public:
    explicit AnalogClock(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:

public slots:

    void update();
};

#endif // ANALOGCLOCK_H
