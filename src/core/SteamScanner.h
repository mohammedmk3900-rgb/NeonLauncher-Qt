#ifndef STEAMSCANNER_H
#define STEAMSCANNER_H

#include <QString>

class SteamScanner
{
public:
    static void scanSteamGames();
    static QString getSteamPath();
};

#endif // STEAMSCANNER_H
