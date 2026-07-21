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

#endif // STEAMSCANNER_H    if (steamWin.exists()) return steamWin.absolutePath();
    
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
