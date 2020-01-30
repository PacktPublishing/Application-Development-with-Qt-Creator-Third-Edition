#include <QCoreApplication>

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	/*
	QString jsonString = "{\"firstName\": \"John\",\"lastName\": \"Smith\",\"age\": 42,\"address\": {\"streetAddress\": \"14 2nd Street\",\"city\": \"New York\",\"state\": \"NY\",\"postalCode\": \"10021-3100\"},\"phoneNumbers\": [{\"type\": \"home\",\"number\": \"212 686-7890\"},{\"type\": \"mobile\",\"number\": \"321 456-7788\"}]}";

	QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
	QJsonObject obj = doc.object(); // Get the json object
	QVariantMap map = obj.toVariantMap(); // Convert json object to variant map

	qDebug() << map["firstName"].toString(); // Obtain firstName data
	*/

	QString jsonString = "{\"name\":\"John\",\"age\":30,\"cars\":[ \"Ford\", \"BMW\", \"Fiat\" ]}";

	QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
	QJsonObject obj = doc.object(); // Get the json object
	QJsonValue value = obj.value("cars"); // Get cars data in QJsonValue format
	QJsonArray array = value.toArray(); // Convert it to QJsonArray

	for (int i = 0; i < array.size(); i++)
	{
		qDebug() << array.at(i).toString(); // Get data
	}

	return a.exec();
}
