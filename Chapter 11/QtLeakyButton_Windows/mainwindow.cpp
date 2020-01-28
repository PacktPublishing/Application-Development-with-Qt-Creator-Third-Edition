#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->leakButton, &QPushButton::clicked, this, &MainWindow::leakPressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::leakPressed()
{
	void *p = new char[512 * 1024];
    m_count++;
    ui->leakCount->setText(QString::number(m_count));
}

