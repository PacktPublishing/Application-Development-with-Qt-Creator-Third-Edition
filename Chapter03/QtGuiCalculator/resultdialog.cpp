#include "resultdialog.h"
#include "ui_resultdialog.h"

ResultDialog::ResultDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);
}

ResultDialog::~ResultDialog()
{
	delete ui;
}

void ResultDialog::setResult(float r)
{
	ui->result->setText(QString::number(r));
}
