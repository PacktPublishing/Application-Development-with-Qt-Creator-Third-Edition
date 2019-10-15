#include <QCoreApplication>

#include "workerthread.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

    WorkerThread* thread = new WorkerThread(&a);
    thread->fetch(""); // Your XML file here

	return a.exec();
}
