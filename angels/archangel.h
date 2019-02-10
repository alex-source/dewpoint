#ifndef ARCHANGEL_H
#define ARCHANGEL_H

#include <QObject>

class ArchAngel : public QObject
{
    Q_OBJECT
public:
    static ArchAngel& getInstance()
    {
        static ArchAngel s;
        return s;
    }
protected:
    ArchAngel(){}
    ~ArchAngel(){}
private:

    ArchAngel(ArchAngel const&) = delete;
    ArchAngel& operator = (ArchAngel const&) = delete;
signals:
    void main(bool b);

};

#endif // ARCHANGEL_H
