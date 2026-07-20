#include "SteamScanner.h"
#include <QDir>
#include <QDebug>
#include <QStandardPaths>
#include <QFile>
#include <QTextStream>
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

QVector<GameInfo> SteamScanner::parseManifestFile(const QString& manifestPath)
{
    QVector<GameInfo> games;
    QFile file(manifestPath);
    
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open manifest:" << manifestPath;
        return games;
    }
    
    GameInfo game;
    QTextStream in(&file);
    
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        
        if (line.contains("\"name\"")) {
            int start = line.indexOf("\"", line.indexOf("\"") + 1) + 1;
            int end = line.lastIndexOf("\"");
            game.name = line.mid(start, end - start);
        }
        else if (line.contains("\"installdir\"")) {
            int start = line.indexOf("\"", line.indexOf("\"") + 1) + 1;
            int end = line.lastIndexOf("\"");
            game.exePath = line.mid(start, end - start);
        }
    }
    
    file.close();
    
    if (!game.name.isEmpty()) {
        game.iconPath = "";  // Icon path would be determined from game directory
        games.append(game);
    }
    
    return games;
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
    qDebug() << "Found" << manifests.size() << "manifest files";

    int gamesAdded = 0;
    for (const QString& file : manifests) {
        QString fullPath = dir.filePath(file);
        qDebug() << "Parsing manifest:" << file;
        
        QVector<GameInfo> parsedGames = parseManifestFile(fullPath);
        
        for (const GameInfo& game : parsedGames) {
            Database::addGame(game.name, game.exePath, game.iconPath);
            gamesAdded++;
            qDebug() << "Added game to database:" << game.name;
        }
    }

    qDebug() << "Steam scan completed. Added" << gamesAdded << "games to database.";
}
