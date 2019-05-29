#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	cout << "Hello world!";

	return a.exec();
}
