#ifndef CHART_H
#define CHART_H

#include <QObject>

class Chart : public QObject
{
    Q_OBJECT
public:
    explicit Chart(QObject *parent = nullptr);
    Q_INVOKABLE void ttt();

signals:
    void appendPoint(QString idName, double value );

public slots:
};

#endif // CHART_H
