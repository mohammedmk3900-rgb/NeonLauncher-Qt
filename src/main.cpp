#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "core/Database.h"
#include "core/SteamScanner.h"
#include "core/GameModel.h"

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

    QQmlApplicationEngine engine;

    // Expose gameModel to QML
    engine.rootContext()->setContextProperty("gameModel", &gameModel);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);

    engine.loadFromModule("NeonLauncher", "Main");

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
