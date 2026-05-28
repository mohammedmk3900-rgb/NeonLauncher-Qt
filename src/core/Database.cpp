#include "Database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

bool Database::initialize()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("launcher.db");

    if (!db.open())
    {
        qDebug() << "Database failed";
        return false;
    }

    QSqlQuery query;

    query.exec(
        "CREATE TABLE IF NOT EXISTS games ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT,"
        "exePath TEXT,"
        "iconPath TEXT"
        ")"
    );

    return true;
}
