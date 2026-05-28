#include <QDir>
#include <QDebug>

void scanSteamGames()
{
    QString steamPath =
        "C:/Program Files (x86)/Steam/steamapps";

    QDir dir(steamPath);

    QStringList manifests =
        dir.entryList(QStringList() << "*.acf");

    for (const QString& file : manifests)
    {
        qDebug() << file;
    }
}