#ifndef SINGLETONCONNECT_H
#define SINGLETONCONNECT_H

#include <QObject>
#include <QDebug>
#include <QString>

class SingletonConnect : public QObject
{
    Q_OBJECT
public:
    //explicit SingletonConnect(QObject *parent = nullptr);

    static SingletonConnect& getInstance()
    {
        static SingletonConnect s;
        return s;
    }

private:
    SingletonConnect() {  }
    ~SingletonConnect() {  }

    SingletonConnect(SingletonConnect const&) = delete;
    SingletonConnect& operator= (SingletonConnect const&) = delete;
signals:
    void sig11(QString idName, QString value);
public slots:
};

#endif // SINGLETONCONNECT_H
