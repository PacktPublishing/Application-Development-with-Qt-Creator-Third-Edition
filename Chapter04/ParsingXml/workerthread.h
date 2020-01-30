#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QMap>
#include <QThread>
#include <QXmlStreamReader>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class WorkerThread : public QThread
{
    Q_OBJECT

public:
    WorkerThread(QObject* owner);
    void run();

    void fetch(const QString& url);
    void cancel();

signals:
    void error(const QString& error);
    void finished(const QMap<QString, QString>&);

private slots:
    void handleNetFinished(QNetworkReply* reply);

private:
	bool mCancelled = false;
    QNetworkAccessManager* mNetManager;
    QNetworkReply* mReply;
};

#endif // WORKERTHREAD_H
