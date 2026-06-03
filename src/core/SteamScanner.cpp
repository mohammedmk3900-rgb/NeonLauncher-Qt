#include "SteamScanner.h"
#include <QDir>
#include <QDebug>
#include "Database.h"

void SteamScanner::scanSteamGames()
{
    QString steamPath = "C:/Program Files (x86)/Steam/steamapps";

    QDir dir(steamPath);
    if (!dir.exists()) {
        qDebug() << "Steam folder not found!";
        return;
    }

    QStringList manifests = dir.entryList(QStringList() << "*.acf", QDir::Files);

    for (const QString& file : manifests) {
        qDebug() << "Found manifest:" << file;
        // بعداً اینجا parsing کامل acf فایل اضافه می‌کنیم
    }

    qDebug() << "Steam scan completed. Found" << manifests.size() << "games.";
}
