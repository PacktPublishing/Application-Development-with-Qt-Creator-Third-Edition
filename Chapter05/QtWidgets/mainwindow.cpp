#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	//QPushButton* button = new QPushButton("Some default text", ui->centralWidget);
	//button->setText("Click me!");

	//QLabel* label = new QLabel("This is some text", ui->centralWidget);

	//QLineEdit* lineEdit = new QLineEdit(ui->centralWidget);

	QComboBox* cbox = new QComboBox(ui->centralWidget);
	cbox->addItem("Option 1");
	cbox->addItem("Option 2");
	cbox->addItem("Option 3");
}

MainWindow::~MainWindow()
{
	delete ui;
}
