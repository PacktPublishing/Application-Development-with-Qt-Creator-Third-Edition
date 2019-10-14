#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPair>

namespace Ui {
	class MainWindow;
}

class ResultDialog;

class MainWindow : public QMainWindow
{
	Q_OBJECT

	typedef QPair<float, float> Arguments;
public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	Arguments arguments();

signals:
	void computed(float f);

private slots:
	void aboutButtonClicked();
	void plusButtonClicked();
	void minusButtonClicked();
	void timesButtonClicked();
	void divideButtonClicked();

	void showResult(float r);

private:
	Ui::MainWindow *ui;
	ResultDialog* results;
};

#endif // MAINWINDOW_H
