#include "playerspectator.hpp"

#include <QNetworkReply>
#include <QByteArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

PlayerSpectator::PlayerSpectator(QObject* parent)
	: QObject(parent)
{
	mTimer.setSingleShot(true);

	QObject::connect(&mTimer, &QTimer::timeout, [this](){
		auto* reply = mNetwork.get(QNetworkRequest{QUrl{"https://127.0.0.1:2999/liveclientdata/allgamedata"}});
		QObject::connect(reply, &QNetworkReply::sslErrors, [reply](){ reply->ignoreSslErrors(); });
		QObject::connect(reply, &QNetworkReply::finished, [reply, this](){
			const auto data = reply->readAll();
			QJsonParseError errorPtr;
			QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
			if (doc.isNull()) {
				qDebug() << "Parse failed";
			}
			QJsonObject content = doc.object();
			QJsonArray allPlayers = content.value("allPlayers").toArray();

			mRedPlayers.clear();
			mBluePlayers.clear();

			for(const QJsonValue& player : allPlayers) {
				QString summonerName = player.toObject().value("summonerName").toString();
				QString championName = player.toObject().value("championName").toString();
				QString team = player.toObject().value("team").toString();

				auto it = db.playerMapping.find(summonerName);
				if (it != db.playerMapping.end())
				{
					auto& players = (team == "ORDER" ? mBluePlayers : mRedPlayers);
					players.append(Player{it.value(), championName});
				}
			}

			playersChanged();

			mTimer.start(1000);
		});
	});
	
	mTimer.start(1000);
}

PlayerSpectator::~PlayerSpectator()
{
	mTimer.stop();
}

QVector<Player> PlayerSpectator::redPlayers() const
{
	return mRedPlayers;
}

QVector<Player> PlayerSpectator::bluePlayers() const
{
	return mBluePlayers;
}

void PlayerSpectator::usePath(QString path)
{
	db = PlayerDatabase(path);
}

void PlayerSpectator::addPlayer(QString proName, QString summonerName)
{
	db.playerMapping.insert(summonerName, proName);
}
