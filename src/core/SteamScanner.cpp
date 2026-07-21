#include "SteamScanner.h"
#include <QDebug>
#include <QDir>
#include <QFile>

void SteamScanner::scanSteamGames()
{
    qDebug() << "Scanning Steam games...";
}

QString SteamScanner::getSteamPath()
{
    return "";
}

QVector<GameInfo> SteamScanner::parseManifestFile(const QString& manifestPath)
{
    QVector<GameInfo> games;
    return games;
}
