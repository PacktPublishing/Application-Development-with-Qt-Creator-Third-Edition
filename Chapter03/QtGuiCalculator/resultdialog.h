#ifndef RESULTDIALOG_H
#define RESULTDIALOG_H

#include <QDialog>

namespace Ui {
	class Dialog;
}

class ResultDialog : public QDialog
{
	Q_OBJECT
public:
	ResultDialog(QWidget *parent = nullptr);
	~ResultDialog();
	void setResult(float r);

private:
	Ui::Dialog *ui;
};

#endif // RESULTDIALOG_H
