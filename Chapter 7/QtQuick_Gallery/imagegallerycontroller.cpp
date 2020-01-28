#include <QDir>
#include <QDesktopServices>
#include <QStandardPaths>

#include "imagegallerycontroller.h"
#include "imagegallerymodel.h"

ImageGalleryController::ImageGalleryController(QObject *parent) :
	QObject(parent)
{
	imageGalleryModel = new ImageGalleryModel();
}

ImageGalleryModel *ImageGalleryController::model() const
{
	return imageGalleryModel;
}

void ImageGalleryController::deferredInit()
{
	imageGalleryModel->setRootPath(QStandardPaths::standardLocations(QStandardPaths::PicturesLocation)[0]);
}
