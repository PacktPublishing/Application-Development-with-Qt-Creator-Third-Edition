#ifndef IMAGEGALLERYMODEL_H
#define IMAGEGALLERYMODEL_H

#include <QStandardItemModel>

class QFileSystemWatcher;

class ImageGalleryModel : public QStandardItemModel
{
	Q_OBJECT
public:
	enum ImageGalleryRoles {
		PathRole = Qt::UserRole + 1
	};

	explicit ImageGalleryModel(QObject *parent = nullptr);

	QHash<int, QByteArray> roleNames() const;
	void setRootPath(const QString& path);
signals:

public slots:
	void onDirectoryChanged(const QString& path);

private:
	QString path;
	QFileSystemWatcher *watcher;
};

#endif // IMAGEGALLERYMODEL_H
