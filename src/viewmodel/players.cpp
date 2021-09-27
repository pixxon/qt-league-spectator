#include "players.hpp"

Players::Players(PlayerSpectator& ps)
	: mps(ps)
{
	QObject::connect(&mps, &PlayerSpectator::playersChanged, this, &Players::onPlayersChanged);
}

QStringList Players::blueTeam()
{
	return mBlueTeam;
}

QStringList Players::redTeam()
{
	return mRedTeam;
}

void Players::onPlayersChanged()
{
	mRedTeam.clear();
	for(const auto& p : mps.redPlayers())
	{
		mRedTeam.append(p.proName + " (" + p.championName + ")");
	}
	redTeamChanged();

	mBlueTeam.clear();
	for(const auto& p : mps.bluePlayers())
	{
		mBlueTeam.append(p.proName + " (" + p.championName + ")");
	}
	blueTeamChanged();
}
