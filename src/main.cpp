#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "core/Database.h"
#include "core/SteamScanner.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Initialize Database
    if (!Database::initialize()) {
        qWarning() << "Failed to initialize database!";
    }

    // Scan Steam games on startup (اختیاری)
    SteamScanner::scanSteamGames();

    QQmlApplicationEngine engine;

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);

    engine.loadFromModule("NeonLauncher", "Main");

    return app.exec();
}
