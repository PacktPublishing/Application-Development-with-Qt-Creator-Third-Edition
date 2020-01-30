#ifndef IMAGEGALLERYCONTROLLER_H
#define IMAGEGALLERYCONTROLLER_H

#include <QObject>

class ImageGalleryModel;
class QAbstractItemModel;

class ImageGalleryController : public QObject
{
	Q_OBJECT

public:
	explicit ImageGalleryController(QObject *parent = 0);
	ImageGalleryModel* model() const;

signals:

public slots:
	void deferredInit();

private:
	ImageGalleryModel *imageGalleryModel;

};

#endif // IMAGEGALLERYCONTROLLER_H
