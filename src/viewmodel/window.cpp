#include "window.hpp"

#include <QSettings>

Window::Window()
{
	QSettings mySettings;
	mWindowWidth = mySettings.value("windowwidth", 800).toInt();
	mWindowHeight = mySettings.value("windowheight", 200).toInt();
	mGap = mySettings.value("windowgap", 100).toInt();
	mMargin = mySettings.value("windowmargin", 100).toInt();
	mPath = mySettings.value("backgroundFile").toString();
}

int Window::windowWidth() const
{
	return mWindowWidth;
}

int Window::windowHeight() const
{
	return mWindowHeight;
}

int Window::gap() const
{
	return mGap;
}

int Window::margin() const
{
	return mMargin;
}

QString Window::path() const
{
	return mPath;
}

void Window::setWindowWidth(int windowWidth)
{
	mWindowWidth = windowWidth;
	windowWidthChanged(mWindowWidth);

	QSettings mySettings;
	mySettings.setValue("windowwidth", mWindowWidth);
}

void Window::setWindowHeight(int windowHeight)
{
	mWindowHeight = windowHeight;
	windowHeightChanged(mWindowHeight);

	QSettings mySettings;
	mySettings.setValue("windowheight", mWindowHeight);
}

void Window::setGap(int gap)
{
	mGap = gap;
	gapChanged(mGap);

	QSettings mySettings;
	mySettings.setValue("windowgap", mGap);
}

void Window::setMargin(int margin)
{
	mMargin = margin;
	marginChanged(mMargin);

	QSettings mySettings;
	mySettings.setValue("windowmargin", mMargin);
}

void Window::setPath(QString path)
{
	mPath = path;
	pathChanged(mPath);

	QSettings mySettings;
	mySettings.setValue("backgroundFile", mPath);
}
