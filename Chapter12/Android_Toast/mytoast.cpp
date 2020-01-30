#include "mytoast.h"

MyToast::MyToast(QObject *parent) : QObject(parent) {}

void MyToast::callToast(QString message)
{
	#ifdef Q_OS_ANDROID
	QtAndroid::runOnAndroidThread([=]
	{
		QAndroidJniObject::callStaticMethod<void>("org/qtproject/example/MyToast",
		"notify", "(Landroid/content/Context;Ljava/lang/String;)V",
		QtAndroid::androidActivity().object(),
		QAndroidJniObject::fromString(message).object<jstring>());
	});
	#endif
}
