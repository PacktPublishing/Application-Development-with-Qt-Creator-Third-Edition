#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QMessageBox::information(this, "Qt Linguist", message());
}

MainWindow::~MainWindow()
{
	delete ui;
}

QString MainWindow::message()
{
	return tr("What is your name?");
}
