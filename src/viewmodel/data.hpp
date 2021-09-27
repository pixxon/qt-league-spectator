#pragma once

#include <QQuickItem>
#include <QString>

#include "model/playerspectator.hpp"

struct Data
	: QQuickItem
{
	Q_OBJECT
	Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
	QML_ELEMENT

public:
	Data(PlayerSpectator& ps);

	[[nodiscard]] QString path() const;

public slots:
	void setPath(QString path);
	void addPlayer(QString proName, QString summonerName);

signals:
	void pathChanged(QString path);

private:
	QString mPath;

	PlayerSpectator& mps;
};
