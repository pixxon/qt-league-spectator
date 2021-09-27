#pragma once

#include <QQuickItem>
#include <QStringList>

#include "model/playerspectator.hpp"

struct Players
	: QQuickItem
{
	Q_OBJECT
	Q_PROPERTY(QStringList blueTeam READ blueTeam NOTIFY blueTeamChanged)
	Q_PROPERTY(QStringList redTeam READ redTeam NOTIFY redTeamChanged)
	QML_ELEMENT

public:
	Players(PlayerSpectator& ps);

	[[nodiscard]] QStringList blueTeam();
	[[nodiscard]] QStringList redTeam();

signals:
	void blueTeamChanged();
	void redTeamChanged();

private slots:
	void onPlayersChanged();

private:
	QStringList mBlueTeam;
	QStringList mRedTeam;

	PlayerSpectator& mps;
};
