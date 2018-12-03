#ifndef MYSQL_H
#define MYSQL_H

#include <QtSql/QSqlDatabase>
class MySql : public QSqlDatabase
{
public:
    MySql();

    void appendValue(QString name,double val);
    void getTable();
    void getColumn(QString columnName, QList<double> &listResult);


private:
    void baseInitString();
    void baseToWork();
    struct baseInitString{
            QString patchToBase;
            QString user;
            QString password;
    } bInit;
    bool dbIsOpen = false;
};

#endif // MYSQL_H
