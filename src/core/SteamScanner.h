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
    // تابع استاتیک برای اسکن بازی‌ها
    static void scanSteamGames();

private:
    static QString getSteamPath();
    static QVector<GameInfo> parseManifestFile(const QString& manifestPath);
};

#endif // STEAMSCANNER_H
