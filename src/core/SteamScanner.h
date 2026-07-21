#pragma once

#include <QString>
#include <QVector>

struct GameInfo {
    QString name;
    QString installDir;
    QString executablePath;
};

class SteamScanner {
public:
    static QVector<GameInfo> scanSteamGames();
    static QString getSteamPath();

private:
    static QVector<GameInfo> parseManifestFile(const QString &manifestPath);
};
