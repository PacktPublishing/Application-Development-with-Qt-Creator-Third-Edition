#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// Comment out the following code to display default language
	QTranslator translator;
	translator.load(":/Linguist.qml");
	a.installTranslator(&translator);

	MainWindow w;
	w.show();

	return a.exec();
}
