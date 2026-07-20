#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QAbstractListModel>
#include <QStringList>

struct GameEntry {
    QString name;
    QString exePath;
    QString iconPath;
};

class GameModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit GameModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void addGame(const QString &name, const QString &exePath, const QString &iconPath);
    void loadGamesFromDatabase();
    void clearGames();

private:
    enum GameRoles {
        NameRole = Qt::UserRole + 1,
        ExePathRole,
        IconPathRole
    };

    QVector<GameEntry> m_games;
};

#endif // GAMEMODEL_H
