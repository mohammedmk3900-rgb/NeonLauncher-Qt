#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "core/Database.h"
#include "core/SteamScanner.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Initialize Database
    if (!Database::initialize()) {
        qWarning() << "Failed to initialize database!";
    } else {
        qDebug() << "Database initialized successfully";
    }

    // Scan Steam games on startup
    SteamScanner::scanSteamGames();

    QQmlApplicationEngine engine;

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);

    engine.loadFromModule("NeonLauncher", "Main");

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
