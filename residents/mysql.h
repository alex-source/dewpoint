#ifndef MYSQL_H
#define MYSQL_H

#include <QtSql/QSqlDatabase>
class MySql : public QSqlDatabase
{
public:
    void appendValue(QString name,double val);
    void getTable();
    void getColumn(QString columnName, QList<double> &listResult);

private:
    MySql();
    void baseInitString();
    void baseToWork();
    struct baseInitString{
            QString patchToBase;
            QString user;
            QString password;
    } baseInitStruct;
    bool dbIsOpen = false;
};

#endif // MYSQL_H
