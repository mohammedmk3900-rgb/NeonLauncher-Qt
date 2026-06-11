#include "SteamScanner.h"
#include <QDir>
#include <QDebug>
#include <QStandardPaths>
#include "Database.h"

QString SteamScanner::getSteamPath()
{
    #ifdef Q_OS_WIN
        return "C:/Program Files (x86)/Steam/steamapps";
    #elif defined(Q_OS_MAC)
        return QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/Library/Application Support/Steam/steamapps";
    #else // Linux
        return QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/.steam/steamapps";
    #endif
}

void SteamScanner::scanSteamGames()
{
    QString steamPath = getSteamPath();

    QDir dir(steamPath);
    if (!dir.exists()) {
        qDebug() << "Steam folder not found at:" << steamPath;
        return;
    }

    QStringList manifests = dir.entryList(QStringList() << "*.acf", QDir::Files);

    for (const QString& file : manifests) {
        qDebug() << "Found manifest:" << file;
        // TODO: اینجا parsing کامل acf فایل اضافه می‌کنیم
        // Database::addGame(gameName, gamePath, iconPath);
    }

    qDebug() << "Steam scan completed. Found" << manifests.size() << "games.";
}
