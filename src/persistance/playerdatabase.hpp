#pragma once

#include <QString>
#include <QMap>

#include "persistance/player.hpp"

struct PlayerDatabase
{
	PlayerDatabase();
	PlayerDatabase(QString path);
	~PlayerDatabase();

	QMap<QString, QString> playerMapping;
	QString mPath;
};
