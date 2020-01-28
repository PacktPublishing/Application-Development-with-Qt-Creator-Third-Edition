#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>
#include <QQmlContext>

#include "imagegallerycontroller.h"
#include "imagegallerymodel.h"
#include "fileimageprovider.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	ImageGalleryController *controller = new ImageGalleryController(&engine);
	ImageGalleryModel *model = controller->model();

	QQmlContext *context = engine.rootContext();
	context->setContextProperty("controller", controller);
	context->setContextProperty("model", model);

	engine.addImageProvider(QLatin1String("file"),
	new FileImageProvider(QQuickImageProvider::Pixmap));

	const QUrl url(QStringLiteral("qrc:/main.qml"));
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
					 &app, [url](QObject *obj, const QUrl &objUrl) {
		if (!obj && url == objUrl)
			QCoreApplication::exit(-1);
	}, Qt::QueuedConnection);
	engine.load(url);

	return app.exec();
}
