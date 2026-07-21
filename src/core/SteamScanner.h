#ifndef STEAMSCANNER_H
#define STEAMSCANNER_H

#include <QString>
#include <QVector>
#include <QObject>

struct GameInfo {
    QString name;
    QString exePath;
    QString iconPath;
};

class SteamScanner : public QObject
{
    Q_OBJECT

public:
    explicit SteamScanner(QObject *parent = nullptr);

    // تابع استاتیک برای اسکن راحت
    static void scanSteamGames();

private:
    static QString getSteamPath();
    static QVector<GameInfo> parseManifestFile(const QString& manifestPath);
};

#endif // STEAMSCANNER_H
