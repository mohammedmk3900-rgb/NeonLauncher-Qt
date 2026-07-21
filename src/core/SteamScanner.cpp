#include "SteamScanner.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>
#include <QDebug>
#include <QRegularExpression>

QString SteamScanner::getSteamPath() {
#if defined(Q_OS_WIN)
    // مسیر پیش‌فرض استیم در ویندوز
    return "C:/Program Files (x86)/Steam";
#elif defined(Q_OS_LINUX)
    QString home = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString linuxPath = home + "/.local/share/Steam";
    if (QDir(linuxPath).exists()) return linuxPath;
    
    // مسیر جایگزین در لینوکس (Flatpak)
    QString flatpakPath = home + "/.var/app/com.valvesoftware.Steam/.local/share/Steam";
    if (QDir(flatpakPath).exists()) return flatpakPath;
#endif
    return "";
}

QVector<GameInfo> SteamScanner::scanSteamGames() {
    QVector<GameInfo> games;
    QString steamPath = getSteamPath();
    
    if (steamPath.isEmpty()) {
        qWarning() << "Steam installation path not found!";
        return games;
    }

    QString steamappsPath = steamPath + "/steamapps";
    QDir steamappsDir(steamappsPath);
    
    if (!steamappsDir.exists()) {
        qWarning() << "steamapps directory does not exist at:" << steamappsPath;
        return games;
    }

    // اسکن فایل‌های مانیفست بازی‌ها (acf)
    QStringList filters;
    filters << "appmanifest_*.acf";
    QFileInfoList manifestFiles = steamappsDir.entryInfoList(filters, QDir::Files);

    for (const QFileInfo &fileInfo : manifestFiles) {
        QVector<GameInfo> parsedGames = parseManifestFile(fileInfo.absoluteFilePath());
        games.append(parsedGames);
    }

    qDebug() << "Total Steam games found:" << games.size();
    return games;
}

QVector<GameInfo> SteamScanner::parseManifestFile(const QString &manifestPath) {
    QVector<GameInfo> games;
    QFile file(manifestPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return games;

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    // استخراج نام بازی از فایل مانیفست با عبارت منظم
    QRegularExpression nameRx("\"name\"\s+\"([^\"]+)\"");
    QRegularExpressionMatch nameMatch = nameRx.match(content);

    QRegularExpression dirRx("\"installdir\"\s+\"([^\"]+)\"");
    QRegularExpressionMatch dirMatch = dirRx.match(content);

    if (nameMatch.hasMatch() && dirMatch.hasMatch()) {
        GameInfo game;
        game.name = nameMatch.captured(1);
        game.installDir = dirMatch.captured(1);
        games.append(game);
    }

    return games;
}
