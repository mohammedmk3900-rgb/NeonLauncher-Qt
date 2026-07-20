#ifndef STEAMSCANNER_H
#define STEAMSCANNER_H

#include <QString>
#include <QVector>

struct GameInfo {
    QString name;
    QString exePath;
    QString iconPath;
};

class SteamScanner
{
public:
    static void scanSteamGames();
    static QString getSteamPath();
    static QVector<GameInfo> parseManifestFile(const QString& manifestPath);
};

#endif // STEAMSCANNER_H
