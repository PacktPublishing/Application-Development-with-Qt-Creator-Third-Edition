#include <QCoreApplication>
#include <QDebug>
#include "mathfunctions.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	int values[] = { 6, 7, 8 };
	for(unsigned int i = 0; i < sizeof(values)/sizeof(int); i++)
	{
		qDebug() << values[i]
				 << "! = "
				 << MathFunctions::factorial(values[i]);
	}

	return a.exec();
}
