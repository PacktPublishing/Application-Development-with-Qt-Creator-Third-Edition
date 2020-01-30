#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QImage>
#include <QPainter>
#include <QBitmap>

#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QPen pen(Qt::black, 2, Qt::SolidLine);
	QBrush whiteBrush(Qt::white, Qt::SolidPattern);
	QBrush blackBrush(Qt::black, Qt::SolidPattern);
	QRect faceOutline(0, 0, 100, 100);
	painter.setPen(pen);
	painter.setBrush(whiteBrush);
	painter.drawEllipse(faceOutline);
	QRect mouth(30, 60, 40, 20);
	painter.drawArc(mouth, 180*16, 180*16);
	QRect eye(25, 25, 10, 10);
	painter.setBrush(blackBrush);
	painter.drawEllipse(eye);
	eye = QRect(65, 25, 10, 10);
	painter.drawEllipse(eye);
	QPoint nosePoints[3] = {
		QPoint(50, 45),
		QPoint(40, 50),
		QPoint(50, 50) };
	painter.drawPolyline(nosePoints, 3);
}

MainWindow::~MainWindow()
{
	delete ui;
}
