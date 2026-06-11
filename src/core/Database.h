#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QStringList>

class Database
{
public:
    static bool initialize();
    static void addGame(const QString& name, const QString& exePath, const QString& iconPath);
    static QStringList getAllGames();
};

#endif // DATABASE_H
