#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QStandardItemModel* model = new QStandardItemModel(this);
	model->setColumnCount(5);
	model->setRowCount(10);
	for (int row = 0; row < model->rowCount(); row++)
	{
		for (int column = 0; column < model->columnCount(); column++)
		{
			QStandardItem *item = new QStandardItem(QString("row %0, column %1").arg(row + 1).arg(column + 1));
			model->setItem(row, column, item);
		}
	}
	ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
	QMessageBox::information(this, "Data", index.data(Qt::DisplayRole).toString());
}
