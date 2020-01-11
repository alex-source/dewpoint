#ifndef QMLSPACE_H
#define QMLSPACE_H

#include <QObject>
#include <QQmlApplicationEngine>

class QmlSpace : public QQmlApplicationEngine
{
    Q_OBJECT
public:
    explicit QmlSpace(QObject *parent = nullptr);
private:

signals:
    void toQml(QString value);

public slots:

};

#endif // QMLSPACE_H
