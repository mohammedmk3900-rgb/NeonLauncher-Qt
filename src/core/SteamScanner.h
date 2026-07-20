#ifndef STEAMSCANNER_H
#define STEAMSCANNER_H

#include <QString>
#include <QVector>
#include <QThread>
#include <QObject>

struct GameInfo {
    QString name;
    QString exePath;
    QString iconPath;
};

class SteamScannerWorker : public QObject
{
    Q_OBJECT

public:
    explicit SteamScannerWorker(QObject *parent = nullptr);

public slots:
    void scanGames();

signals:
    void gameFound(const GameInfo &game);
    void scanFinished(int totalGames);
    void scanProgress(int current, int total);
    void errorOccurred(const QString &error);

private:
    QString getSteamPath() const;
    QVector<GameInfo> parseManifestFile(const QString& manifestPath);
    void loadGameIcons(const GameInfo &game);
    
    int m_totalManifests = 0;
};

class SteamScanner : public QObject
{
    Q_OBJECT

public:
    explicit SteamScanner(QObject *parent = nullptr);
    ~SteamScanner();

    void startScanAsync();
    void stopScan();
    bool isScanning() const;

signals:
    void gameFound(const GameInfo &game);
    void scanFinished(int totalGames);
    void scanProgress(int current, int total);
    void errorOccurred(const QString &error);

private:
    QThread *m_scanThread = nullptr;
    SteamScannerWorker *m_worker = nullptr;
};

#endif // STEAMSCANNER_H
