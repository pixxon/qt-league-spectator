#include "persistance/playerdatabase.hpp"

#include <QFile>
#include <QByteArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

PlayerDatabase::PlayerDatabase()
{
}

PlayerDatabase::PlayerDatabase(QString path)
{
	QFile inFile(QUrl(path).toLocalFile());
	if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return;
	}

	QByteArray data = inFile.readAll();
	inFile.close();

	QJsonParseError errorPtr;
	QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
	if (doc.isNull()) {
		qDebug() << "Parse failed";
	}
	QJsonArray ptsArray = doc.array();
	qDebug() << "There are " << ptsArray.size() << "sets of points in the json file";
	for(const QJsonValue& val : ptsArray) {
		QString proName = val.toObject().value("proName").toString();
		QString summonerName = val.toObject().value("summonerName").toString();
		playerMapping.insert(summonerName, proName);
	}

	mPath = path;
}

PlayerDatabase::~PlayerDatabase()
{
	QFile inFile(QUrl(mPath).toLocalFile());
	if (!inFile.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		return;
	}

	QJsonArray ptsArray;
	for(auto it = playerMapping.begin(); it != playerMapping.end(); ++it)
	{
		QJsonObject obj;
		obj.insert("summonerName", it.key());
		obj.insert("proName", it.value());
		ptsArray.append(obj);
	}

	QJsonDocument doc(ptsArray);

	inFile.write(doc.toJson());
	inFile.close();
}
