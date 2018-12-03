#include "mysql.h"
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QDir>
#include <QDateTime>

MySql::MySql() : QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE")){
    QSqlDatabase db;
    baseInitString();
    baseToWork();
    getTable();

}

void MySql::appendValue(QString name,double val)
{
    QString qs,t,n,c,v;
    c = ",";
    t = QString::number(QDateTime::currentDateTime().toTime_t());
    n = "'"+name+"'";
    v = QString::number(val);
    qs.append(t+c+n+c+v);


      QSqlQuery q;
      qs ="INSERT INTO telemetry (time, name, value) "
        "VALUES ("+qs+")";

      q.exec(qs);
      qDebug()<<qs<<q.lastError();
}

void MySql::getTable()
{
    QList<QList<QString>> t;//is table
    QList<QString> r;//is row
    QString qs;
    qs = "SELECT * FROM telemetry";
    QSqlQuery q;
    q.exec(qs);
    while (q.next()) {
       r.append(q.value(0).toString());
       r.append(q.value(1).toString());
       r.append(q.value(2).toString());
       t.append(r);
       r.clear();
    }
//    qDebug()<<q.lastError();

}

 void MySql::getColumn(QString columnName, QList<double> &listResult)
{
    QString qs;
    qs = "SELECT "+columnName+" FROM telemetry";
    QSqlQuery q;
    q.exec(qs);
    while (q.next()) {
       listResult.append(q.value(0).toDouble());
    }

}

void MySql::baseToWork()
{
    this->setDatabaseName(bInit.patchToBase);
    this->setUserName(bInit.user);
    this->setPassword(bInit.password);
    dbIsOpen = this->open();
    qDebug()<<this->lastError()<<dbIsOpen<<this->tables();
}

void MySql::baseInitString()
{
        bInit.patchToBase ="..//..//db//lite//dewpoint.sqlite";
        bInit.user = "user";
        bInit.password = "root";
}
