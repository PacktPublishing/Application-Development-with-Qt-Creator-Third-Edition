#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>
#include <QtWebEngineWidgets>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QWebEngineView *view = new QWebEngineView();
	view->load(QUrl("http://www.zhieng.com"));
	ui->verticalLayout->addWidget(view);
}

MainWindow::~MainWindow()
{
	delete ui;
}
