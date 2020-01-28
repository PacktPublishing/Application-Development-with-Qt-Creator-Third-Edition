#include "fileimageprovider.h"

FileImageProvider::FileImageProvider(QQuickImageProvider::ImageType type) :
  QQuickImageProvider(type)
{
}

QImage FileImageProvider::requestImage(const QString& filename, QSize* size, const QSize& requestedSize)
{
	QImage image(filename);
	QImage result;
	if (requestedSize.isValid()) {
		result = image.scaled(requestedSize, Qt::KeepAspectRatio);
	} else {
		result = image;
	}
	*size = result.size();
	return result;
}

QPixmap FileImageProvider::requestPixmap(const QString& filename, QSize* size, const QSize& requestedSize)
{
	QPixmap image(filename);
	QPixmap result;

	if (requestedSize.isValid()) {
		result = image.scaled(requestedSize, Qt::KeepAspectRatio);
	} else {
		result = image;
	}
	*size = result.size();
	return result;
}
