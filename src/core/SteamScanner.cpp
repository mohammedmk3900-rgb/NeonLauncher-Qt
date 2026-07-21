#include "SteamScanner.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>

void SteamScanner::scanSteamGames()
{
    qDebug() << "Scanning Steam games...";
    QString steamPath = getSteamPath();
    if (steamPath.isEmpty()) {
        qDebug() << "Steam path not found!";
        return;
    }

    QString libraryPath = steamPath + "/steamapps";
    QDir dir(libraryPath);
    if (!dir.exists()) return;

    QStringList filters;
    filters << "appmanifest_*.acf";
    QFileInfoList list = dir.entryInfoList(filters, QDir::Files);

    for (const QFileInfo &fileInfo : list) {
        QVector<GameInfo> parsedGames = parseManifestFile(fileInfo.absoluteFilePath());
        for (const auto &game : parsedGames) {
            qDebug() << "Found Steam Game:" << game.name << "Path:" << game.exePath;
        }
    }
}

QString SteamScanner::getSteamPath()
{
#if defined(Q_OS_WIN)
    QDir steamWin("C:/Program Files (x86)/Steam");
    if (steamWin.exists()) return steamWin.absolutePath();
    
    QDir steamWin2("C:/Program Files/Steam");
    if (steamWin2.exists()) return steamWin2.absolutePath();
#elif defined(Q_OS_LINUX)
    QString home = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString linuxPath = home + "/.steam/steam";
    if (QDir(linuxPath).exists()) return linuxPath;
#endif

    return "";
}

QVector<GameInfo> SteamScanner::parseManifestFile(const QString& manifestPath)
{
    QVector<GameInfo> games;
    QFile file(manifestPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return games;

    QTextStream in(&file);
    QString name;
    QString installDirName;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.contains("\"name\"")) {
            int start = line.indexOf("\"", 6) + 1;
            int end = line.lastIndexOf("\"");
            name = line.mid(start, end - start);
        }
        if (line.contains("\"installdir\"")) {
            int start = line.indexOf("\"", 12) + 1;
            int end = line.lastIndexOf("\"");
            installDirName = line.mid(start, end - start);
        }
    }
    file.close();

    if (!name.isEmpty() && !installDirName.isEmpty()) {
        QString steamPath = getSteamPath();
        QString fullPath = steamPath + "/steamapps/common/" + installDirName;
        games.append({name, fullPath, ""});
    }

    return games;
}
