#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resultdialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	results(nullptr)
{

	ui->setupUi(this);
	QObject::connect(ui->aboutButton, &QPushButton::clicked,
					 this, &MainWindow::aboutButtonClicked);
	QObject::connect(this, &MainWindow::computed,
					 this, &MainWindow::showResult);
	QObject::connect(ui->plusButton, &QPushButton::clicked,
					 this, &MainWindow::plusButtonClicked);
	QObject::connect(ui->minusButton, &QPushButton::clicked,
					 this, &MainWindow::minusButtonClicked);
	QObject::connect(ui->timesButton, &QPushButton::clicked,
					 this, &MainWindow::timesButtonClicked);
	QObject::connect(ui->divideButton, &QPushButton::clicked,
					 this, &MainWindow::divideButtonClicked);
}

MainWindow::~MainWindow()
{
	delete ui;
}

MainWindow::Arguments MainWindow::arguments()
{
	bool ok1, ok2;
	float a1 = ui->argument1Input->text().toFloat(&ok1);
	float a2 = ui->argument2Input->text().toFloat(&ok2);
	if (!ok1 || !ok2)
	{
		QMessageBox messageBox;
		messageBox.setIconPixmap(QPixmap(":/icon.png"));
		messageBox.setText("One of your entries is not a valid number.");
		messageBox.setWindowTitle("Error");
		messageBox.exec();
	}
	return Arguments(a1, a2);
}

void MainWindow::aboutButtonClicked()
{
	QMessageBox messageBox;
	messageBox.setIconPixmap(QPixmap(":/icon.png"));
	messageBox.setText("Lorem ipsum.");
	messageBox.setWindowTitle("About");
	messageBox.exec();
}

void MainWindow::plusButtonClicked()
{
	Arguments a = arguments();
	emit computed(a.first + a.second);
}

void MainWindow::minusButtonClicked()
{
	Arguments a = arguments();
	emit computed(a.first - a.second);
}

void MainWindow::timesButtonClicked()
{
	Arguments a = arguments();
	emit computed(a.first * a.second);
}

void MainWindow::divideButtonClicked()
{
	Arguments a = arguments();
	emit computed(a.first / a.second);
}

void MainWindow::showResult(float r)
{
	if (!results)
	{
		results = new ResultDialog();
	}
	results->setResult(r);
	results->exec();
}

