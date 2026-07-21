#include "SteamScanner.h"
#include <QDebug>
#include <QDir>
#include <QFile>

void SteamScanner::scanSteamGames()
{
    // کدهای پیاده‌سازی اسکنر استیم شما
    qDebug() << "Scanning Steam games...";
}

QString SteamScanner::getSteamPath()
{
    // پیاده‌سازی مسیر استیم
    return "";
}

QVector<GameInfo> SteamScanner::parseManifestFile(const QString& manifestPath)
{
    QVector<GameInfo> games;
    // پیاده‌سازی پارس کردن فایل مانیفست
    return games;
}
                     Qt::QueuedConnection);

    engine.loadFromModule("NeonLauncher", "Main");

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
