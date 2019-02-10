#ifndef MONITOR_H
#define MONITOR_H

#include <QObject>
#include "archangel.h"

class Monitor : public ArchAngel
{
    Q_OBJECT
public:
    static Monitor& getInstance()
    {
        static Monitor s;
        return s;
    }

private:
    Monitor(){}
    ~Monitor(){}

    Monitor(Monitor const&) = delete;
    Monitor& operator = (Monitor const&) = delete;
signals:


public slots:
};

#endif // MONITOR_H
