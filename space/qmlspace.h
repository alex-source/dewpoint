#ifndef QMLSPACE_H
#define QMLSPACE_H

#include <QObject>
#include <QQmlApplicationEngine>

class QmlSpace : public QQmlApplicationEngine
{
    Q_OBJECT
public:
    explicit QmlSpace(QObject *parent = nullptr);

signals:
    void toQml(QString idName, QString value);

public slots:

};

#endif // QMLSPACE_H
