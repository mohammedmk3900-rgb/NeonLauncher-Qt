#include "GameModel.h"
#include "Database.h"
#include <QDebug>

GameModel::GameModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int GameModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_games.size();
}

QVariant GameModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_games.size())
        return QVariant();

    const GameEntry &game = m_games.at(index.row());

    switch (role) {
    case NameRole:
        return game.name;
    case ExePathRole:
        return game.exePath;
    case IconPathRole:
        return game.iconPath;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> GameModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[ExePathRole] = "exePath";
    roles[IconPathRole] = "icon";
    return roles;
}

void GameModel::addGame(const QString &name, const QString &exePath, const QString &iconPath)
{
    beginInsertRows(QModelIndex(), m_games.size(), m_games.size());
    GameEntry entry;
    entry.name = name;
    entry.exePath = exePath;
    entry.iconPath = iconPath;
    m_games.append(entry);
    endInsertRows();
}

void GameModel::loadGamesFromDatabase()
{
    clearGames();
    QStringList games = Database::getAllGames();
    for (const QString &gameName : games) {
        addGame(gameName, "", "");
    }
}

void GameModel::clearGames()
{
    if (!m_games.isEmpty()) {
        beginRemoveRows(QModelIndex(), 0, m_games.size() - 1);
        m_games.clear();
        endRemoveRows();
    }
}
