#ifndef MYTOAST_H
#define MYTOAST_H

#include <QObject>

#ifdef Q_OS_ANDROID
	#include <QtAndroidExtras>
	#include <QAndroidJniObject>
#endif

class MyToast : public QObject
{
	Q_OBJECT
public:
	explicit MyToast(QObject *parent = nullptr);
	Q_INVOKABLE void callToast(QString message);
};

#endif // MYTOAST_H
