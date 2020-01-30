#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>
#include <QTimer>

#include <QAccelerometer>
#include <QAmbientLightSensor>
#include <QProximitySensor>

#include <QAccelerometerReading>
#include <QAmbientLightReading>
#include <QProximityReading>

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
	const QUrl url(QStringLiteral("qrc:/main.qml"));
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
					 &app, [url](QObject *obj, const QUrl &objUrl) {
		if (!obj && url == objUrl)
			QCoreApplication::exit(-1);
	}, Qt::QueuedConnection);
	engine.load(url);

	// Sensors and Readings
	QAccelerometer *accSensor = new QAccelerometer;
	accSensor->start();
	QSensorReading *accReading = accSensor->reading();

	QAmbientLightSensor *ambSensor = new QAmbientLightSensor;
	ambSensor->start();
	QAmbientLightReading * ambReading = ambSensor->reading();

	QProximitySensor *proxSensor = new QProximitySensor;
	proxSensor->start();
	QProximityReading *proxReading = proxSensor->reading();

	// Timer
	QTimer* timer = new QTimer;
	QObject::connect(timer, &QTimer::timeout, [=] {
		qreal x = accReading->property("x").value<qreal>();
		qreal y = accReading->value(1).value<qreal>();
		qDebug() << "Accelerometer:" << x << y;

		qDebug() << "Ambient Light:" << ambReading->lightLevel();
		qDebug() << "Proximity:" << proxReading->close();
	});
	timer->start(1000);

	return app.exec();
}
