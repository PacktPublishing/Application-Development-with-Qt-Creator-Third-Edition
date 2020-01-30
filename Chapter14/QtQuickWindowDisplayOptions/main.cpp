#include <QGuiApplication>
#include <QtQuick/QQuickView>

int main(int argc, char *argv[])
{
	QGuiApplication a(argc, argv);

	QQuickView view;
	view.setOpacity(0.75);
	view.setFlags(Qt::Popup | Qt::WindowStaysOnTopHint);
	view.setSource(QUrl("qrc:/qml/main.qml"));
	view.show();

	return a.exec();
}
