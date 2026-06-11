#include "Database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool Database::initialize()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("launcher.db");

    if (!db.open())
    {
        qDebug() << "Database failed:" << db.lastError().text();
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

void Database::addGame(const QString& name, const QString& exePath, const QString& iconPath)
{
    QSqlQuery query;
    query.prepare("INSERT INTO games (name, exePath, iconPath) VALUES (?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(exePath);
    query.addBindValue(iconPath);
    
    if (!query.exec()) {
        qDebug() << "Failed to insert game:" << query.lastError().text();
    }
}

QStringList Database::getAllGames()
{
    QStringList games;
    QSqlQuery query("SELECT name FROM games");
    
    while (query.next()) {
        games << query.value(0).toString();
    }
    
    return games;
}
