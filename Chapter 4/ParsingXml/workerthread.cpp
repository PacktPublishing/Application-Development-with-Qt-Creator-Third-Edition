#include "workerthread.h"

WorkerThread::WorkerThread(QObject* owner)
{
    this->setParent(owner);
    mNetManager = new QNetworkAccessManager(this);
    connect(mNetManager, &QNetworkAccessManager::finished, this, &WorkerThread::handleNetFinished);
}

void WorkerThread::run()
{
    QXmlStreamReader xml;
    QXmlStreamReader::TokenType type;
    QString fieldName;
    QString value;
    QString tag;
    bool successful = false;
    bool gotValue = false;
    QMap<QString, QString> result;

	xml.setDevice(mReply);

	while(!xml.atEnd())
    {
        // If we've been cancelled, stop processing.
		if (mCancelled) break;

        type = xml.readNext();
		bool gotEntry = false;

		switch(type)
        {
            case QXmlStreamReader::StartElement:
            {
                QString tag = xml.name().toString().toLower();
                fieldName = tag;
                gotValue = false;
                qDebug() << "tag" << tag;
				break;
            }
            case QXmlStreamReader::Characters:
			{
				// Save aside any text
				if (!gotValue)
				{
					value = xml.text().toString().simplified();
					if (value != "")
					{
						gotValue = true;
						qDebug() << "value" << value;
					}
				}
				break;
			}
            case QXmlStreamReader::EndElement:
			{
				// Save aside this value
				if (gotEntry && gotValue)
				{
					result[fieldName] = value;
				}
				gotEntry = false;
				gotValue = false;
				break;
			}
            default:
            break;
		}
	}
    successful = xml.hasError() ? false : true;

    if (!mCancelled && successful)
    {
        emit finished(result);
    }
    else if (!mCancelled)
    {
        emit error(tr("Could not interpret the server's response."));
    }
}

void WorkerThread::fetch(const QString& url)
{
    // Don't try to re-start if we're running
    if (isRunning()) { this->cancel(); }

    QNetworkReply *reply = mNetManager->get(QNetworkRequest(QUrl(url)));

    if (!reply) { emit error(tr("Could not contact the server.")); }
}

void WorkerThread::cancel()
{
    mCancelled = true;
    wait();
};

void WorkerThread::handleNetFinished(QNetworkReply* reply)
{
    // Start parse by starting the thread.
	if (reply->error() == QNetworkReply::NoError)
    {
        if (!this->isRunning())
        {
              mReply = reply;
              start();
        }
    }
    else
    {
        emit error(tr("A network error occurred."));
        qDebug() << QString("net error %1").arg(reply->error());
	}
}
