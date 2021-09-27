#include "data.hpp"

#include <QSettings>

Data::Data(PlayerSpectator& ps)
	: mps(ps)
{
	QSettings mySettings;
	mPath = mySettings.value("dataFile").toString();

	mps.usePath(mPath);
}

QString Data::path() const
{
	return mPath;
}

void Data::setPath(QString path)
{
	mPath = path;
	pathChanged(mPath);

	mps.usePath(mPath);

	QSettings mySettings;
	mySettings.setValue("dataFile", mPath);
}

void Data::addPlayer(QString proName, QString summonerName)
{
	mps.addPlayer(proName, summonerName);
}
