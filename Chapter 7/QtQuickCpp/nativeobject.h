#ifndef NATIVEOBJECT_H
#define NATIVEOBJECT_H

#include <QObject>

class NativeObject : public QObject
{
    Q_OBJECT
public:
    explicit NativeObject(QObject *parent = nullptr) :
    QObject(parent)
    {
        m_text = "Hello world!";
    }

    Q_PROPERTY(QString text READ text)
    const QString& text() { return m_text; }

private:
    QString m_text;

};

#endif // NATIVEOBJECT_H
