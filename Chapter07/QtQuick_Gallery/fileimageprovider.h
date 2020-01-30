#ifndef FILEIMAGEPROVIDER_H
#define FILEIMAGEPROVIDER_H

#include <QQuickImageProvider>

class FileImageProvider : public QQuickImageProvider
{
public:
	FileImageProvider(QQuickImageProvider::ImageType type);
	QImage requestImage(const QString& id, QSize* size, const QSize& requestedSize);
	QPixmap requestPixmap(const QString& id, QSize* size, const QSize& requestedSize);
};

#endif // FILEIMAGEPROVIDER_H
