#include <QApplication>
#include <QQmlApplicationEngine>

#include "persistance/playerdatabase.hpp"
#include "model/playerspectator.hpp"
#include "viewmodel/data.hpp"
#include "viewmodel/players.hpp"
#include "viewmodel/window.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("pixxont");
    QCoreApplication::setApplicationName("qt-league-spectator");

    QApplication app(argc, argv);

    PlayerSpectator ps;

    Window w;
    Players p( ps );
    Data d( ps );

    QQmlApplicationEngine display;
    display.setInitialProperties({
        { "windowModel", QVariant::fromValue(&w) },
        { "currentPlayers", QVariant::fromValue(&p) }
    });
    display.load(QUrl("qrc:///view/display.qml"));

    QQmlApplicationEngine controller;
    controller.setInitialProperties({
        { "windowModel", QVariant::fromValue(&w) },
        { "dataModel", QVariant::fromValue(&d) }
    });
    controller.load(QUrl("qrc:///view/controller.qml"));

    return app.exec();
}