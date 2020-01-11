#ifndef BROADCAST_H
#define BROADCAST_H

#include <QObject>
#include "archangel.h"

class Broadcast : public ArchAngel
{
    Q_OBJECT
public:
    static Broadcast& getInstance()
    {
        static Broadcast s;
        return s;
    }

private:
    Broadcast(){}
    ~Broadcast(){}

    Broadcast(Broadcast const&) = delete;
    Broadcast& operator = (Broadcast const&) = delete;
signals:
    void arduino(QString value);

public slots:
};

#endif // BROADCAST_H
