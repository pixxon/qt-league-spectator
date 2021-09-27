#pragma once

#include <QQuickItem>

struct Window
	: QQuickItem
{
	Q_OBJECT
	Q_PROPERTY(int windowWidth READ windowWidth WRITE setWindowWidth NOTIFY windowWidthChanged)
	Q_PROPERTY(int windowHeight READ windowHeight WRITE setWindowHeight NOTIFY windowHeightChanged)
	Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
	Q_PROPERTY(int gap READ gap WRITE setGap NOTIFY gapChanged)
	Q_PROPERTY(int margin READ margin WRITE setMargin NOTIFY marginChanged)
	QML_ELEMENT

public:
	Window();

	[[nodiscard]] int windowWidth() const;
	[[nodiscard]] int windowHeight() const;
	[[nodiscard]] int gap() const;
	[[nodiscard]] int margin() const;
	[[nodiscard]] QString path() const;


public slots:
	void setWindowWidth(int windowWidth);
	void setWindowHeight(int windowHeight);
	void setGap(int gap);
	void setMargin(int margin);
	void setPath(QString path);

signals:
	void windowWidthChanged(int windowWidth);
	void windowHeightChanged(int windowHeight);
	void gapChanged(int gap);
	void marginChanged(int margin);
	void pathChanged(QString path);

private:
	int mWindowHeight;
	int mWindowWidth;
	int mGap;
	int mMargin;
	QString mPath;
};
