#include "imagegallerymodel.h"
#include <QDir>
#include <QFile>
#include <QFileSystemWatcher>

ImageGalleryModel::ImageGalleryModel(QObject *parent) :
	QStandardItemModel(parent)
{
	watcher = new QFileSystemWatcher(this);
	connect(watcher, SIGNAL(directoryChanged(QString)),
		this, SLOT(onDirectoryChanged(QString)));
}

QHash<int, QByteArray> ImageGalleryModel::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[PathRole] = "path";
	return roles;
}

void ImageGalleryModel::setRootPath(const QString &p)
{
	this->clear();

	if (path != "") {
		watcher->removePath(path);
	}

	path = p;
	watcher->addPath(path);

	// Sync the model
	onDirectoryChanged(path);
}

void ImageGalleryModel::onDirectoryChanged(
	const QString &path)
{
	QStringList nameFilters;
	nameFilters << "*.png" << "*.jpg";
	QDir directory(path);
	directory.setNameFilters(nameFilters);
	QStringList files = directory.entryList();

	QHash<QString, int> fileIndexes;

	// Sync the model with the list.

	// Now delete anything in the model not on the filesystem
	for(int i = 0; i < rowCount(); i++)
	{
		QString absolutePath = data(index(i, 0), PathRole).toString();
		QString name = directory.relativeFilePath(absolutePath);
		if (!files.contains(name)) {
			removeRow(i);
			i--;
			continue;
		}
		fileIndexes[absolutePath] = i;
	}

	// Add anything to the model that's on disk
	// and not in the model
	foreach(const QString &file, files)
	{
		QString absolutePath = directory.absoluteFilePath(file);
		if (!fileIndexes.contains(absolutePath)) {
			QStandardItem *item = new QStandardItem();
			item->setData(absolutePath, PathRole);
			appendRow(item);
		}
	}
}
