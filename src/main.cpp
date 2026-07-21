#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "core/Database.h"
#include "core/SteamScanner.h"
#include "core/GameModel.h"
#include "core/TranslationManager.h"    // ۱. اضافه کردن هدر مدیریت زبان
#include "core/SaveBackupManager.h"    // ۲. اضافه کردن هدر مدیریت بکاپ سیو

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Initialize Database
    if (!Database::initialize()) {
        qWarning() << "Failed to initialize database!";
        return -1;
    } else {
        qDebug() << "Database initialized successfully";
    }

    // Create game model
    GameModel gameModel;

    // Scan Steam games on startup
    SteamScanner::scanSteamGames();

    // Load games from database into model
    gameModel.loadGamesFromDatabase();

    // ۳. مقداردهی اولیه سیستم مدیریت زبان و بکاپ
    TranslationManager translationManager;
    SaveBackupManager saveBackupManager;

    QQmlApplicationEngine engine;

    // Expose objects to QML (۴. معرفی به محیط QML)
    engine.rootContext()->setContextProperty("gameModel", &gameModel);
    engine.rootContext()->setContextProperty("trManager", &translationManager);
    engine.rootContext()->setContextProperty("saveBackupManager", &saveBackupManager);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);

    engine.loadFromModule("NeonLauncher", "Main");

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
