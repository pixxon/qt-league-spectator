#pragma once

#include <QObject>
#include <QVector>
#include <QTimer>
#include <QNetworkAccessManager>

#include "persistance/player.hpp"
#include "persistance/playerdatabase.hpp"

struct PlayerSpectator
	: QObject
{
	Q_OBJECT

public:
	PlayerSpectator(QObject* parent = nullptr);
	~PlayerSpectator();

	[[nodiscard]] QVector<Player> redPlayers() const;
	[[nodiscard]] QVector<Player> bluePlayers() const;

	void usePath(QString path);
	void addPlayer(QString proName, QString summonerName);

signals:
	void playersChanged();

private:
	QVector<Player> mRedPlayers;
	QVector<Player> mBluePlayers;

	PlayerDatabase db;

	QTimer mTimer;
	QNetworkAccessManager mNetwork;
};
